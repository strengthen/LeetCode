__________________________________________________________________________________________________
4ms
class Solution {
public:
  static vector<int> searchRange(const vector<int> &nums,const int &target) {
    const auto &lb = std::lower_bound(nums.cbegin(), nums.cend(), target); 
    if (lb == nums.end() || *lb != target) return {-1, -1};
    const auto &ub = std::upper_bound(nums.cbegin(), nums.cend(), target);
    return {int(lb - nums.cbegin()), int(ub - nums.cbegin()) - 1};
  }
};

__attribute__((constructor)) void _() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);
}
__________________________________________________________________________________________________
8ms
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int left = 0, right = nums.size()-1; 
        /* search for left range  */
        int left_idx =0, right_idx =0;
        vector<int> range = {-1, -1};
        if (nums.size() == 0) return range;
        if (nums.size() == 1) {
            if (nums[0] == target) {
                range = {0,0};
            } 
            return range;
        }

        while (left+1 < right) {
            int mid = left + (right -left)/2;
            if ((nums[mid] == target) && ((mid == 0) || nums[mid-1] < target)) {
                range[0] = mid;
                break;
            } else if (nums[mid] < target) {
                left = mid+1;
            }else {
                right = mid;
            }
        }
        if (range[0] == -1) {
            /* target not found */
            if (nums[left] == target) range[0] = left;
            
            else if (nums[right] == target) range[0] = right;
            else return range;                 /* target not present */
        }
        /* */
        left = range[0];
        right = nums.size()-1; // reset the right pointer to 
       // cout << left << "  " << right ;
        while (left+1 < right) {
            int mid = left + (right - left)/2;
            if ((nums[mid] == target) && ((mid == nums.size()-1) || (nums[mid+1] > target))) {
                range[1] = mid;
                break;
            } else if (nums[mid] == target) {
                left = mid;
            } else {
                /* mid is larger than target then move the right pointer to the middle */
                right = mid;
            }
        }
            
        if (range[1] == -1) {
            
            if ((right != range[0]) && (nums[right] == target))               
                range[1] = right;
            else 
                range[1] = range[0];           
        }
        return (range);
        }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx = search(nums, 0, nums.size() - 1, target);
        if (idx == -1) return {-1, -1};
        int left = idx, right = idx;
        while (left > 0 && nums[left - 1] == nums[idx]) --left;
        while (right < nums.size() - 1 && nums[right + 1] == nums[idx]) ++right;
        return {left, right};
    }
    int search(vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) return search(nums, mid + 1, right, target);
        else return search(nums, left, mid - 1, target);
    }
};
__________________________________________________________________________________________________
10352 kb
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size();
        if (right == 0)
        {
            return {-1, -1};
        }
        
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid;
            }
            else
            {
                bool changed = false;
                if (nums[left] < target)
                {
                    ++left;
                    changed = true;
                }
                if (nums[right - 1] > target)
                {
                    --right;
                    changed = true;
                }
                if (!changed)
                {
                    break;
                }
            }
        }
        if (left == right)
        {
            return {-1, -1};
        }
        
        return {left, right - 1};
    }
};

int faster_io = [](){ ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
__________________________________________________________________________________________________
10368 kb
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0 , right = nums.size()-1;
        while(left<right)
        {
            int mid = (left+right)/2;
            if(nums[mid]<target) left = mid+1;
            else right = mid;
        }
        if(nums.empty() || nums[left]!=target) return vector<int>{-1,-1};
        
        int start = left,end = left;
        for (; start >= 0 && nums[start] == target; --start);
	    for (; end < nums.size() && nums[end] == target; ++end);
        
        return vector<int>{start+1,end-1};
    }
};

int faster_io = [](){ ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
__________________________________________________________________________________________________