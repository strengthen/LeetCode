__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        string str = "";
        for (char i = '1'; i <= '9'; ++i) {
            str.push_back(i);
            getNum(res, N-1, K, str);
            str.pop_back();
        }
        if (N == 1)
            res.push_back(0);
        return res;
    }
    
    void getNum(vector<int> &res, int n, int K, string &str) {
        if (n == 0) 
            res.push_back(stoi(str));
        else {
            char k = str.back()-K;
            if (k >= '0') {
                str.push_back(k);
                getNum(res, n-1, K, str);
                str.pop_back();
            }
            k += 2*K;
            if (K > 0 && k <= '9') {
                str.push_back(k);
                getNum(res, n-1, K, str);
                str.pop_back();
            }
        }
    }
};
__________________________________________________________________________________________________
sample 9240 kb submission
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ret;
        if(N==1) ret.push_back(0);
        int tmp = 0;
        dfs(0, N, K, ret, tmp);
        return ret;
    }
    
    void dfs(int d, int N, int K, vector<int> &ret, int tmp)
    {
        if(d == N) {
            ret.push_back(tmp);
            return;
        }
        
        if(d == 0) {
            for(int i=1; i<=9;++i) {
                dfs(d+1, N, K, ret, i);
            }
        }
        else {
            for(int i=0;i<=9;++i) {
                if((tmp%10) + K == i || (tmp%10) - K == i )
                    dfs(d+1, N, K, ret, tmp*10 + i);
            }
        }
    }
};
__________________________________________________________________________________________________
