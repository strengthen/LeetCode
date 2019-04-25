__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public:
    int getSum(int a, int b) {
        return b?getSum(a^b, ((a&b)&(0x7FFFFFFF))<<1):a;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution
{
public:
    int getSum(int a, int b)
    {
        if (a == 0)
        {
            return b;
        }
        if (b == 0)
        {
            return a;
        }
        long long carryValue;
        while (b != 0)
        {
            carryValue = a & b;
            a = a ^ b;
            b = ((carryValue & 0xffffffff) << 1);
        }
        return a;
    }
};

__________________________________________________________________________________________________
sample 7928 kb submission
class Solution {
public:
    int getSum(int a, int b) {
        return a+b;
    }
};