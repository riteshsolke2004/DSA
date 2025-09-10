
234. Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true
  
Example 2:
Input: head = [1,2]
Output: false


# Solution :- 

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

    int getlength(ListNode* head){
        ListNode* temp = head ;
        int count = 0 ;
        while(temp != NULL){
            count++ ;
            temp = temp->next ;
        }
        return count ;
    }

    ListNode* getmid(ListNode* head){
        ListNode* slow = head ;
        ListNode* fast = head ;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        return slow  ;
    }

    ListNode* reversell(ListNode* head){
    ListNode* prev = NULL ;
    ListNode* curr = head ;

    while(curr != NULL){
        ListNode* forword = curr->next ;
        curr->next = prev ; 
        prev = curr ;
        curr = forword ;
    }
    return prev ;  
}


    bool isPalindrome(ListNode* head) {
        int len = getlength(head);
        ListNode* mid = getmid(head) ;

        ListNode* finalmid = NULL ;
        if(len & 1){
            finalmid = mid->next ;
        }
        else{
            finalmid = mid ;
        }

        finalmid = reversell(finalmid) ;
        ListNode* temp = head ;
        while(temp !=NULL && finalmid != NULL){
            if(temp->val != finalmid->val){
                return false  ;
            }
            else{
                temp = temp -> next ;
                finalmid = finalmid -> next ;
            }
        }
        return true ;
        
    }
};
