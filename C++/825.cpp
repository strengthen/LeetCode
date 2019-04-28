__________________________________________________________________________________________________
sample 16 ms submission
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int count[122];
    int numFriendRequests(vector<int>& ages) {
        memset(count, 0, sizeof(count));
        for (auto x:ages) {
            count[x]++;
        }
        int ret = 0;
        
        for (int i = 1; i < 122; i++) {
            count[i] += count[i - 1];
            if (0.5 * i + 7 > i || count[i] - count[i - 1] == 0 || (count[i] - count[(int) (0.5 * i + 7)] - 1) <= 0)
                continue;
            ret += (count[i] - count[(int) (0.5 * i + 7)] - 1) * (count[i] - count[i - 1]);
        }
        return ret;
    }
};
__________________________________________________________________________________________________
sample 11240 kb submission
typedef long long int64;
const int INF = 0x3f3f3f3f;
template <class T> inline int len (const T &a) { return a.size (); }

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int N = len(ages);
        vector <int> dat(125, 0);
        for (int age: ages) dat[age]++;
        int ret = 0;
        for (int A = 1; A <= 120; A++)
            for (int B = 1; B <= A; B++) {
                if (!dat[A]) continue;
                if (!dat[B]) continue;
                if (2 * B <= A + 14) continue;
                if (B > 100 && A < 100) continue;
                cout << A << " " << B << " " << dat [A] << " " << dat[B] << endl;
                if (A != B)
                    ret += dat[A] * dat[B];
                else
                    ret += dat[A] * (dat[A] - 1);
            }
        
        return ret;
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
