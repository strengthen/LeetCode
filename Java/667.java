__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[] constructArray(int n, int k) {
        int[] result = new int[n];
        
        int index = 0;
        int x = 1, y = k + 1;
        
        while (x <= y) {
            result[index++] = x++;
            if (x < y) {
                result[index++] = y--;
            }
        }
        for (int i = index + 1; i <= n; i++) {
            result[index++] = i;
        }
        return result;
    }
}
__________________________________________________________________________________________________
sample 34432 kb submission
class Solution {
    public int[] constructArray(int n, int k) {
        int[] ret = new int[n];
        int left = 1, right = k + 1, count = 0;
        while(left < right) {
            ret[count ++] = left ++;
            ret[count ++] = right --;
        }
        if(left == right) ret[count ++] = left;
        while(count < n) {
            ret[count] = count + 1;
            count ++;
        }
        return ret;
    }
}
__________________________________________________________________________________________________
