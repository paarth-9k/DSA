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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *f = head;
        if (f == nullptr)
            return nullptr;
        ListNode *s = head;
        ListNode *prev = nullptr;
        while (f != nullptr && f->next != nullptr)
        {
            f = f->next->next;
            prev = s;
            s = s->next;
        }
        prev->next = s->next;
        return head;
    }
};