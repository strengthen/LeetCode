__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K == 1) {
            int len{S.size()};
            S += S;
            int max_beg{};
            for (int beg = 1; beg < len; ++beg) {
                if (lexicographical_compare(S.begin() + beg, S.begin() + beg + len, S.begin() + max_beg, S.begin() + max_beg + len)) {
                    max_beg = beg;
                }
            }
            return string(S.begin() + max_beg, S.begin() + max_beg + len);
        }
        else {
            sort(S.begin(), S.end());
            return S;
        }
    }
};
__________________________________________________________________________________________________
sample 9096 kb submission
class Solution {
public:
    string orderlyQueue(string S, int K) {
        //那么这个题就是说我们每次可以移动前K个中的一个 到最后面 然后返回经过很多次移动后，字典顺序最小的那个 如果k = 1 那么就是一个个的移动 找到最小的那个 如果是K >=2 感觉K越大，我能选择的自由度越大，然后比如cba k = 2，=> cab => abc 一定能做到直接sort S的结果 所以直接根据K来判断即可
        if(S.empty()) return S;
        if(K > 1){
            sort(S.begin(), S.end());
            return S;
        }
        string res = S;
        for(int i = 0; i < S.size(); ++i){
            rotate(S.begin(), S.begin() + 1, S.end());
            if(S < res){
                res = S;
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
