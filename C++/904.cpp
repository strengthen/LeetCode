__________________________________________________________________________________________________
sample 44 ms submission
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int sz = tree.size();
        if (sz < 3) return sz;
        
        int fruit1 = -1;
        int fruit2 = -1;
        int start = -1;
        int prev = -1;
        int max_len = -1;
        for (int i = 0; i < sz; i++) {
            bool init = false;
            int f = tree[i];
            if(fruit1 == -1) {
                fruit1 = f;
                init = true;
                if (start == -1) start = i;
            }
            else if ( f != fruit1 && fruit2 == -1) {
                fruit2 = f;
                init = true;
                prev = i - 1;
            }
            bool isf1 = (fruit1 == f);
            bool isf2 = (fruit2 == f);
            if (isf1 || isf2 ) {
                if (!init) {
                    if (tree[i-1] != f) {
                        prev = i - 1;
                    }
                }
                if ((i == (sz - 1))) {
                    int len = i + 1 - start;
                    max_len = max(len, max_len);
                }
            } else {
                int len = i - start;
                max_len = max(len, max_len);
                if ( tree[i-1] == fruit1) {
                    fruit2 = f;
                } else {
                    fruit1 = f;
                }
                start = prev + 1;
                prev = i-1;
            }
            
        }    
        return max_len;
    }
};
__________________________________________________________________________________________________
sample 14836 kb submission
static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution {

public:
    int totalFruit(vector<int>& tree) {
        int basket1 = -1, basket2 = -1;
        int begin = 0, end = 0;

        int n = tree.size(), res = -1;
        for(end = 0; end < n; end++) {
            if(basket1 == -1) { basket1 = tree[end]; continue;}
            if(basket1 == tree[end]) continue;
            if(basket2 == -1) { basket2 = tree[end]; continue;}
            if(basket2 == tree[end]) continue;
            res = max(res, end - begin);
            begin = end - 1;
            while(begin >= 1 && tree[begin] == tree[begin-1]) begin--;
            basket1 = tree[begin];
            basket2 = tree[end];
        }
        res = max(res, end - begin);
        return res;
    }
};
__________________________________________________________________________________________________
