Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]


  class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0 ;
        ListNode* temp = head ;

        while(temp != NULL){
            count++ ;
            temp = temp->next ;
        }
        count = count - n ;
        
        if(count == 0){
            temp = head ;
            head = head->next ;
            delete temp ;
            return head ;
        }

        ListNode* curr = head ;
        ListNode* prev = NULL ;

        while(count--){
            prev = curr ;
            curr = curr->next ;
            
        }
        prev->next = curr->next ;
        delete curr ;

        return head ;
    }
};
