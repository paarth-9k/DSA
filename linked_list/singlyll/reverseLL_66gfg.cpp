// Reverse a linked list
// Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
};

class Solution
{
public:
    Node *reverseList(struct Node *head)
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;
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
};