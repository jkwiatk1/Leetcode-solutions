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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode();
        ListNode* tail = dummyNode;
        while (list1 && list2) {
            if(list1->val >= list2->val) {
                tail->next = list2;
                list2 = list2->next;
            }
            else{
                tail->next = list1;
                list1 = list1->next;
            }   
            tail = tail->next;
        }

        if(list1){tail->next = list1;}
        else if(list2){tail->next = list2;}

        return dummyNode->next;       
    }
};


int main() {
    Solution solution;
    vector<int> head = {1,2,4};
    vector<int> head2 = {1,3,4};
    ListNode* linkedList = createLinkedList(head);
    ListNode* linkedList2 = createLinkedList(head2);
    ListNode* result = nullptr;
    
    cout << "Created Linked List\nList1: " << endl;
    printLinkedList(linkedList);
    cout << "List2: " << endl;
    printLinkedList(linkedList2);

    result = solution.mergeTwoLists(linkedList, linkedList2);  

    cout << "Result: ";
    printLinkedList(result);

    return 0;
}