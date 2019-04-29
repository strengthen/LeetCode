__________________________________________________________________________________________________
sample 20 ms submission
typedef long long int LL;
typedef long long unsigned LLU;
typedef long double LD;
#define G(_tuple, num) (get<num>(_tuple))
#define len(c) int((c).size())
#define allof(container) (container).begin(), (container).end()
#define frontof(container, N) (container).begin(), (container).begin() + (N)
#define rep(i, N) for (int i = 0; i < int(N); i++)
#define repr(i, begin, end) for (int i = int(begin); i < int(end); i++)
#define irep(i, N) for (int i = int(N) - 1; i >= 0; i--)
#define irepr(i, begin, end) for (int i = int(end) - 1; i >= int(begin); i--)

class Solution {
    int ALEN;
    const int MAXN = 10000 + 8;
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        ALEN = len(A);
        return atMostK(A, K) - atMostK(A, K - 1);
    }
    int atMostK(vector<int>& A, int K){
        vector<int> cnt(MAXN);
        int left = 0, right = 0, type = 0, res = 0;
        while(right < ALEN){
            cnt[A[right]] ++;
            if(cnt[A[right]] == 1) type ++;
            while(type > K){
                cnt[A[left]]--;
                if(cnt[A[left]] == 0) type --;
                left ++;
            }
            res += right - left + 1;
            right ++;
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 11732 kb submission
int __FAST_IO = [](){ios::sync_with_stdio(0); cin.tie(0); return 0;}();

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int C[A.size() + 1];
        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            int k = 0;
            memset(C, 0, sizeof(C));
            for (int j = i; j < A.size(); j++) {
                if (!(C[A[j]]++)) k++;
                if (k == K) ans++;
                if (k > K) break;
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
