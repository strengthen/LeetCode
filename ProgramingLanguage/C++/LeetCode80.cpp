__________________________________________________________________________________________________
12ms
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(res<2)
            {
                nums[res++]=nums[i];
                continue;
            }
            if(nums[i]!=nums[res-2])
                nums[res++]=nums[i];
        }
        return res;
    }
};
__________________________________________________________________________________________________
9532 kb
class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        if(n<2) return n;
        int p = 2;
        for(int i=2; i<n; i++){
            if(a[i] == a[p-1] && a[i] == a[p-2]) continue;
            a[p++] = a[i];
        }
        return p;
    }
};
__________________________________________________________________________________________________
