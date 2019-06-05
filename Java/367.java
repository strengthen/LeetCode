__________________________________________________________________________________________________
sample 0 ms submission
/*
 * @lc app=leetcode id=367 lang=java
 *
 * [367] Valid Perfect Square
 */
class Solution {
    public boolean isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }

        long start = 1, end = num;
        while (start < end - 1) {
            long middle = start + (end - start) / 2;
            long temp = middle * middle;
            if (temp == (long)num) {
                return true;
            } else if (temp > (long)num) {
                end = middle;
            } else {
                start = middle;
            }
        }
        return start * start == num || end * end == num;
    }
}

__________________________________________________________________________________________________
sample 31424 kb submission
class Solution {
    public boolean isPerfectSquare(int num) {
        int low=1, high=num, mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(num/mid < mid){
                high=mid-1;
            }
            else{
                if(mid*mid==num){
                    return true;
                }
                low=mid+1;
            }
        }
        return false;
    }
}
__________________________________________________________________________________________________
