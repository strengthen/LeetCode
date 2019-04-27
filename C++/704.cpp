__________________________________________________________________________________________________
sample 16 ms submission
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int a = 0, b = nums.size();
        if (b == 0) {
            return -1;
        }
        while (true) {
            int m = (a + b) >> 1 ; // ((b - a) >> 1) + a;
            if (a == m) {
                return nums[a] == target ? a : -1;
            }
            if (nums[m] > target) {
                b = m;
            } else {
                a = m;
            }
        }
    }
};
__________________________________________________________________________________________________
sample 10700 kb submission
class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        int r = -1, i = 0, j = nums.size() - 1;

        int m = (j - i) >> 1;

        while (i <= j) {
            if (nums[m] == target) return m;

            if (target > nums[m]) {
                i = ++m;
            }
            else {
                j = --m;
            }

            m = ((j - i) >> 1) + i;
        }

        return r;
    }
};

static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
__________________________________________________________________________________________________
