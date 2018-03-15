/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2){
            return NULL;
        }
        else if(l1 && !l2){
            return l1;
        }
        else if(!l1 && l2){
            return l2;
        }
        else{
            if(l1->val > l2->val){
            swap(l1,l2);
        }
          ListNode* ret = new ListNode(l1->val);
          ListNode* ptr = ret;
          l1 = l1->next;
          
          while(l1 && l2){
              if(l1->val < l2->val){
                 
                  ptr -> next = new ListNode(l1->val);
                  ptr = ptr -> next;
                  l1 = l1->next;
              }
              else{
                  
                  ptr -> next = new ListNode(l2->val);
                  ptr = ptr -> next;
                  l2 = l2 -> next;
              }
          }
          if(l1 != NULL){
              ptr -> next = l1;
          }
          else{
              ptr -> next = l2;
          }
          return ret;
            
        }
        
    }
};
