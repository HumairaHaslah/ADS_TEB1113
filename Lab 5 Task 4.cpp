#include <iostream>
#include <string>

using namespace std;

class Queue {
public:
    string arr[100];
    int front;
    int rear;

    Queue() {
        front = 0;
        rear = 0;
    }

    void enqueue(string name) {
        if (rear == 100) {
            cout << "The queue is full." << endl;
            return;
        }
        if (front == 0) {
            front = 1;
        }
        rear++;
        arr[rear] = name;
    }

    void dequeue() {
        if (front == 0) {
            cout << "This queue is empty";
            return;
        }
        cout << endl;
        cout << arr[front] << " is dequeued." << endl;
        front++;

        if(front > rear) {
            front = rear = -1; 
        }
    }

    void display() {
        if (front == 0) {
            cout << "This queue is empty";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << endl;
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
