__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    Map<Integer, int[]> memo;
    public int[] beautifulArray(int N) {
        memo = new HashMap<>();
        return dfs(N);
    }
    public int[] dfs(int N){
        if (memo.containsKey(N)) return memo.get(N);
        int[] res = new int[N];
        if (N == 1) {
            res[0] = 1;
            return res;
        }
        int index = 0;
        for (int i : dfs((N+1)/2)){
            res[index++] = i*2-1;
        }
        for (int i : dfs(N/2)){
            res[index++] = i*2;
        }
        memo.put(N, res);
        return res;
    }
}
__________________________________________________________________________________________________
sample 33920 kb submission
class Solution {
    Map <Integer, int[]> memo = new HashMap<Integer, int[]>();
    public int[] beautifulArray(int N) {
        return generateArray(N);
    }
    
    public int[] generateArray(int N) {
        if (memo.containsKey(N))
            return memo.get(N);
        
        int[] ans = new int[N];
        if (N==1)
            ans[0] = 1;
        else {
            int t = 0;
            for (int x:generateArray((N+1)/2))
                ans[t++] = 2*x - 1;
            for (int x:generateArray(N/2))
                ans[t++] = 2*x;
        }
        memo.put(N,ans);
        return ans;
    }
}
__________________________________________________________________________________________________
