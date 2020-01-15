__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0; i<nums.size(); ++i){
            int c=0;
            while(nums[i]>0){
                nums[i] /= 10;
                c++;
            }
            if(c%2==0) ++count;
        }
        return count;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]>9 && nums[i]<100 || nums[i]>999 && nums[i]<10000 || nums[i]>99999 && nums[i]<1000000)
                ++count;
        }
        return count;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        string s;
        int count=0;
        for(int i = 0; i < nums.size(); i ++)
        {
            s = to_string(nums[i]);
            if (s.length() %2 ==0)
                count++;
        }
        return count;
    }
};