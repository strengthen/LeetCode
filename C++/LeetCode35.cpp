__________________________________________________________________________________________________
4ms
static const auto io_opt = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); ++i) {
            if (target <= nums[i])
                return i;
        }
        
        return nums.size();
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    int searchInsert(vector<int>& nums, int key) {
        int low=0,high=nums.size()-1;
    int mid=0;
  while(low<=high)
  {
      mid=(low+high)/2;

      if(nums[mid]<key)
      {
          low=mid+1;
      }else
      if(nums[mid]>key)
      {
          high=mid-1;

      }
      else if(nums[mid]==key)
      {
         
          return mid;
      }

  }
  
  return low;  
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int length = nums.size();
        int end = length - 1;
        int median = (begin + end) / 2;
        while(begin <= end){
            if(nums[median] == target){
                return median;
            }
            else if(nums[median] < target){
                begin = median + 1;
            }
            else{
                end = median - 1;
            }
            median = (begin + end) / 2;
        }
        return begin;
    }
};
__________________________________________________________________________________________________
8672 kb
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = (nums.size() - 1);
        int mid = 0;
        
        if(nums.size() == 0)
        {
            return 0;
        }
        
        while(low <= high)
        {
            mid = (low + high) / 2;
            
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }   
        }   
        
        return low;
    }
};

static int x = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();
__________________________________________________________________________________________________
8760 kb
static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (right - left > 1)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target)
            {
                right = mid;
            }
            else if (nums[mid] < target)
            {
                left = mid;
            }
            else
            {
                return mid;
            }
        }
        if (nums[left] == target)
        {
            return left;
        }
        if (nums[right] == target)
        {
            return right;
        }
        if (nums[left] > target)
        {
            return 0;
        }
        if (nums[right] < target)
        {
            return nums.size();
        }
        return right;
    }
};
__________________________________________________________________________________________________