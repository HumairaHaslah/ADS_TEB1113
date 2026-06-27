#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    Node* next;
    Node* prev;

    Node(string n)
    {
        name = n;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList
{
public:
    Node* head;

    LinkedList()
    {
        head = NULL;
    }

    void insertEnd(string name)
    {
        Node* newNode = new Node(name);

        if (head == NULL)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        Node* tail = head->prev;

        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    void insertAfter(string afterName, string newName)
    {
        if (head == NULL)
            return;

        Node* current = head;

        do
        {
            if (current->name == afterName)
            {
                Node* newNode = new Node(newName);

                newNode->next = current->next;
                newNode->prev = current;

                current->next->prev = newNode;
                current->next = newNode;

                return;
            }

            current = current->next;

        } while (current != head);

        cout << afterName << " not found." << endl;
    }

    void deleteByName(string name)
    {
        if (head == NULL)
            return;

        Node* current = head;

        do
        {
            if (current->name == name)
            {
                if (current == head && head->next == head)
                {
                    delete head;
                    head = NULL;
                    return;
                }

                current->prev->next = current->next;
                current->next->prev = current->prev;

                if (current == head)
                {
                    head = current->next;
                }

                delete current;
                return;
            }

            current = current->next;

        } while (current != head);
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = head;

        do
        {
            cout << current->name << endl;
            current = current->next;
        }
        while (current != head);
    }

    void displayReverse()
    {
        if (head == NULL)
        {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = head->prev;

        do
        {
            cout << current->name << endl;
            current = current->prev;
        }
        while (current != head->prev);
    }
};

int main()
{
    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << endl;
    cout << "Initial list:" << endl;
    list.display();

    cout << endl;
    cout << "After inserting Ali after Anjana:" << endl;
    list.insertAfter("Anjana", "Ali");
    list.display();

    cout << endl;
    cout << "After inserting Jane at the end:" << endl;
    list.insertEnd("Jane");
    list.display();

    cout << endl;
    cout << "After deleting Jessy:" << endl;
    list.deleteByName("Jessy");
    list.display();

    cout << endl;
    cout << "Reverse linked list:" << endl;
    list.displayReverse();

    cout << endl;
    cout << "Final list (in order):" << endl;
    list.display();

    return 0;
}
