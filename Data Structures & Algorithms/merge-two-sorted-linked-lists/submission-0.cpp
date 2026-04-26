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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;     
        ListNode* l2 = list2;
        ListNode* l1 = list1;

        if (list1== nullptr){
            return list2;
        }
        else{            
            head = list1;
            l1 = list1->next;
        }
        if (list2==nullptr){
            return head;
        }
        else{            
            if (list2->val < list1->val){
                head= list2;
                l1= list1;
                l2 = list2 -> next;
            }
        }
        std::cout << "head" << std::endl;
        // ListNode* ahead = nullptr;
        ListNode* curr = head;
        // ListNode* prev = head;
        // prev -> next = curr;

        while (l1!=nullptr || l2!=nullptr){
            if (l1!=nullptr && l2!=nullptr){            
                if (l1->val <= l2->val){
                    curr->next = l1;
                    l1 = l1 -> next;
                    // std::cout << "l1" << std::endl;
                    //curr = curr -> next
                }
                else{
                    curr -> next = l2;
                    l2 = l2 -> next;
                    //curr = curr -> next;
                }
            }
            else if (l1!=nullptr){
                 curr-> next = l1;
                 l1 = l1->next;
                 //curr = curr -> next;
            }
            else{
                curr -> next = l2;
                l2 = l2 -> next;
                
            }
            curr = curr -> next;
        }

        return head;
    }
};
