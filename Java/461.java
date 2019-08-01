__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int hammingDistance(int x, int y) {
        return Integer.bitCount(x^y);
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public static int hammingDistance(int x, int y) {
        int z = x^y;
        String zString = Integer.toBinaryString(z);
        int count = 0;
        for(int i = 0; i < zString.length(); i++)
        {
            if(zString.charAt(i) == '1')
            {
                count++;
            }
        }
        return count;
    }
}
__________________________________________________________________________________________________
sample 31704 kb submission
class Solution {
    public int hammingDistance(int x, int y) {
                int ans = 0;

        int result = x ^ y;

        while (result > 0) {

            result &= (result - 1);

            ans++;

        }
        return ans;
        
    }
}