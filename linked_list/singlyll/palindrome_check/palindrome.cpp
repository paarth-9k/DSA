//  Definition for singly-linked list.
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
    ListNode *reverse(struct ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *next = nullptr;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

    bool isPalindrome(ListNode *head)
    {
        ListNode *s = head, *f = head;
        while (f->next != nullptr && f->next->next != nullptr)
        {
            s = s->next;
            f = f->next->next;
        }
        ListNode *newHead = reverse(s->next);
        ListNode *first = head, *second = newHead;
        while (second)
        {
            if (first->val != second->val)
            {
                reverse(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverse(newHead);
        return true;
    }
};