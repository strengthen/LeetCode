__________________________________________________________________________________________________
sample 28 ms submission
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int maxSubarraySumCircular(const vector<int> &A)
    {
        int dp_min, dp_max, all_min, all_max;
        dp_min = dp_max = all_min = all_max = A[0];
        for (int i = 1, size = A.size(); i < size; ++i) {
            dp_min = A[i] + min(0, dp_min);
            dp_max = A[i] + max(0, dp_max);
            if (dp_min < all_min) all_min = dp_min;
            if (dp_max > all_max) all_max = dp_max;
        }
        return (all_max > 0) ? max(accumulate(A.begin(), A.end(), 0) - all_min, all_max) : all_max;
    }
};
__________________________________________________________________________________________________
sample 12656 kb submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) 
    {
        int max_sum = -30000, min_sum = 30000, cur_max = 0, cur_min = 0, total = 0;
        for(auto& element : A)
        {   
            cur_max = max(0, cur_max) + element;
            cur_min = min(0, cur_min) + element;
            max_sum = max(max_sum, cur_max);
            min_sum = min(min_sum, cur_min);
            total += element;
        }
        if(max_sum < 0)
            return max_sum;
        return max(max_sum, total - min_sum);
    }
};
__________________________________________________________________________________________________
