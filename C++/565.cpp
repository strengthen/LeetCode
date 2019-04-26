__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                int count = 1;
                int tmp = nums[i];
                nums[i] = -1;
                while (nums[tmp] >= 0) {
                    int ttmp = nums[tmp];
                    nums[tmp] = -1;
                    tmp = ttmp;
                    count++;
                }
                ans = max(count, ans);
            }
        }
        return ans;
    }
};

static int ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
__________________________________________________________________________________________________
sample 9944 kb submission
static const auto fastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
} ();

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        std::vector<bool> visited(nums.size(), false);
        
        int max = 0;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;
            
            int count = 0;
            std::size_t start = i;
            while (!visited[start]) {
                ++count;
                visited[start] = true;
                start = nums[start];
            }
            
            max = std::max(max, count);
        }
        
        return max;
    }
};
__________________________________________________________________________________________________
