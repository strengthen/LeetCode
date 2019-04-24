__________________________________________________________________________________________________
44ms
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
    void reorderList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if((head==NULL)||(head->next==NULL)||(head->next->next==NULL))return;
        
        struct ListNode *fp=head;
        struct ListNode *sp=head;
        while(fp!=NULL)
        {
            fp=fp->next;
            if(fp!=NULL)
            {
                sp=sp->next;fp=fp->next;
            }
        }
        struct ListNode *bck=rev(sp);
        struct ListNode *t1=head;
        struct ListNode *bn;
        bn=bck->next;
        struct ListNode *fn;
        fn=t1->next;
        
        while((bn!=NULL)||(fn!=NULL))
        {
            t1->next=bck;
            bck->next=fn;
            t1=fn;bck=bn;
            fn=fn->next;
            if(fn==bn)return;
            bn=bn->next;
        }
        
    }
    ListNode* rev(ListNode * head)
    {
        struct ListNode * p;struct ListNode * c;struct ListNode * n;
        p=head;
        
        c=p->next;
        p->next=NULL;
        n=c->next;
        while(n!=NULL)
        {
            c->next=p;
            p=c;
            c=n;
            n=n->next;
        }
        c->next=p;
        return c;
    }
};
__________________________________________________________________________________________________
11940 kb
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
    void reorderList(ListNode* head) {
        int len = 0;
        ListNode *now, *pre, *tmp, *tmp1, *l, *r;
        for(now=head; now!=NULL; now=now->next)
            len++;
        if(len<=2)
            return;
        now = head;
        for(int i=0; i<(1+len)/2-1; i++)
            now = now->next;
        pre = now;
        now = pre->next;
        pre->next = NULL;
        while(now!=NULL){
            tmp = now->next;
            now->next = pre;
            pre = now;
            now = tmp;
        }
        l = head;
        r = pre;
        while(l!=NULL && l!=r){
            tmp = l->next;
            tmp1 = r->next;
            l->next = r;
            r->next = tmp;
            l = tmp;
            r = tmp1;
        }
    }
};
__________________________________________________________________________________________________
