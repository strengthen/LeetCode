__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool isUgly(int num) {
        if(num == 0)
            return false;
        for(int i = 5; i >= 2; i--)
            while(num % i == 0)
                 num /= i;
        return num == 1;
    }
};
__________________________________________________________________________________________________
sample 7860 kb submission
class Solution {
public:
    bool isUgly(int num) {
        if (num < 1)
            return false;
        for (int i = 2; i < 6; i++) {
            while (num % i == 0)
                num = num / i;
        }
        
        return num == 1;
    }
};
__________________________________________________________________________________________________
