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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* begin=NULL;
        int value=0;
        do{
            ListNode* end;
            if(l1!=NULL){
                value+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                value+=l2->val;
                l2=l2->next;
            }
            ListNode* temp=new ListNode(value%10);
            if(begin==NULL){
                begin=temp;
                end=begin;
            }else{
                end->next=temp;
                end=end->next;
            }
            value/=10;
        }while(value||(l1!=NULL)||(l2!=NULL));
        return begin;
    }
};
