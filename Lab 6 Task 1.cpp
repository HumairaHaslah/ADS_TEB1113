#include <iostream>
#include <string>
using namespace std;

class Tree {
public:
    int value;
    Tree* left  = NULL;
    Tree* right = NULL;

    //constructor
    Tree(int v) {
    value = v;   
    }

    void insert(int v) { 
        if (v < value) {
            if (left == NULL) left = new Tree(v);  
            else left->insert(v);
        }
		else if (v > value) {
            if (right == NULL) right = new Tree(v);
            else right->insert(v); 
        }
    }

    bool search(int v) {
        if (v == value) return true;
        if (v < value)  return left  != NULL && left->search(v);
        else            return right != NULL && right->search(v);
    }

    void displayInOrder() {
        if (left)  left->displayInOrder();  // left
        cout << value << " "; // display the root value
        if (right) right->displayInOrder();  // right 
    }

    //display start from top
    void displayPreOrder() {
        cout << value << " "; //root value
        if (left)  left->displayPreOrder();
        cout << " | " ;
        if (right) right->displayPreOrder();
    }
};

int main() {
    // insert 1 to 7
    int order[] = {4, 2, 6, 1, 3, 5, 7};

    Tree* root = new Tree(order[0]);
    // right element as root
    for (int i = 1; i < 7; i++) {  // only insert 6 numbers
        root->insert(order[i]);
    }

    cout << "In-order (sorted): ";
    root->displayInOrder();
    cout << endl;

    cout << "Pre-order (shows structure): ";
    root->displayPreOrder();
    cout << endl;

    cout << "Search 5: " << (root->search(5) ? "found" : "not found") << endl;
    cout << "Search 9: " << (root->search(9) ? "found" : "not found") << endl;
}
