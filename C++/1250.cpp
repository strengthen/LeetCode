__________________________________________________________________________________________________
sample 16 ms submission
static const int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int ,int> pii;
typedef pair<ll, ll> pll;
typedef double rl;
#define pb push_back
#define _x first
#define _y second

#if 1
#define dbg(x) cout << #x << ": " << (x) << endl;
#else
#define dbg(x)
#endif

class Solution {
    /*
    int gcd(int A, int B)
    {
        while(B!=0)
        {
            A%=B;
            swap(A, B);
        }
        return A;
    }
    */
public:
    bool isGoodArray(vector<int>& nums) {
        int G=0;
        for(int a: nums)
        {
            G=gcd(a, G);
            if(G==1) break;
        }
        return G==1;
    }
};
__________________________________________________________________________________________________
sample 20 ms submission
inline int gcd(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            g = gcd(g, nums[i]);
            if (g == 1) return true;
        }
        
        return g == 1;
    }
};

auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
