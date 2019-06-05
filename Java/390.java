__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int lastRemaining(int n) {
        int start = 1, end = n;
        int jump = 1;
        boolean flip = true;
        while (start != end) {
            if (flip) {
                start += jump;
                jump *= 2;
                end -= (end-start)%jump;
            } else {
                end -= jump;
                jump *= 2;
                start += (end-start)%jump;
            }
            flip = !flip;
        }
        
        return start;
    }
}
__________________________________________________________________________________________________
sample 33568 kb submission
class Solution {
    public int lastRemaining(int n) {
        return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
    }
}
__________________________________________________________________________________________________
