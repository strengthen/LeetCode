__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean divisorGame(int N) {
        return (N%2==0);
    }
}
__________________________________________________________________________________________________
sample 31560 kb submission
class Solution {
    public boolean divisorGame(int N) {
        if ((N & 1) == 0) return true;
        return false;
    }
}
__________________________________________________________________________________________________
