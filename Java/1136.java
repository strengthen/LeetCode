__________________________________________________________________________________________________
class Solution {
    public int minimumSemesters(int N, int[][] relations) {
        int m = relations.length;
        int[] from = new int[m];
        int[] to = new int[m];
        for(int i = 0;i < m;i++){
            from[i] = relations[i][0]-1;
            to[i] = relations[i][1]-1;
        }
        
        int n = N;
        int[][] g = packD(n, from, to);
        int[] ord = sortTopologically(g);
        if(ord == null){
            return -1;
        }
        int[][] ig = packD(n, to, from);
        int[] dp = new int[n];
        int ret = 0;
        for(int i = 0;i < n;i++){
            int cur = ord[i];
            dp[cur] = 1;
            for(int e : ig[cur]){
                dp[cur] = Math.max(dp[cur], dp[e] + 1);
            }
            ret = Math.max(ret, dp[cur]);
        }
        return ret;
    }
    
    public int[] sortTopologically(int[][] g)
    {
        int n = g.length;
        int[] ec = new int[n];
        for(int i = 0;i < n;i++){
            for(int to : g[i])ec[to]++;
        }
        int[] ret = new int[n];
        int q = 0;
        
        // sources
        for(int i = 0;i < n;i++){
            if(ec[i] == 0)ret[q++] = i;
        }
        
        for(int p = 0;p < q;p++){
            for(int to : g[ret[p]]){
                if(--ec[to] == 0)ret[q++] = to;
            }
        }
        // loop
        for(int i = 0;i < n;i++){
            if(ec[i] > 0)return null;
        }
        return ret;
    }

    
    int[][] packD(int n, int[] from, int[] to) {
        int[][] g = new int[n][];
        int[] p = new int[n];
        for (int f : from)
            p[f]++;
        for (int i = 0; i < n; i++)
            g[i] = new int[p[i]];
        for (int i = 0; i < from.length; i++) {
            g[from[i]][--p[from[i]]] = to[i];
        }
        return g;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
