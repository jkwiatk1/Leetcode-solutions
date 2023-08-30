#include <iostream>
#include <limits>

using namespace std;

class MinStack {
private:
    struct Node {
        int value;
        int minSoFar;
        Node* next;
        Node(int val, int minVal) : value(val), minSoFar(minVal), next(nullptr) {}
    };

    Node* topNode; 
public:
    MinStack() : topNode(nullptr) {}
    
    void push(int val) {
        int newMin = (topNode == nullptr) ? val : min(val, topNode->minSoFar);
        Node* newNode = new Node(val, newMin);
        newNode->next = topNode;
        topNode = newNode;
    }
    
    void pop() {
        if (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
    
    int top() const {
        if (topNode != nullptr) {
            return topNode->value;
        } else {
            cerr << "Stack is empty." << endl;
            return -1;
        }
    }
    
    int getMin() const {
        if (topNode != nullptr) {
            return topNode->minSoFar;
        } else {
            cerr << "Stack is empty." << endl;
            return numeric_limits<int>::max(); 
        }
    }
};


int main()
{
    MinStack* obj = new MinStack();
    obj->push(10);
    obj->push(20);
    obj->push(5);
    obj->push(30);
    obj->push(13);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();

    cout << param_3 << endl;
    cout << param_4 << endl;

    return 0;
}