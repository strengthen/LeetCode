__________________________________________________________________________________________________
sample 12 ms submission
static const int _x_ = [] () { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; } ();

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int first_0_i = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (first_0_i < 0 && nums[i] == 0) {
                first_0_i = i;
            }
            else if (first_0_i >= 0 && nums[i] != 0) {
                swap(nums[first_0_i], nums[i]);
                ++first_0_i;
            }
        }
    }
};
__________________________________________________________________________________________________
sample 9348 kb submission
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        int end  = sz-1;
        for (int i = sz-1; i >= 0; i--) {
            //cout << i <<endl;
            if (nums[i] == 0) { 
                int j = i;
                for (j = i; j < end; j++) {
                    nums[j] = nums[j+1];
                }
                nums[j] = 0;
                end--;
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
};
__________________________________________________________________________________________________
