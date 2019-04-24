__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //方法一，将所有元素往右移动一个单位，重复k次
        //时间复杂度O(n*k),空间复杂度O(1)
        //会遭遇TLE
        /*
        int n = nums.size();
        if(n == 0)
            return;
        for(int i = 0; i < k; i ++){
            int temp = nums[0], cur;
            for(int j = 0; j < nums.size(); j ++){
                cur = nums[(j + 1) % n];
                nums[(j + 1) % n] = temp;
                temp = cur;
            }
        }
        */
        //方法二，将所有元素统一右移动k位
        int n = nums.size();
        k = k % n;
        if(n == 0)
            return;
        vector<int> temp(k,0);
        for(int i = 0; i < k; i ++)
            temp[i] = nums[i];
        for(int i = 0; i < k; i ++){
            int tem = temp[i], cur;
            for(int j = 0; i + j * k < nums.size(); j ++){
                cur = nums[(i + (j + 1) * k) % n];
                nums[(i + (j + 1) * k) % n] = tem;
                tem = cur;
            }
        }
            
        
    }
};
__________________________________________________________________________________________________
sample 9228 kb submission
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        if (k == 0)
            return;
        
        reverseArray(0, size-1, nums);
        reverseArray(0, k-1, nums);
        reverseArray(k, size-1, nums);
    }
    
    void reverseArray(int i, int j, vector<int>& nums)
    {
        int temp;
        while (i<j)
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
};
__________________________________________________________________________________________________
