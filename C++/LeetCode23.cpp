__________________________________________________________________________________________________
20ms
static int SPEED_UP = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution {
 public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ret, *curr;
        if (l2 == NULL)
            return l1;
        if (l1 == NULL)
            return l2;
        if (l1->val < l2->val) {
            ret = l1;
            l1 = l1->next;
        } else {
            ret = l2;
            l2 = l2->next;
        }
        curr = ret;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return ret;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        if (lists.size() & 1)
            lists.push_back(NULL);
        for (int i = 0; i < lists.size()/2; ++i) {
            lists[i] = mergeTwoLists(lists[i*2], lists[i*2+1]);
        }
        lists.resize(lists.size()/2);
        if (lists.size() == 1)
            return lists[0];
        else
            return mergeKLists(lists);
    }
};
__________________________________________________________________________________________________
24ms
class Solution {
public:
    ListNode* merge2Lists(ListNode* a, ListNode* b){
        if(!a){
            return b;
        }
        if(!b){
            return a;
        }
    
        if(a->val <= b-> val){
            a->next = merge2Lists(a->next, b);
            return a;
        }
        else{
            b->next = merge2Lists(a, b->next);
            return b;
        }  
    }
    
    ListNode* mergebinary(vector<ListNode*>& lists, int left, int right){
        if(right < left){
            return NULL;
        }
        if(right == left){
            return lists[left];
        }
        int mid = left + (right - left)/2;
        return merge2Lists(mergebinary(lists, left, mid), mergebinary(lists, mid+1, right));
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergebinary(lists, 0, lists.size()-1);
    }
};
__________________________________________________________________________________________________
28ms
static const int __ = []() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        return 0;
    }();
class Solution {
public:
    ListNode* mergeList(ListNode *l1, ListNode *l2)
    {
        ListNode *l = new ListNode(0);
        ListNode *ln = l;
        while (l1&&l2)
        {
             if (l1->val<l2->val)
            {
                ln->next = l1;
                l1 = l1->next;
            }
            else
            {
                ln->next = l2;
                l2 = l2->next;
            }
             ln = ln->next;
        }
        if (l1) ln->next = l1;
        else ln->next = l2;
        return l->next;
    }
    ListNode* mergeLists(vector<ListNode*>& lists, int a, int b)
    {
        if (a > b)
            return NULL;
        if (a == b)
            return lists[a];
        if (a+1==b)
            return mergeList(lists[a], lists[b]);
        int m = (a + b) / 2;
        return mergeList(mergeLists(lists, a, m), mergeLists(lists, m + 1, b));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        int a = 0;
        int b = size - 1;
        return mergeLists(lists, a, b);
    }
};
__________________________________________________________________________________________________
10636 kb
static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    #if 1
    ListNode* getSmallerNode(ListNode *l1, ListNode *l2)
    {
        ListNode root(0), *last=NULL;
        
        last = &root;
        
        while (l1 && l2)
        {
            if((l1)->val < (l2)->val)
            {
                last->next = l1;
                l1 = (l1)->next;
            }else
            {
                last->next = l2;
                l2 = (l2)->next;
            }
            last = last->next;
            last->next = NULL;
        }
        
        if (l1)
        {
            last->next = l1;
        }else if(l2)
        {
            last->next = l2;
        }
        
        return root.next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *nl=NULL, *last=NULL, *tmpN=NULL, *l3s=NULL, *l1=NULL, *l2=NULL;
        vector<ListNode*> &cpyList = lists;

        #if 0        
        for (int i=0; i<lists.size(); i++)
        {
            if (lists[i])
                cpyList.push_back(lists[i]);
        }
#endif
        
        if (!cpyList.size())
        {
            return NULL;
        }
        
        if (cpyList.size() == 1)
        {
            return cpyList[0];
        }
        
        while(cpyList.size()>1)
        {
            nl = getSmallerNode(cpyList[0], cpyList[1]);
            cpyList.erase(cpyList.begin());
            cpyList.erase(cpyList.begin());
            cpyList.push_back(nl);
        }

        return cpyList[0];
    }
    
    #else
    ListNode* getSmallNode(vector<ListNode*>& lists)
    {
        int i=0, minI=0;
        ListNode* tmp=NULL;

        for (i=1; i<lists.size(); i++)
        {
            if (lists[minI]->val > lists[i]->val)
            {
                minI = i;
            }
        }
        
        tmp = lists[minI];
        lists[minI] = lists[minI]->next;
        if (lists[minI] == NULL)
        {
            lists.erase(lists.begin()+minI);
        }
        
        return tmp;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *nl=NULL, *last=NULL, *tmpN=NULL;
        vector<ListNode*>cpyList;
        
        for(int j=0; j<lists.size(); j++)
        {
            if (lists[j])
                cpyList.push_back(lists[j]);
        }


        while(cpyList.size())
        {
            tmpN = getSmallNode(cpyList);
            if (nl==NULL)
            {
                nl = tmpN;
                last = tmpN;
            }else
            {
                last->next = tmpN;
                last = tmpN;
            }
        }
        return nl;
    }
#endif
};
__________________________________________________________________________________________________
11048 kb
auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        if (a == nullptr) {
            return b;
        }
        if (b == nullptr) {
            return a;
        }
        ListNode* head;
        if (a->val < b->val) {
            head = a;
            a = a->next;
        } else {
            head = b;
            b = b->next;
        }
        head->next = nullptr;
        ListNode* tail = head;
        while (a != nullptr && b != nullptr) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
            tail->next = nullptr;
        }
        if (a != nullptr) {
            tail->next = a;
        } else if (b != nullptr) {
            tail->next = b;
        }
        return head;
    }
    
    void mergePairs(vector<ListNode*>& lists, vector<ListNode*>& dst) {
        for (int i = 0; i < lists.size(); i += 2) {
            ListNode* a = lists[i];
            ListNode* b = i + 1 < lists.size() ? lists[i + 1] : nullptr;
            ListNode* mergedList = merge(a, b);
            if (mergedList != nullptr) {
                dst.push_back(mergedList);
            }
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> dst;
        while (lists.size() > 1) {
            mergePairs(lists, dst);
            std::swap(lists, dst);
            dst.clear();
        }
        if (lists.empty()) {
            return nullptr;
        }
        return lists[0];
    }
};
__________________________________________________________________________________________________
