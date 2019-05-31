__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
	public boolean isPowerOfTwo(int n) {
		return (n > 0 && (n & (n - 1)) == 0);
	}
}
__________________________________________________________________________________________________
sample 32052 kb submission
class Solution {
    public boolean isPowerOfTwo(int n) {
        long i = 1;
        while(i < n){
            i *= 2;
        }
        
        return i == n;
        
    }
}
__________________________________________________________________________________________________
