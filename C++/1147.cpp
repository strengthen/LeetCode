__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    string A;
    
    int rec(int st, int en) {
        if(st == en) {
            return 1;
        }
        
        if(st > en) {
            return 0;
        }
        
        
        for(int i = en;i >= st;--i) {
            if(en - i + 1 + st > i) {
                return 1;
            }
            if(A[i] == A[st]) {
                bool ok = true;
                for(int j = i;j <= en;++j) {
                    if(A[j] != A[st + (j - i)]) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    // cout << st << " " << i << "\n";
                    return 2 + rec(st + (en - i) + 1, i - 1);
                }
            }
        }
        return 1;
    }
    
    int longestDecomposition(string text) {
        A = text;
        return rec(0, A.size() - 1);
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int longestDecomposition(string s) {
        int N = s.size();
        int l = 0, i = 0, j = N, r = N;
        int cnt = 0;
        while (i < j) {
            while (i-l==0 || s.substr(l, i-l) != s.substr(j, r-j)) {
                i ++;
                j --;
            }
            cnt += i <= j ? 2 : 1;
            l = i, r = j;
        }
        return cnt;
    }
};
__________________________________________________________________________________________________
