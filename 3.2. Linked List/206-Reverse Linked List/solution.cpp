#include <iostream>
#include <vector>

using namespace std;


 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


 ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}


void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val;
        if (current->next) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }
};

int main() {
    Solution solution;
    vector<int> head = {1,2,3,4,5};
    ListNode* linkedList = createLinkedList(head);
    
    cout << "Created Linked List: ";
    printLinkedList(linkedList);

    linkedList = solution.reverseList(linkedList);  

    cout << "Reversed: ";
    printLinkedList(linkedList);

    while (linkedList) {
        ListNode* temp = linkedList;
        linkedList = linkedList->next;
        delete temp;
    }  

    return 0;
}