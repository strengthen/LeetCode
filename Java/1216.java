__________________________________________________________________________________________________
13ms
class Solution {
    public boolean isValidPalindrome(String s, int k)
    {
        StringBuilder sb= new StringBuilder(s);
        sb.reverse();
        return (helper(s, sb.toString(),s.length(), sb.length()) <= k*2);
    }
    
    public int helper(String a, String b, int alen, int blen)
    {
        int[][] dp= new int[alen+1][blen+1];
        for(int i=0;i<=alen;i++)
            for(int j=0;j<=blen;j++)
            {
                if(i==0)
                    dp[i][j]= j;
                else if(j==0)
                    dp[i][j]= i;
                else if(a.charAt(i-1)==b.charAt(j-1))
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]= Math.min(dp[i-1][j],dp[i][j-1])+1;
            }
        return dp[alen][blen];
    } 
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
