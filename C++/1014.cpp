__________________________________________________________________________________________________
sample 24 ms submission
static const auto io_sync_off = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& A) {
		int n = A.size();
		int m = 0, ans = 0;
		for(int i = 0; i < n; ++i) {
			int tmp = m + A[i] - i; // 24 ms
			if(ans < tmp)
				ans = tmp;
			tmp = A[i] + i;
			if(m < tmp)
				m = tmp;

			// ans = max(ans, m + A[i] - i); // 28 ms
			// m = max(m, A[i] + i);
		}
		return ans;
	}
};
__________________________________________________________________________________________________
sample 28 ms submission
static int _ = [](){std::ios::sync_with_stdio(false);cin.tie(NULL);return 0;}();

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<class K,class V> using umap = unordered_map<K,V>;
template<class T> using uset = unordered_set<T>;

#define F(i,l,r) for(int i=(l);i<(r);i++)
#define RF(i,l,r) for(int i=(r)-1;i>=l;i--)
#define FILL(a,v) memset(a,v,sizeof(a))
#define LOG(arg) cout << ""#arg" = " << (arg) << endl

const int MOD = 1e9+7;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int mx = a[0]+a[1]-1;
        int lmx = max(a[0] - 1, a[1]);
        int n = a.size();
        F(i,2,n){
            lmx--;
            mx = max(mx, lmx + a[i]);
            lmx = max(lmx, a[i]);
        }
        return mx;
    }
};
__________________________________________________________________________________________________
