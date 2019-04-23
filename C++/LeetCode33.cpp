__________________________________________________________________________________________________
4ms
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) {
            if (nums[0] == target) return 0;
            return -1;
        }
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            if (target >= nums[l]) {
                if (nums[mid] < nums[l]) {
                    r = mid - 1;
                } else {
                    if (target > nums[mid])
                        l = mid + 1;
                    else
                        r = mid;
                }
            } else {
                if (nums[mid] > nums[r]) {
                    l = mid + 1;
                } else {
                    if (target > nums[mid])
                        l = mid + 1;
                    else
                        r = mid;
                }
            }
        }
        
        if (nums[l] == target) return l;
        if (nums[r] == target) return r;
        return -1;
    }
};
__________________________________________________________________________________________________
4ms
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            } else {
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
   int search(vector<int> &nums, int target)
    {
        int size = static_cast<int>(nums.size());
        if (size < 1)
        {
            return -1;
        }
        int rotate = indexOfMin(nums);
        cout << "rotate is " << rotate << endl;
        int l = 0;
        int r = size - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int rotatedMid = (rotate + mid) % size;
            if (nums.at(rotatedMid) == target)
            {
                return rotatedMid;
            }
            if (nums.at(rotatedMid) > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1;
    }
    
    int indexOfMin(vector<int> nums)
    {
        int l = 0;
        int r = static_cast<int>(nums.size()) - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums.at(mid) > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};
__________________________________________________________________________________________________
8660 kb
class Solution {
public:
    int search(const vector<int>& nums, int target, int lh, int rh) {
        int mid;
        while(lh <= rh){
            mid = (lh+rh)>>1;
            if(nums[mid] == target)
                return mid;
            if(nums[mid]<target){
                lh = mid + 1;
            }else{
                rh = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        if(nums.size()==1) return nums[0]==target?0:-1;
        int i = 0;
        for(; i<nums.size()-1; ++i)
            if(nums[i]>nums[i+1])
                break;
        
        if(nums[0] <= target && target <= nums[i]){
            return search(nums, target, 0, i);
        }else{
            return search(nums, target, i+1, nums.size()-1);
        }
    }
};

static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
8696 kb 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        
        int begin = 0;
        int size = nums.size();
        
        int m;
        int l = 0;
        int r = size - 1;
        while (l <= r) {
            m = (l + r) / 2;
            
            if (nums[l] <= nums[m] && nums[m] <= nums[r]) {
                begin = l;
                break;
            }
            
            if (nums[m] < nums[r])
                r = m;
            else
                l = m + 1;
        }
        
        l = 0;
        r = size - 1;
        while (l <= r) {
            m = (l + r) / 2;
            
            int index = (m + begin) % size;
            if (nums[index] == target)
                return index;
            if (nums[index] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        
        return -1;
    }
};

static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return nullptr;
}();
__________________________________________________________________________________________________
