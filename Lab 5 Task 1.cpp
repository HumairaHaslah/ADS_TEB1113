#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* next;
    
    Node(string n) {
        name = n; 
        next = NULL;
    }
};

class Stack {
public:
    Node* top; 
    Stack() {
        top = NULL;
    }

    void push(string name) {
        Node* newNode = new Node(name);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "This stack is empty";
        }
        Node* temp = top;
        top = top->next;
        cout << endl;
        cout << temp->name << " is popped" << endl;
        delete temp;
    }

    void display() {
        Node* current = top;
        if(current == NULL) {
            cout << "The stack is empty" << endl;
            return;
        }
        while (current != NULL) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
   Stack s;

   s.push("Aimar");
   s.push("Ahmad");
   s.push("Anjana");

   cout << "Display from top to bottom:" << endl;
   s.display();

   s.pop();
   cout << "\nAfter pop:" << endl;
   s.display();
}
