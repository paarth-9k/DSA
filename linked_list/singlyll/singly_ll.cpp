#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
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
            temp = temp->next;
        temp->next = newNode;
    }

    // Insert at a given position (0-based index)
    void insertAtPosition(int value, int position)
    {
        if (position == 0)
        {
            insertAtBeginning(value);
            return;
        }
        Node *newNode = new Node(value);
        Node *temp = head;
        for (int i = 0; i < position - 1 && temp; i++)
        {
            temp = temp->next;
        }
        if (!temp)
        {
            cout << "Position out of range\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete node by position (0-based)
    void deleteByPosition(int position)
    {
        if (!head)
            return;
        if (position == 0)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node *temp = head;
        for (int i = 0; i < position - 1 && temp->next; i++)
        {
            temp = temp->next;
        }
        if (!temp->next)
        {
            cout << "Position out of range\n";
            return;
        }
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Delete node by value (first occurrence)
    void deleteByValue(int value)
    {
        if (!head)
            return;
        if (head->data == value)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->data != value)
        {
            temp = temp->next;
        }
        if (!temp->next)
        {
            cout << "Value not found\n";
            return;
        }
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Display the list
    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Search for a value
    bool search(int key)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Reverse the list
    void reverse()
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
    }

    // Destructor to clean up memory
    ~LinkedList()
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

// Example usage
int main()
{
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtPosition(15, 2);

    cout << "List: ";
    list.display();

    list.deleteByValue(20);
    cout << "After deleting 20: ";
    list.display();

    list.deleteByPosition(1);
    cout << "After deleting at position 1: ";
    list.display();

    cout << "Search 10: " << (list.search(10) ? "Found" : "Not Found") << endl;

    list.reverse();
    cout << "Reversed list: ";
    list.display();

    return 0;
}
