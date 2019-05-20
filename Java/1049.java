__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    int res = 0;
    public int lastStoneWeightII(int[] stones) {
        int sum = 0;
        Arrays.sort(stones);
        for(int i=0;i<stones.length;i++){
            sum+=stones[i];
            stones[i]*=2;
        }
        res = sum;
        dfs(stones,0,sum);
        return res;
    }
    
    public void dfs(int[] stones, int index, int sum){
        if(res==0 || res==1) return;
        if(index==stones.length || sum<stones[index]){
            res = Math.min(sum,res);
            return;
        }
        for(int i=index;i<stones.length;i++){
            if(sum>=stones[i]){
                dfs(stones,i+1,sum-stones[i]);
            }else{
                break;
            }
        }
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int lastStoneWeightII(int[] stones) {
        int[] dp = new int[5000];
        dp[0] = 1;
        int sum = 0;
        for (int s: stones) sum += s;
        for (int s: stones) {
            for (int i = sum; i >= 0; i--) if (dp[i] > 0) dp[i+s] = 1;
        }
        int res = sum;
        for (int i = 0; i <= sum; i++) if (dp[i] > 0) {
            res = Math.min(res, Math.abs(sum - i - i));
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int lastStoneWeightII(int[] A) {
        int[] dp = new int[1501];
        dp[0] = 1;
        int sumA = 0, res = 100;
        for (int a : A) {
            sumA += a;
            for (int i = 1500; i >= a; --i)
                dp[i] |= dp[i - a];
        }
        for (int i = 0; i < 1500; ++i)
            res = Math.min(res, Math.abs(sumA - dp[i] * i * 2));
        return res;
    }
}