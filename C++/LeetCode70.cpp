__________________________________________________________________________________________________
4ms
class Solution {
public:
    int climbStairs(int n) {
        long long int x=1;
        long long int y=2;
        long long int ans=0;
        if(n==1)return 1;
        if(n==2)return 2;
        n-=2;
        while(n--){
            ans=x+y;
            x=y;
            y=ans;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
8132 kb
static const auto speedup = []() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();
class Solution {
public:
	int climbStairs(int n) {
		if (n <= 2) return n;
		int last_two = 1;	//当前格子的前两格
		int last_one = 2;	//当前格子的前一格
		int ret = 0;
		int tmp = 3;
		while (tmp <= n)
		{
			ret = last_two + last_one;
			last_two = last_one;
			last_one = ret;
			++tmp;
		}
		return ret;
	}
};
__________________________________________________________________________________________________
