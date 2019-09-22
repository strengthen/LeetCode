__________________________________________________________________________________________________
108ms
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
       
        if (arr.empty()) return {};
        
        vector<vector<int>> res;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int lo = INT_MAX, cur;

        for (int i = 0; i + 1 < n; ++i) {
            cur = arr[i+1] - arr[i];
            if (cur < lo && cur > 0) {
                lo = cur;
                res = {{arr[i], arr[i+1]}};
            } else if (cur == lo) {
                res.push_back({arr[i], arr[i+1]});
            } else {}
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 116 ms submission
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();
        int mi = 1e7;
        for(int i = 1;i < n;++i) {
            mi = min(mi, A[i] - A[i - 1]);
        }
        
        vector < vector < int > > ans;
        for(int i = 1;i < n;++i) {
            if(A[i] - A[i - 1] == mi) {
                ans.push_back({A[i - 1], A[i]});
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
