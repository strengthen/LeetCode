__________________________________________________________________________________________________
40ms
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* dummy;

    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* c=dummy;
        //cout<<"Merging:";
        while(left||right){
            if(!left || (right && right->val<left->val))c->next=right,right=right->next;
            else c->next=left,left=left->next;
            c=c->next;
            //cout<<c->val<<" ";
        }
        //cout<<endl;
        c->next=nullptr;
        return dummy->next;
    }
public:
        Solution(){
            dummy=new ListNode(-1);
        }
    ~Solution(){
        delete dummy;
    }
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next)return head;
        ListNode* slow=head,*fast=head->next;
        while(fast && fast->next)slow=slow->next,fast=fast->next->next;
        fast=slow->next;
        slow->next=nullptr;
        return merge(sortList(head),sortList(fast));
    }
    
};
static auto _=[](){ios::sync_with_stdio(false);return 0;}();
__________________________________________________________________________________________________
11384 kb
class Solution
{
    public:
    ListNode* sortList(ListNode* head)
    {
        // Do nothing if the list has length 0 or 1.
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* carry = nullptr;
        ListNode* tmp[64]{ };
        ListNode** fill = tmp;
        ListNode** counter = nullptr;
        do
        {
            carry = head;
            head = head->next;
            carry->next = nullptr;
            //carry.splice(carry.begin(), *this, begin());
            // carry.size==1
            for (counter = tmp; counter != fill && nullptr != *counter; ++counter)
            {
                // This operation is stable: for equivalent elements in the two lists, the elements from *this shall always precede the elements from other
                // https://en.cppreference.com/w/cpp/container/list/merge
                // so not equal to carry.merge(*count)
                carry = merge(carry, *counter);
                // count.size>=1, carry.size>=1
                //*counter = merge(*counter, carry);
                // count.size>=2, carry.size=0
                //std::swap(carry, *counter);
                // count.size=0, carry.size>=2
            }
            // count.size=0, carry.size>=1
            std::swap(carry, *counter);
            // count.size>=1, carry.size=0
            if (counter == fill)
                ++fill;
        }
        while (head != nullptr);
        for (counter = tmp + 1; counter != fill; ++counter)
            *counter = merge(*counter, *(counter - 1));
        return *(fill - 1);
    }
    int getLen(ListNode* head)
    {
        int len = 0;
        for (; head != nullptr; head = head->next)
        {
            ++len;
        }
        return len;
    }
    ListNode* advance(ListNode* head, int len)
    {
        for (int i = 0; i < len; ++i)
        {
            head = head->next;
        }
        return head;
    }
    ListNode* merge(ListNode*& first, ListNode*& second)
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int lenA = 0;
        int lenB = 0;
        while (first != nullptr && second != nullptr)
        {
            if (first->val <= second->val)
            {
                tail->next = first;
                first = first->next;
                ++lenA;
            }
            else
            {
                tail->next = second;

                second = second->next;
                ++lenB;
            }
            tail = tail->next;
        }

        if (first == nullptr)
        {
            tail->next = second;
        }
        else
        {
            tail->next = first;
        }

        first = nullptr;
        second = nullptr;

        return dummy.next;
    }

};
__________________________________________________________________________________________________
