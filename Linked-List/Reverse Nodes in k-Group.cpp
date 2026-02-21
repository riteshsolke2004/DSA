Reverse Nodes in k-Group


Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is
not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.


  Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

# SOLUTION 
  class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0 ;
        ListNode* temp = head ;

        while(temp != NULL && count < k ){
            temp = temp->next ;
            count++ ;
        }
        

        if(count == k){
            ListNode* prev = NULL ;
            ListNode* curr = head ;
            ListNode* forword = NULL ;

            int i = 0 ;

            while(i < k){
                forword = curr->next ;
                curr->next = prev ;
                prev = curr ;
                curr = forword ;
                i++ ;
            }

            ListNode* recursionKaHead = reverseKGroup(forword , k) ;

            head->next = recursionKaHead ;
            return prev ;

        }
        else {
            return head ;
        }
    }
};
