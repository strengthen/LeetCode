__________________________________________________________________________________________________
4ms
static auto fastio = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findMin(vector<int>& nums) {
        int minVal = nums[0];
        
        int n = nums.size() - nums.size()%4;
        for(int i = 0; i < n; i += 4){
            int a = nums[i+0];
            int b = nums[i+1];
            int c = nums[i+2];
            int d = nums[i+3];
            
            if(b < a)
                a = b;
            if(d < c)
                c = d;
            if(c < a)
                a = c;
            
            if(a < minVal)
                minVal = a;
        }
        
        for(int i = n; i < nums.size(); ++i){
            if(nums[i] < minVal)
                minVal = nums[i];
        }
        
        return minVal;
    }
};
__________________________________________________________________________________________________
8576 kb
class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i = 1; i < nums.size(); ++i)
            if (nums[i] < nums[i-1]) return nums[i];
        return nums[0];
    }
};
__________________________________________________________________________________________________
