__________________________________________________________________________________________________
sample 8 ms submission
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums.back() - nums.front();
        while (l <= r) {
            int cnt = 0;
            int j = 0;
            int m = l + (r - l) / 2;
            for (int i = 0; i < n; ++i) {
                while (j < n && nums[j] - nums[i] <= m) ++j;
                cnt += j - i - 1;
            }
            cnt >= k ? r = m - 1 : l = m + 1;
        }        
        return l;
    }
};
__________________________________________________________________________________________________
sample 9192 kb submission
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0;
        int high = nums[n-1]-nums[0];
        while(low < high){
            int mid = low + (high-low)/2;
            if(check(nums, k, mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
    
    bool check(vector<int>& nums, int k, int mid){
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++){
            int j=i+1;
            for(; j<n; j++){
                if(nums[j]-nums[i]>mid)
                    break;
            }
            count += j-i-1;
            if(count>=k)
                return true;
        }
        return false;
    }
};
__________________________________________________________________________________________________
