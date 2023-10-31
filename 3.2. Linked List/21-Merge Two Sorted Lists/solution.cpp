#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/merge-two-sorted-lists/
// https://www.youtube.com/watch?v=XIdigk956u0&t=2s
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prev = nullptr;
        ListNode* current = list1;
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
    vector<int> head2 = {1,2,3,4,5};
    ListNode* linkedList = createLinkedList(head);
    ListNode* linkedList2 = createLinkedList(head2);
    
    cout << "Created Linked List: ";
    printLinkedList(linkedList);

    linkedList = solution.mergeTwoLists(linkedList, linkedList2);  

    cout << "Reversed: ";
    printLinkedList(linkedList);

    while (linkedList) {
        ListNode* temp = linkedList;
        linkedList = linkedList->next;
        delete temp;
    }  

    return 0;
}