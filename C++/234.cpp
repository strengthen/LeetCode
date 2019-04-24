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
static int desyncio = []() {
    std::ios::sync_with_stdio( false );
    cin .tie( nullptr );
    cout.tie( nullptr );
    return 0;
}();

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slowp = head, *fastp = head, *revp = NULL;
        while (fastp && fastp->next){
            fastp = fastp->next->next;
            ListNode* tmp = slowp->next;
            slowp->next = revp;
            revp = slowp;
            slowp = tmp;
        }
        if (fastp) slowp = slowp->next;
        while (slowp && revp){
            if (slowp->val != revp->val) return false;
            slowp = slowp->next;
            revp = revp->next;
        }
        return true;
    }
};
__________________________________________________________________________________________________
sample 12160 kb submission
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
bool isPalindrome(ListNode* head) {
	ListNode* slowp = head, *fastp = head, *revp = NULL;
	while (fastp && fastp->next){
		fastp = fastp->next->next;
		ListNode* tmp = slowp->next;
		slowp->next = revp;
		revp = slowp;
		slowp = tmp;
	}
	if (fastp) slowp = slowp->next;
	while (slowp && revp){
		if (slowp->val != revp->val) return false;
		slowp = slowp->next;
		revp = revp->next;
	}
	return true;
}
};
__________________________________________________________________________________________________
