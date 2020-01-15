__________________________________________________________________________________________________
sample 48 ms submission
auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        const int n = nums.size();
        
        int ans = 0;
        int odd = 0;
        vector<int> count (n+1, 0);
        count[0] = 1;
        
        for(int i = 0;i < n; i++)
        {
            odd += nums[i]&1;
            if(odd >= k) {
                ans += count[odd-k];
            }
            
            count[odd]++;
        }

        return ans;
    }

private:
    int next(vector<int>& nums, int idx) {
        idx++;
        while (idx < nums.size() && (nums[idx]&1) == 0) {
            idx++;
        }
        
        return idx;
    }
};
__________________________________________________________________________________________________
sample 52 ms submission
static int accel = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l=0, ans=0;
        for(;l<nums.size()&&(!(nums[l]&1));++l);
        if(l==nums.size())
            return ans;
        int countEvens=l, r=l+1;
        k=k-1;
        for(;r<nums.size()&&k;r++) {
            if(nums[r]&1)
                --k;
        }
        if(r==nums.size())
            return ans;
        ans+=countEvens+1;
        for(;r<nums.size();++r) {
            if(nums[r]&1){
                ++l;
                countEvens=0;
                for(;l<nums.size()&&(nums[l]%2==0);++l)
                    ++countEvens;
                ans+=countEvens+1;
            }
            else {                
                ans+=countEvens+1;
            }
        }
        
        return ans;
    }
};
__________________________________________________________________________________________________
