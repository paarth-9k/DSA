#include <iostream>
using namespace std;

class Node
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

    // Insert at the beginning
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        if (head != nullptr)
        {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    // Insert at the end
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

    // Delete at the beginning
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

    // Delete at the end
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

    // Delete by value (first occurrence)
    void deleteByValue(int value)
    {
        if (!head)
        {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head;
        while (temp && temp->data != value)
        {
            temp = temp->next;
        }
        if (!temp)
        {
            cout << "Value not found\n";
            return;
        }
        if (temp == head)
        {
            deleteAtBeginning();
            return;
        }
        if (!temp->next)
        {
            deleteAtEnd();
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    // Display forward
    void displayForward()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Display backward
    void displayBackward()
    {
        if (!head)
        {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;

        while (temp)
        {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }

    // Destructor to free memory
    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main()
{
    DoublyLinkedList dll;

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(5);
    dll.insertAtEnd(30);

    cout << "Forward: ";
    dll.displayForward();

    cout << "Backward: ";
    dll.displayBackward();

    dll.deleteByValue(20);
    cout << "After deleting 20:\n";
    dll.displayForward();

    dll.deleteAtBeginning();
    dll.deleteAtEnd();
    cout << "After deleting at beginning and end:\n";
    dll.displayForward();

    return 0;
}

// Forward: 5 <-> 10 <-> 20 <-> 30 <-> NULL
// Backward: 30 <-> 20 <-> 10 <-> 5 <-> NULL
// After deleting 20:
// 5 <-> 10 <-> 30 <-> NULL
// After deleting at beginning and end:
// 10 <-> NULL
