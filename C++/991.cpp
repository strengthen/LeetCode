__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while (Y>X) {
            Y=Y%2>0?Y+1:Y/2;
            ++ans;
        }
        return ans+X-Y;
    }
};
__________________________________________________________________________________________________
sample 8068 kb submission

static int x=[](){std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}(); // NOLINT

class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while (Y > X) {
            ans++;
            if (Y % 2 == 1) {
                Y++;
            } else {
                Y /= 2;
            }
        }

        return ans + X - Y;
    }
};
__________________________________________________________________________________________________
