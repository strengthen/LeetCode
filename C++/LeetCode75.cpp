__________________________________________________________________________________________________
4ms
class Solution {
public:
    void swap(vector<int> &nums, int i, int j)
    {
        auto t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = nums.size() - 1;
        while(one <= two)
        {
            if (nums[one] < 1)
            {
                swap(nums, zero++, one++);
            }
            else if (nums[one] == 1)
            {
                one++;
                
            }
            else
            {
                swap(nums, two--, one);
            }
        }
    }
};
__________________________________________________________________________________________________
8352 kb
class Solution {
public:
void sortColors(vector<int>& nums) {
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < nums.size(); i ++) {
        if (nums[i] == 0) {
            count0 ++;
        } else if (nums[i] == 1) {
            count1 ++;
        } else {
            count2 ++;
        }
    }
    const int size = nums.size();
    for (int i = 0; i < size; i ++) {
        if (i < count0) {
            nums[i] = 0;
        } else if (i < count1 + count0) {
            nums[i] = 1;
        } else {
            nums[i] = 2;
        }
    }
}
};
__________________________________________________________________________________________________
