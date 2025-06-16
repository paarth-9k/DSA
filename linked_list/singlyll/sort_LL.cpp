
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *findMiddleNode(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast =
            head->next; // head->next because we want slow to point to the first
                        // element/middle in the even length case

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // merge linked list function
    ListNode *merge(ListNode *list1Head, ListNode *list2Head)
    {
        ListNode *dummyNode = new ListNode(-1); // can be any value
        ListNode *temp = dummyNode;

        while (list1Head != nullptr && list2Head != nullptr)
        {
            if (list1Head->val <= list2Head->val)
            {
                temp->next = list1Head;
                temp = list1Head;
                list1Head = list1Head->next;
            }
            else
            {
                temp->next = list2Head;
                temp = list2Head;
                list2Head = list2Head->next;
            }
        }

        // if list1 still has elements left
        while (list1Head != nullptr)
        {
            temp->next = list1Head;
            temp = list1Head;
            list1Head = list1Head->next;
        }

        // if list2 still has elements left
        while (list2Head != nullptr)
        {
            temp->next = list2Head;
            temp = list2Head;
            list2Head = list2Head->next;
        }
        return dummyNode->next;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *mid = findMiddleNode(head);
        ListNode *leftHead = head;
        ListNode *rightHead = mid->next;
        mid->next = nullptr; // Disconnect the left and right halves

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return merge(leftHead, rightHead);
    }
};