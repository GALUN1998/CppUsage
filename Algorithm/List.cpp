#include <iostream>
using namespace std;

typedef struct ListNode{
    ListNode* next;
    int data;
} ListNode;

void insertNode(ListNode* head) {
    ListNode* node = new ListNode;
    node->data = 10000;
    node->next = head->next;
    head->next = node;
}

ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* nextnode = nullptr;
    while(cur != nullptr) {
        nextnode = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nextnode;
    }
    return pre;
}
int main() {

}