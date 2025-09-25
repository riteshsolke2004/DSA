83. Remove Duplicates from Sorted List

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Example 1:
Input: head = [1,1,2]
Output: [1,2]
  
Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]

#Solution :- 
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
    ListNode* deleteDuplicates(ListNode* head) {

        
        if(head == NULL){
            return head ;
        }

        if(head->next == NULL){
            return head ;
        }

        ListNode* curr = head->next ;
        ListNode* prev = head ;

        while(curr != NULL){
            if(curr->val == prev->val){
                prev->next = curr->next ;
                curr->next = NULL ;
                delete curr ;
                curr = prev->next ; 
                
            }
            else{
                curr = curr->next ;
                prev = prev->next ;
            }

        }

        return head ;

        
    }
};
