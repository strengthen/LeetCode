__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long start = 0, end = 0;
        for(auto num: nums) {
            start = start > num ? start : num;
            end += num;
        }
        while(start + 1 < end) {
            long mid = start + (end - start) / 2;
            long checkR = check(nums, mid);
            if(checkR <= m)
                end = mid;
            else
                start = mid;
        }
        if(check(nums, start) <= m)
            return start;
        else
            return end;
    }
    int check(vector<int>& nums, long m) {
        long sum = 0;
        int cnt = 1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum > m) {
                sum = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};
__________________________________________________________________________________________________
sample 8428 kb submission
class Solution {
public:
    bool ok(vector<int>& nums, int m, long long v){
        long long tmp =0;
        int k = 0;
        for (int i=0; i<nums.size(); ++i) {
            if(tmp+nums[i] > v) {
                tmp = nums[i];
                k++;
                if(k>=m || tmp>v) return false;
            } else tmp += nums[i];
        }
        
        return tmp<=v;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        long long l = nums[0], r=l;
        for(int i=1; i<n; ++i) r+=nums[i];
        while(l<r) {
            long long mid = l+(r-l)/2;
            if(ok(nums, m, mid)) {
                r=mid;
            } else l=mid+1;
            
        }
        return l;
    }
};
__________________________________________________________________________________________________
