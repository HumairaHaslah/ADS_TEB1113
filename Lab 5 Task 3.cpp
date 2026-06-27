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

class Queue {
public:
    Node* front; 
    Node* rear;

    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(string name) {
        Node* newNode = new Node(name);
        if (rear == NULL) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "This queue is empty";
            return;
        }
        Node* temp = front;
        front = front->next;
        cout << endl;
        cout << temp->name << " is popped" << endl;
        delete temp;
        
        if(front == NULL) {
            rear = NULL; 
        } 
    }

    void display() {
        Node* current = front;
        if(current == NULL) {
            cout << "The queue is empty" << endl;
            return;
        }
        while (current != NULL) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
   Queue q;

   q.enqueue("Aimar");
   q.enqueue("Ahmad");
   q.enqueue("Anjana");

   cout << "Display from front to rear (left to right):" << endl;
   q.display();

   q.dequeue();
   cout << "\nAfter dequeue the front:" << endl;
   q.display();
}
