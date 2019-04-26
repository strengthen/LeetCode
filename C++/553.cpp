__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string max_helper(vector<int>& nums, vector<vector<int>>& min_trace, vector<vector<int>>& max_trace, int i, int j) {
        if (i+1 == j) return to_string(nums[i]);
        string ans(max_helper(nums, min_trace, max_trace, i, max_trace[i][j]));
        ans.push_back('/');
        if (j - max_trace[i][j] > 1) {
            ans.push_back('(');
            ans += min_helper(nums, min_trace, max_trace, max_trace[i][j], j);
            ans.push_back(')');
        } else {
            ans += min_helper(nums, min_trace, max_trace, max_trace[i][j], j);
        }
        return ans;
    }
    
    string min_helper(vector<int>& nums, vector<vector<int>>& min_trace, vector<vector<int>>& max_trace, int i, int j) {
        if (i+1 == j) return to_string(nums[i]);
        string ans(min_helper(nums, min_trace, max_trace, i, min_trace[i][j]));
        ans.push_back('/');
        if (j - min_trace[i][j] > 1) {
            ans.push_back('(');
            ans += max_helper(nums, min_trace, max_trace, min_trace[i][j], j);
            ans.push_back(')');
        } else {
            ans += max_helper(nums, min_trace, max_trace, min_trace[i][j], j);
        }
        return ans;
    }
    
    string optimalDivision(vector<int>& nums) {
        const int N(nums.size());
        vector<vector<double>> min_q(N+1, vector<double>(N+1));
        vector<vector<double>> max_q(N+1, vector<double>(N+1));
        vector<vector<int>> min_trace(N+1, vector<int>(N+1));
        vector<vector<int>> max_trace(N+1, vector<int>(N+1));
        
        for (int d = 1; d <= N; d++) {
            for (int i(0); i+d<=N; i++) {
                if (d == 1) {
                    min_q[i][i+d] = nums[i];
                    min_trace[i][i+d] = -1;
                    max_q[i][i+d] = nums[i];
                    max_trace[i][i+d] = -1;
                } else {
                    for (int j(i+1); j<i+d; j++) {
                        if (min_q[i][i+d] == 0.0) {
                            min_q[i][i+d] = min_q[i][j] / max_q[j][i+d];
                            min_trace[i][i+d] = j;
                        } else {
                            if (min_q[i][i+d] > min_q[i][j] / max_q[j][i+d]) {
                                min_q[i][i+d] = min_q[i][j] / max_q[j][i+d];
                                min_trace[i][i+d] = j;
                            }
                        }
                        if (max_q[i][i+d] == 0.0) {
                            max_q[i][i+d] = max_q[i][j] / min_q[j][i+d];
                            max_trace[i][i+d] = j;
                        } else {
                            if (max_q[i][i+d] < max_q[i][j] / min_q[j][i+d]) {
                                max_q[i][i+d] = max_q[i][j] / min_q[j][i+d];
                                max_trace[i][i+d] = j;
                            }
                        }
                    }
                }
            }
        }
        return max_helper(nums, min_trace, max_trace, 0, N);
    }
};
__________________________________________________________________________________________________
sample 8676 kb submission
class Solution {
public:
    string optimalDivision(vector<int>& nums) 
    {
        string str = "";
        str.append(to_string(nums[0]));
        
        if (nums.size() > 1)
        {
        
            str.append("/");
            
            if (nums.size() > 2)
            {
                str.append("(");
            }

            for (int i=1; i<nums.size() - 1; i++)
            {
                str.append(to_string(nums[i]));
                str.append("/");
            }

            str.append(to_string(nums[nums.size() - 1]));        
            
            if (nums.size() > 2)
            {
                str.append(")");        
            }
        }
        return str;
    }
};
__________________________________________________________________________________________________
