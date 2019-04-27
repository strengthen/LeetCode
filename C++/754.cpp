__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int reachNumber(int target) {
        int k = 0;
        target = abs(target);
        
        while (target > 0)
        {
            k++;
            target -= k;
        }
        
        if (target % 2 == 0)
        {
            return k;
        }
        else
        {
            return k + 1 + k%2;
        }
    }
};
__________________________________________________________________________________________________
sample 8416 kb submission
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int step = 0;
        while(target > 0) {
            step += 1;
            target -= step;
        }
        // if step is even, k+1 is odd, addind k+1 changes the result to even
        // if step is odd, k+1 is even, addind k+1 does not change the result 
        return target % 2 == 0 ? step : step + 1 + step % 2;
    }
};
__________________________________________________________________________________________________
