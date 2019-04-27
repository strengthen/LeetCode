__________________________________________________________________________________________________
sample 16 ms submission
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int s = 0;
        for (int i = 0; i < k; ++i)
            s += nums[i];
        
        vector<int> ss;
        ss.push_back(s);
        for (int i = k; i < nums.size(); ++i) {
            ss.push_back(ss.back() + nums[i] - nums[i - k]);
        }
        
        vector<vector<int>> rr;
        rr.emplace_back(ss.size() - 2 * k, 0);
        for (int i = 1; i <= 3; ++i) {
            rr.emplace_back();
            vector<int> & r = rr.back();
            
            int rmax = 0;
            for (int j = 0; j < ss.size() - 2 * k; ++j) {
                if (ss[j + (i - 1) * k] + rr[i - 1][j] > rmax)
                    rmax = ss[j + (i - 1) * k] + rr[i - 1][j];
                r.push_back(rmax);
            }
        }
        
        vector<int> result(3, 0);
        int max = rr[3].back();
        for (int i = 2; i >= 0; --i) {
            int pos = std::lower_bound(rr[i + 1].begin(), rr[i + 1].end(), max) - rr[i + 1].begin() + k * i;
            result[i] = pos;
            max -= ss[pos];
        }

        return result;
    }
};
__________________________________________________________________________________________________
sample 10864 kb submission
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        if (nums.size()<3)
            return vector<int>();
        int sum3 = 0;
        int len = nums.size()-k+1;
        int subsum[len] = {};
        for (int i = 0; i < nums.size(); i++){
            sum3 += nums[i];
            if (i >= k)
                sum3 -= nums[i-k];
            if (i >= k-1)
                subsum[i-k+1] = sum3;
        }
        int best = 0;
        int left[len];
        for (int i = 0; i < len; i++){
            if (subsum[i] > subsum[best])
                best = i;
            left[i] = best;
        }
        best = len-1;
        int right[len];
        for (int i = len-1; i >= 0; i--){
            if (subsum[i] >= subsum[best])
                best = i;
            right[i] = best;
        }
        vector<int> ans = {-1, -1, -1};
        for (int j = k; j < len - k; j++){
            int l = left[j-k];
            int r = right[j+k];
            if (ans[0] == -1 || subsum[ans[0]] + subsum[ans[1]] + subsum[ans[2]] < subsum[l] + subsum[r] + subsum[j]){
                ans[0] = l;
                ans[1] = j;
                ans[2] = r;
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
