__________________________________________________________________________________________________
sample 116 ms submission
static const auto fast = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
} ();

class Solution {
public:
    std::vector<int> sumEvenAfterQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        int sum = 0;
        std::vector<int> result(queries.size(), 0);
        
        for (const auto& num : nums) {
            if (num & 1) continue;
            sum += num;
        }
        
        for (ssize_t i = 0; i < queries.size(); ++i) {
            bool first = queries[i][0] % 2 == 0;
            bool second = nums[queries[i][1]] % 2 == 0;
            
            if (first == second) {
                sum += queries[i][0];
                sum += !first ? nums[queries[i][1]] : 0;
            } else {
                sum -= second ? nums[queries[i][1]] : 0;
            }
            
            result[i] = sum;
            nums[queries[i][1]] += queries[i][0];
        }
        
        return result;
    }
};
__________________________________________________________________________________________________
sample 28092 kb submission

static int x=[](){std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}(); // NOLINT

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        for (int x : A) {
            if (x % 2 == 0) {
                sum += x;
            }
        }

        vector<int> ans(queries.size());

        for (int i = 0; i < queries.size(); ++i) {
            int val = queries[i][0];
            int index = queries[i][1];
            if (A[index] % 2 == 0) {
                sum -= A[index];
            }
            A[index] += val;
            if (A[index] % 2 == 0) {
                sum += A[index];
            }
            ans[i] = sum;
        }

        return ans;
    }
};
__________________________________________________________________________________________________
