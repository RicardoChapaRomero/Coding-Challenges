/*
 Given a non-empty, singly linked list with head node head, return a middle
 node of linked list.
 
 If there are two middle nodes, return the second middle node.
 
 
 Input: [1,2,3,4,5]
 Output: Node 3 from this list
 
 Input: [1,2,3,4,5,6]
 Output: Node 4 from this list
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* turtle = head;
    ListNode* rabbit = head->next;
    int n=2;
    while(rabbit != nullptr){
        if(rabbit->next== nullptr) return turtle->next;
        else{
            turtle = turtle->next;
            for(int i=0; i<n && rabbit != nullptr; i++){
                rabbit = rabbit->next;
            }
        }
    }
    return turtle;
}

int main() {
    
    return 0;
}
