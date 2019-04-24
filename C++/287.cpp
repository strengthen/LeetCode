__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != (i+1))
            {
                
                if(nums[i] == nums[nums[i]-1])
                    return nums[i];
                else
                    swap(nums[i],nums[nums[i]-1]);
            }
        }
          for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != (i+1))
            {
                
                if(nums[i] == nums[nums[i]-1])
                    return nums[i];
                else
                    swap(nums[i],nums[nums[i]-1]);
            }  
        }
        return 0;
    }
};

static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
sample 9584 kb submission
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            
            if (abs(nums[index]) != nums[index])
                return index + 1;
            
            nums[index] *= -1;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << ' ';
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        
        return 1;
    }
};
__________________________________________________________________________________________________
