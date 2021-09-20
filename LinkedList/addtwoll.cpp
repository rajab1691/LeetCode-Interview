// https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int val=l1->val+l2->val;
        ListNode* l=new ListNode(val%10);
        val/=10;
        ListNode* ptr=l;
        while(l1->next!=NULL or l2->next!=NULL){
            
            if(l1->next!=NULL and l2->next!=NULL){
                l1=l1->next;
                l2=l2->next;
                val+=(l1->val+l2->val);
                ListNode* node=new ListNode(val%10);
                val/=10;
                ptr->next=node;
                ptr=node;
            }else if(l2->next!=NULL){
                l2=l2->next;
                val+=(l2->val);
                ListNode* node=new ListNode(val%10);
                val/=10;
                ptr->next=node;
                ptr=node;
            }else{
                l1=l1->next;
                val+=(l1->val);
                ListNode* node=new ListNode(val%10);
                val/=10;
                ptr->next=node;
                ptr=node;
            }        
        }
        if(val>0){
            ListNode* node=new ListNode(val);
            ptr->next=node;
        }
        return l;
    }
};
