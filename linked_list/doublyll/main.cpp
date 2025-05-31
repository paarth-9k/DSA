#include <iostream>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{

private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        // newNode -> prev = nullptr; already done in constructor
        head->prev = newNode;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteAtBeginning()
    {
        if (!head)
        {
            cout << "List is empty\n";
            return;
        }
        Node *toDelete = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        delete toDelete;
    }

    void deleteAtEnd()
    {
        if (!head)
        {
            cout << "List is empty\n";
            return;
        }
        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }
};

int main()
{
}