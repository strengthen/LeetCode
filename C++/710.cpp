__________________________________________________________________________________________________
sample 164 ms submission
static int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
} ();
class Solution {
    int N;
    vector<int> B;
public:
    Solution(int N, vector<int> blacklist): N(N-blacklist.size()), B(move(blacklist)) {
        sort(B.begin(), B.end());
        int i=0;
        for (int &b: B) {
            b -= (i++);
        }
    }
    
    int pick() {
        int n = rand()%N;
        if (B.empty() || n<B[0]) return n;
        int l = 0, r=B.size()-1;
        while (l<r) {
            int mid = (l+r)/2;
            if (B[mid]<=n && n<B[mid+1]) return n+mid+1;
            if (B[mid]>n) r=mid-1; else l=mid+1;
        }
        return n+l+1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
__________________________________________________________________________________________________
sample 50128 kb submission
class Solution {
public:
    vector<int> blacklist;
    int sz;
    Solution(int N, vector<int> blacklist) {
        this->blacklist = blacklist;
        sort(this->blacklist.begin(), this->blacklist.end());
        sz = N - this->blacklist.size();
    }
    
    int pick() {
        int r = rand() % sz;
        int lo = 0;
        int hi = this->blacklist.size();
        while (lo < hi) {
            int md = (lo + hi) / 2;
            if (this->blacklist[md] >= r + md + 1) {
                hi = md;
            } else {
                lo = md + 1;
            }
        }
        return r + lo;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
__________________________________________________________________________________________________
