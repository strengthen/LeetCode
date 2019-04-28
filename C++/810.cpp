__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    bool xorGame(vector<int>& nums) {
     
        return accumulate(nums.begin(),nums.end(),0,std::bit_xor<int>())==0||nums.size()%2==0;
    }
};
__________________________________________________________________________________________________
sample 9728 kb submission
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int Xor = 0, n = nums.size();
        for(int i=0; i<n; i++)
            Xor ^= nums[i];
        return (Xor == 0 || n%2 == 0);
    }
};
__________________________________________________________________________________________________
