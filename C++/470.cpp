__________________________________________________________________________________________________
sample 68 ms submission
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int d = 40;
        while(d >= 40)
        {
            d = 7 * (rand7() - 1) + (rand7() - 1);
        }
        return d%10 + 1;
    }
};
__________________________________________________________________________________________________
sample 9524 kb submission
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (true) {
            int res = 7 * (rand7() - 1) + rand7();
            if (res <= 40) {
                return  1 + (res - 1) % 10; 
            }
        }
    }
};
__________________________________________________________________________________________________
