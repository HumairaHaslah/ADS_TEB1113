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
            return;
        }

        Node* current = head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
    }

    void insertAfter(string afterName, string newName)
    {
        Node* current = head;

        while (current != NULL && current->name != afterName)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << afterName << " not found." << endl;
            return;
        }

        Node* newNode = new Node(newName);

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL)
        {
            current->next->prev = newNode;
        }

        current->next = newNode;
    }

    void deleteByName(string name)
    {
        if (head == NULL)
        {
            return;
        }

        if (head->name == name)
        {
            Node* temp = head;
            head = head->next;

            if (head != NULL)
            {
                head->prev = NULL;
            }

            delete temp;
            return;
        }

        Node* current = head;

        while (current->next != NULL)
        {
            if (current->next->name == name)
            {
                Node* temp = current->next;

                current->next = temp->next;

                if (temp->next != NULL)
                {
                    temp->next->prev = current;
                }

                delete temp;
                return;
            }

            current = current->next;
        }
    }

    void display()
    {
        Node* current = head;

        while (current != NULL)
        {
            cout << current->name << endl;
            current = current->next;
        }
    }

    void displayReverse()
    {
        if (head == NULL)
        {
            return;
        }

        Node* current = head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        while (current != NULL)
        {
            cout << current->name << endl;
            current = current->prev;
        }
    }
};

int main()
{
    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

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
