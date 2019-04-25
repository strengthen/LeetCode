__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool isPowerOfFour(int num) {
        return 0x0 < num && !(num & 0xAAAAAAAA) &&  ((num&(num-1)) == 0);
    }
};
__________________________________________________________________________________________________
sample 7880 kb submission
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0)
            return false;
        while(num % 4 == 0)
        {
            num /= 4;
        }
        return num == 1;
    }
};
__________________________________________________________________________________________________
