__________________________________________________________________________________________________
4ms
static const auto speedup = []() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();
class Solution {
public:
    bool search(const vector<int>& nums, int target) {
        int m = 0, l = 0, h = nums.size() - 1;
        
        while (l <= h) {
            m = (l + h)/2;
            
            if (nums[m] == target)
                return true;
            
            if (nums[m] > nums[l]) {
                if (nums[l] <= target && target < nums[m]) 
                    h = m;
                else
                    l = m + 1;
            }
            else if (nums[m] < nums[l]){
                if (nums[m] < target && target <= nums[h])
                    l = m + 1;
                else
                    h = m ;
            }
            else 
                l++;
        }
        return false;
    }
};
__________________________________________________________________________________________________
8472 kb
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
            else if (nums[mid] > nums[right]) {
                if (nums[mid] > target && nums[left] <= target) right = mid - 1;
                else left = mid + 1;
            }
            else --right;            
        }
        return false;
    }
};
__________________________________________________________________________________________________
