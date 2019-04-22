__________________________________________________________________________________________________
4ms
static auto io = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    return nullptr;
}();

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
     int c, g;
     
     int i=0;   
     int s = size(nums);
     int v[s+2][2];
          
     v[0][0] = c = nums[0];
     v[0][1] = g = nums[0];
    
     if (s<=1) return nums[0];   
        
     for(i =1; i<s; i++)
     { 
      v[i][0]= max(nums[i],v[i-1][0]+nums[i]) ;
      c = v[i][0];  
      if(c > g)   g= c;
      
      v[i][1]= g;   
       
     }
        
     return  v[i-1][1];   
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    int maxSubArray(vector<int>& nums) {//前面的要不要的问题
        int res = nums[0];
        int cur = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            cur = max(nums[i], nums[i] + cur);
            if (res < cur) {
                res = cur;
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxsum = INT_MIN;        

        for (int i = 0; i < nums.size(); i++) {
            sum = max(sum + nums[i], nums[i]);
            maxsum = max(maxsum, sum);    
        }
        return maxsum;
    }
};
__________________________________________________________________________________________________
9040 kb
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int max = nums[0];
      int subsum = nums[0];
      for (int i = 1; i < nums.size(); i++) {
        if (subsum < 0) {
          subsum = nums[i];
        } else {
          subsum += nums[i];
        }

        if (subsum > max) max = subsum;
      }

      return max;
    }
};

static const auto fast = []() {
	std::ios::sync_with_stdio( false );
	std::cin.tie( nullptr );
	return nullptr;
}( );
__________________________________________________________________________________________________
9056 kb
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int best = nums[0], sum=0;
        for(int i = 0; i < (int)nums.size(); i++){
            sum = max(nums[i], sum+nums[i]);
            best = max(best, sum);
        }
        return best;
    }
};
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
__________________________________________________________________________________________________