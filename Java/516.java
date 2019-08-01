__________________________________________________________________________________________________
sample 6 ms submission
class Solution {
    public int longestPalindromeSubseq(String s) {
        char[] arr = s.toCharArray();
        int[] dp = new int[arr.length];
        
        for(int i=0; i<arr.length; i++) {
            dp[i] = 1;
            int maxPair = 0;
            for(int j=i-1; j>=0; j--) {
                int prev = dp[j];
                if(arr[j] == arr[i]) {
                    dp[j] = maxPair + 2;
                }
                maxPair = Math.max(maxPair, prev);
            }
        }
        int max = 0;
        for(int d : dp) max = Math.max(max, d);
        return max;
    }
}
__________________________________________________________________________________________________
sample 35640 kb submission
class Solution {
    public int longestPalindromeSubseq(String s) {
        if (s.length() == 0){
            return 0;
        }
        int[] dp = new int[s.length()];
        for (int i = s.length() - 1; i >= 0; i--){
            dp[i] = 1;
            int prev = 0;
            for (int j = i + 1; j < s.length(); j++){
                int temp = dp[j];
                if (s.charAt(i) == s.charAt(j)){
                    dp[j] = prev + 2;
                } else {
                    dp[j] = Math.max(dp[j], dp[j - 1]);
                }
                prev = temp;    
            }
        }
        return dp[s.length() - 1];
    }
}
__________________________________________________________________________________________________
