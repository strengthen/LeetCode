__________________________________________________________________________________________________
sample 72 ms submission
static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> v=nums;
        for(auto a:nums)
        {
            v.push_back(a);
        }
        stack<int> s;
        vector<int> ans(n);
        for(int i=2*n-1;i>=0;i--)
        {
           
            while(!s.empty()&&v[s.top()]<=v[i])
            {
                s.pop();
            }
            if(i<=n-1)
            ans[i]=s.empty()?-1:v[s.top()];
            s.push(i);
            
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 12512 kb submission
static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    
    stack<int> stk;
    
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,-1);    
        if(nums.empty()) return res;
        // first pass
        for(size_t i = 0; i < nums.size(); ++i){
            if(!stk.empty() && nums[stk.top()] < nums[i]){
                while(!stk.empty() && nums[stk.top()] < nums[i]){
                    res[stk.top()] = nums[i];
                    stk.pop();
                }
            }
            stk.push(i);
        }
        // second pass
        for(size_t i = 0; i < nums.size(); ++i){
            if(!stk.empty() && nums[stk.top()] < nums[i]){
                while(!stk.empty() && nums[stk.top()] < nums[i]){
                    res[stk.top()] = nums[i];
                    stk.pop();
                }
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
