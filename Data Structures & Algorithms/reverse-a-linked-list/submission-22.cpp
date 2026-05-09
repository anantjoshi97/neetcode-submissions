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

// class Solution{
// public:
//     ListNode* reverseList(ListNode* head){
//         //if there are 2 nodes only
//         if (head==nullptr){return head;}
//         ListNode* head1 = head;
//         if (head->next!=nullptr){
//             head1
//         }
//         ahead->next = head;        
//         return reverseList(ahead);
        
//         // old_tail = reverseList(head->next);
//         // reverseList(head->next)->next = head;
//         // head->next = nullptr;
//         // ListNode* ahead = head->next;
//         // ahead->next = head;
//         // head->next = nullptr;

//     }
// };



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    
        if(head==nullptr){return head;}

        ListNode* head1= head;
        if (head->next!=nullptr){
            head1 = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;
        return head1;
    
    }
    
};
