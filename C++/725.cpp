__________________________________________________________________________________________________
sample 8 ms submission
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int length = 0;
        ListNode* node = root;
        while (node) {
            ++length;
            node = node->next;
        }
        vector<ListNode*> result;
        ListNode* prev;
        if (length < k) {
            node = root;
            while (node) {
                result.push_back(node);
                prev = node;
                node = node->next;
                prev->next = NULL;
            }
            while (length < k) {
                result.push_back(NULL);
                ++length;
            }
        } else {
            int group = k;
            k = length / group;
            int r = length % group;
            node = root;
            while (node) {
                int count = k;
                if (r > 0) ++count, --r;
                result.push_back(node);
                while (count > 0) {
                    prev = node;
                    node = node->next;
                    --count;
                }
                prev->next = NULL;
            }
        }
        
        return result;
    }
};

auto ___ = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
__________________________________________________________________________________________________
sample 9276 kb submission
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = 0;
        ListNode *p = root, *q;
        while (p != NULL) {
            n++;
            p = p->next;
        }
        int i = n/k;
        vector<int> record(k,0);
        for (int loop = 0; loop < k; loop++) {
            if (loop < n - k*i) record[loop] = i + 1;
            else record[loop] = i;
        }
        vector<ListNode*> result(k, NULL);
        result[0] = root;
        p = root;
        for (int j = 1; j < k; j++) {
            if (record[j] == 0) break;
            for (int jj = 0; jj < record[j-1] - 1; jj++) {
                p = p->next;
            }
            result[j] = p->next;
            q = p;
            p = p->next;
            q->next = NULL;
        }
        return result;
    }
};
__________________________________________________________________________________________________
