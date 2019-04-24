__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n!=0)
        {
            if((n&1) ==1)
                count+=1;
            n=n>>1;
        }
        return count;
    }
};
__________________________________________________________________________________________________
sample 7852 kb submission
class Solution {
public:
    int hammingWeight(uint32_t n) {
            int res = 0;
    while(n)
    {
        n &= n - 1;
        res++;
    }
    return res;
    }
};
__________________________________________________________________________________________________
