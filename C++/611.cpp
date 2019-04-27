__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        
        for (auto i = nums.cend(); i != nums.cbegin();) {
            --i;
            auto iv = *i;
            
            auto j = nums.cbegin();
            auto k = i;
            --k;
            while(j < k) {
                if (*j + *k > iv) {
                    res += distance(j, k);
                    --k;
                } else {
                    ++j;
                }
            }
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
sample 9656 kb submission
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        if(nums.size() < 3) {
            return ans;
        }
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; ++ i){
            for(int j = i + 1; j < nums.size() - 1; ++ j){
                ans += getNumOfTriangles(nums[i] + nums[j], j, nums);
            }
        }
        return ans;
    }
    
private:
    int getNumOfTriangles(int upbnd, int start, vector<int>& nums){
        int l = start + 1, r = nums.size() - 1;
        int res = start;
        while(l <= r){
            int mid = (l + r)>>1;
            if(nums[mid] < upbnd){
                res = max(res, mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res - start;
    }
};
__________________________________________________________________________________________________
