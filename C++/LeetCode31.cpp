__________________________________________________________________________________________________
8ms
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return; 
        
        for(int i=n-2; i>=0; i--)
        {   
            auto it = upper_bound(nums.begin()+i+1, nums.end(), nums[i]);
            if(it != nums.end())
            {
                swap(nums[i], *it);
                return;
            }
            else rotate(nums.begin()+i, nums.begin()+i+1, nums.end() );                     
        }        
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i, j, n = num.size();
        for (i = n - 2; i >= 0; --i) {
            if (num[i + 1] > num[i]) {
                for (j = n - 1; j > i; --j) {
                    if (num[j] > num[i]) break;
                }
                swap(num[i], num[j]);
                reverse(num.begin() + i + 1, num.end());
                return;
            }
        }
        reverse(num.begin(), num.end());
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return;
        int pos = -1;
        int pos2 = -1;
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                pos = i;
                break;
            }
        }
        //std::cout << " pos"
        if (pos == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] > nums[pos]) {
                pos2 = i;
                break;
            }
        }
        std::cout << " pos: " << pos << " pos2: " << pos2 << std::endl;
        int tmp = nums[pos];
        nums[pos] = nums[pos2];
        nums[pos2] = tmp;
        sort(nums.begin()+pos+1, nums.end());
        return;
    }
};
__________________________________________________________________________________________________

const static auto ioSpeedUp=[](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return NULL;
}();
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1)
            return;
        int iPost = nums.size()-1, iPre=nums.size()-2;
        if(nums[iPost] > nums[iPre] )
        {
            nums[iPost] ^= nums[iPre];
            nums[iPre] ^= nums[iPost];
            nums[iPost] ^= nums[iPre];
            return;
        }
        
        while(iPre>=0 && nums[iPre] >= nums[iPre+1])
            --iPre;
        if(iPre>=0)
        {
            while(nums[iPost] <= nums[iPre])
                --iPost;
            swap(nums[iPost],nums[iPre]);
        }
        reverse(nums.begin()+iPre+1,nums.end());
       return; 
    }
};
__________________________________________________________________________________________________
8756 kb
static auto x = [](){ std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();
class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        const int numsSize = nums.size();
        
        if (numsSize<=1)
        {
            return;
        }
        int prev = nums.back();
        for (int i=numsSize-2; i>=0; --i)
        {
            if (nums[i] < prev)
            {
                int swapIdx = numsSize - 1;
                for (; swapIdx >= 0; --swapIdx)
                {
                    if (nums[i] < nums[swapIdx])
                    {
                        break;
                    }
                }
                std::swap(nums[i], nums[swapIdx]);
                auto begin = nums.begin()+i+1;
                std::reverse(begin, nums.end());
                return;
            }
            prev = nums[i];
        }
        std::reverse(nums.begin(), nums.end());
    }
};
__________________________________________________________________________________________________
