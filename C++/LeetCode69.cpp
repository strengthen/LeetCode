__________________________________________________________________________________________________
4ms
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int left = 0, right = x/2+1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (x / mid == mid) return mid;
            else if (x / mid > mid) left=mid+1;
            else right=mid-1;
        }
        return right;
    }
};
__________________________________________________________________________________________________
8044 kb
static const auto speedup = []() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();
class Solution {
public:
	int mySqrt(int x) {
		if (x < 2) return x;
		unsigned int multi = 0;
		int ret = 0;
		for (size_t i = 2; i < INT_MAX; i++)
		{
			multi = i * i;
			if (multi == x) return i;
			else if(multi > x){
				ret = i - 1;
                break;
			}
		}
		return ret;
	}
};
__________________________________________________________________________________________________
