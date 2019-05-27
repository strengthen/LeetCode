__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int keepNotGrumpyFrom = 0;
        int curUnsCus = 0;
        int maxUnsCus = 0;

        
        for (int i = 0; i < X; i++) {
            curUnsCus += customers[i] * grumpy[i];
        }
        
        maxUnsCus = curUnsCus;
        
        for (int i = 1, j = X; j < customers.length; i++, j++) {
            int temp = curUnsCus - (customers[i-1] * grumpy[i-1]) + customers[j] * grumpy[j];
            if (temp > maxUnsCus) {
                keepNotGrumpyFrom = i;
                maxUnsCus = temp;
            }
            
            curUnsCus = temp;
        }
        
        for (int i = keepNotGrumpyFrom; i < keepNotGrumpyFrom + X; i++) {
            grumpy[i] = 0;
        }
        
        int maxSat = 0;
        for (int i = 0; i < customers.length; i++) {
            maxSat += customers[i] * (grumpy[i] ^ 1);
        }
        
        return maxSat;
    }
}
__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int left = 0;
        int right = 0;
        int len = customers.length;
        for(int i = 0; i < X; i++) {
            left += customers[i];
        }
        for(int i = X; i < len; i++) {
            if(grumpy[i] == 0) {
                right += customers[i];
            }
        }
        int max = left + right;
        int temp = left + right;
        for(int i = 1; i < len - X + 1; i++) {

            if(grumpy[i - 1] == 1) {
                temp -= customers[i - 1];
            }
            if(grumpy[i + X - 1] == 1) {
                temp += customers[i + X - 1];
            }
            max = Math.max(max, temp);
        }
        return max;
    }
}
__________________________________________________________________________________________________
