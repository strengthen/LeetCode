__________________________________________________________________________________________________
4ms
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind=0,n=nums.size();
        for(int i=0;i<n;i++){
            //int&& currJump=i+nums[i];
            if(maxind<i)break;
            maxind=max(maxind,i+nums[i]);
            if(maxind>=n-1)return true;
        }
        return maxind>=n-1;
    }
};
static auto _=[](){ios::sync_with_stdio(false);return 0;}();
__________________________________________________________________________________________________
8ms
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(maxind<i)break;
            maxind=max(maxind,i+nums[i]);
            if(maxind>=n-1)return true;
        }
        return false;
    }
};
static auto _=[](){ios::sync_with_stdio(false);return 0;}();
__________________________________________________________________________________________________
12ms
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if(nums.empty())
        {
            return true;
        }
        
        int dist = 0;
        for(int i = 0; i <= dist; i++)
        {
            dist = std::max(dist, i+nums[i]);
            if(dist >= nums.size()-1)
            {
                return true;
            }
        }
        
        return false;
        
    }
};
__________________________________________________________________________________________________
9656 kb
class Solution {
public:    
    bool canJump(vector<int>& nums) {
        static int fast_io = [](){
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            return 0;
        }();
        int max_reach = 0;
        for (int i = 0; i <= max_reach; i++) {
            // if (max_reach < i) return false;
            if (max_reach >= nums.size() - 1) {
                return true;
            }
            max_reach = max(max_reach, nums[i] + i);
        }
        return false;
    }
};
__________________________________________________________________________________________________
9680 kb
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int e = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; --i)
            if (nums[i] >= e - i)
                e = i;
        return !e;
    }
};

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________