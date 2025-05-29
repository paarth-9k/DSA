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
        // Because at this point, head itself is nullptr, so trying to do head->next = nullptr would result in a segmentation fault (crash).
    }

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        // newnode points to head and finally new head is node
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
    }

    void insertAtPosition(int value, int position)
    {
        if (position == 0)
        {
            insertAtBeginning(value);
            return;
        }
        // Check if List is Empty
        if (!head)
        {
            cout << "Position out of range\n";
            return;
        }
        Node *newNode = new Node(value);
        Node *temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        // Check if Reached Valid Position
        if (!temp)
        {
            cout << "Position out of range\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        // temp is pointing to Person A

        // temp->next is Person B

        // newNode is the new person you're inserting

        // 🔁 Line-by-line in Plain English:
        // 1️⃣ newNode->next = temp->next;
        // 👉 You tell the new person (newNode):
        // “Hey, hold the hand of whoever Person A was holding (Person B).”

        // 2️⃣ temp->next = newNode;
        // 👉 Then you tell Person A (temp):
        // “Now you stop holding Person B's hand. Instead, hold the hand of the new person.”
    }
};
