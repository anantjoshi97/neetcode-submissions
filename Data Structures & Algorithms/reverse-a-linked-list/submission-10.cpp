/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    
    if (head == nullptr || head->next == nullptr){return head;}
    
    
    ListNode* prev = head;
    ListNode* curr = head->next;
    ListNode* ahead = curr->next;
    curr->next = prev;
    prev->next = nullptr;
    while(ahead!=nullptr){
        prev=curr;
        curr=ahead;
        ahead=ahead->next;
        curr->next = prev;

    }
    
    return curr;
    
    }
    
};
