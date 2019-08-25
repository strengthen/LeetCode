__________________________________________________________________________________________________
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* root =new ListNode(0);
        root->next=head;
        unordered_map<int,ListNode*>um;
        um[0]=root;
        int ac=0;
        
        while(head!=NULL){
            ac+=head->val;
            
            //found value
            if(um.find(ac)!=um.end()){
                ListNode* prev= um[ac];
                ListNode* start= prev;
                
                //delete bad references
                int aux = ac;
                while(prev!=head){
                    prev=prev->next;
                    aux+=prev->val;
                    if(prev!=head)um.erase(aux);
                }
                
                start->next = head->next;
            }else{
                um[ac]= head;
            }
            
            head=head->next;
        }
        
        return root->next;
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* root =new ListNode(0);
        root->next=head;
        
        unordered_map<int,ListNode*>um;
        um[0]=root;
        
        int ac=0;
        
        while(head!=NULL){
            ac+=head->val;
            
            //found value
            if(um.find(ac)!=um.end()){
                ListNode* prev= um[ac];
                ListNode* start= prev;
                
                //delete bad references
                int aux = ac;
                while(prev!=head){
                    prev=prev->next;
                    aux+=prev->val;
                    if(prev!=head)um.erase(aux);
                }
                
                
                start->next = head->next;
            }else{
                um[ac]= head;
            }
            
            head=head->next;
        }
        
        return root->next;
    }
};
__________________________________________________________________________________________________
