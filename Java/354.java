__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        if(envelopes == null || envelopes.length == 0  || envelopes[0] == null || envelopes[0].length != 2)
        return 0;
        
        Arrays.sort(envelopes, new Comparator<int[]>(){
           public int compare(int[] e1, int[] e2) {
               return (e1[0] == e2[0]) ? - e1[1] + e2[1] : e1[0] - e2[0];
           } 
        });
        
        int n = envelopes.length;
        int[] tail = new int[n];
        int count = 0;
        for (int[] item: envelopes) {
            int index = Arrays.binarySearch(tail, 0, count, item[1]);
            if (index < 0) {
                index = - index - 1;
            }
            tail[index] = item[1];
            if (index == count) {
                count ++;
            }
        }
        return count;
    }
}
__________________________________________________________________________________________________
sample 43156 kb submission
class Solution {
    public int maxEnvelopes(int[][] env) {
        Arrays.sort(env, (a, b) -> (a[0] - b[0] == 0 ? b[1] - a[1] : a[0] - b[0]));

        int n = env.length;
        int[] dp = new int[n];
        int len = 0;
        for(int i = 0; i < n; i++) {
            int pos = binarySearch(dp, 0, len - 1, env[i][1]);
            dp[pos] = env[i][1];
            if(pos == len) len++;
        }
        return len;
    }
    
    private int binarySearch(int[] dp, int l, int r, int t) {
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(dp[mid] < t) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return dp[l] >= t ? l : r + 1;
    }
}
__________________________________________________________________________________________________
