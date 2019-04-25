__________________________________________________________________________________________________
sample 4 ms submission
auto speedup =[]() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {   
public:
    int thirdMax(vector<int>& nums) 
    {
        int64_t a = numeric_limits<decltype(a)>::min(), b = a, c = a;
        for (int n : nums) {
            if (n <= c || n == b || n == a)
                continue;
            c = n;
            if (c > b)
                swap(b, c);
            if (b > a)
                swap(a, b);
        }
        return (numeric_limits<decltype(c)>::min() == c) ? a : c;
    }
};
__________________________________________________________________________________________________
sample 8932 kb submission
static auto x = [](){std::ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr;}();

class Solution{
public:
	int thirdMax(vector<int>& nums){
		long max1=LONG_MIN,max2=LONG_MIN,max3=LONG_MIN;
		
		for(int i=0;i<nums.size();i++)
			if(nums[i]>max3){
				max1=max2; max2=max3; max3=nums[i];
			}
			else if(nums[i]<max3&&nums[i]>max2){
				max1=max2; max2=nums[i];
			}
			else if(nums[i]<max2&&nums[i]>max1)
				max1=nums[i];
		
		return max1==LONG_MIN ? max3 : max1;
	}
};
__________________________________________________________________________________________________
