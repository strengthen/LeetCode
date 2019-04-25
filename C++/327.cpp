__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    long long sum[10000];
    long long tmp[10000];
    int up, low;
    int solve(int left, int right) { 
        if (left+1 >= right) 
		    return 0;
    	int ans = 0, mid = (left+right)>>1;
        ans += solve(left, mid) + solve(mid, right);
        int p1 = left, p2 = left;
        for (int i = mid; i < right; i++) {
            while (p1 < mid && sum[p1] < sum[i]-up) p1++;
            while (p2 < mid && sum[p2] <= sum[i]-low) p2++;
            ans += p2 - p1;
        }
        merge(sum+left, sum+mid, sum+mid, sum+right, tmp+left);
        for(int i = left; i < right; i++)
            sum[i] = tmp[i];
        return ans;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        up = upper, low = lower;
        sum[0] = 0;
        for (int i = 0; i < n; i++)  
            sum[i+1] = sum[i] + nums[i];
    	return solve(0, n+1);
    }   
};
__________________________________________________________________________________________________
sample 8956 kb submission
class Solution {
public:
    
    /**
     * Bruteforce calculate sum
     */
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int ret = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            int64_t sum = nums[i];
            
            if (sum >= lower && sum <= upper) {
                ++ret;
            }
            
            for (int j = i + 1; j < nums.size(); ++j) {
                sum += nums[j];
                
                if (sum >= lower && sum <= upper) {
                    ++ret;
                }
            }
        }        
        return ret;
    }
};
__________________________________________________________________________________________________
