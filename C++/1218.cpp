__________________________________________________________________________________________________
sample 164 ms submission
class Solution {
public:
  int longestSubsequence(vector<int>& arr, int difference) {
    const int n = arr.size();
    unordered_map<int, int> f;
    int ans = 0;
    for (int x : arr) {
      f[x] = f[x - difference] + 1;
      ans = max(ans, f[x]);
    }
    return ans;
  }
};
__________________________________________________________________________________________________
sample 176 ms submission
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> dp; // maximum length end with val is dp[val]
        int ans = 1;
        for(int num : arr) {
            auto it = dp.find(num - diff);
            if (it != dp.end()) {
                dp[num] = max(dp[num], it->second + 1);
            }
            dp[num] = max(dp[num], 1);
        }
        for(auto & p : dp) ans = max(ans, p.second);
        return ans;
    }
};
__________________________________________________________________________________________________
static auto fast=[]{ios_base::sync_with_stdio(false); cin.tie(nullptr);return 0;}();
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) 
    {
        unordered_map<int,int> um;
        int maxlen=0;
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(um.find(arr[i]+diff)!=um.end())
                um[arr[i]]=1+um[arr[i]+diff];
            else
                um[arr[i]]=1;
            if(maxlen<um[arr[i]])
               maxlen=um[arr[i]]; 
        }
        return maxlen;
    }
};
