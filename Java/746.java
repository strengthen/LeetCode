__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int f1 = 0, f2 = 0;
        for (int i = cost.length - 1; i >= 0; --i) {
            int f0 = cost[i] + Math.min(f1, f2);
            f2 = f1;
            f1 = f0;
        }
        return Math.min(f1, f2);
    }
}
__________________________________________________________________________________________________
sample 37068 kb submission
class Solution {
    public int sum[];
    public int minCostClimbingStairs(int[] cost) {
        sum = new int[cost.length];
        sum[cost.length-1] = cost[cost.length-1];
        sum[cost.length-2] = cost[cost.length-2];
        for(int i=0;i<cost.length-1;i++){
            sum[i]=0;
        }
        calC(cost,0);
        if(sum[0]>sum[1])
            return sum[1];
        else
            return sum[0];
    }
    public int calC(int []cost,int index){
        if(cost.length>index && sum[index]==0){
            int v1= calC(cost,index+1);
            int v2= calC(cost,index+2);
            if(v1>v2){
                sum[index] = v2 + cost[index];
            }else{
                sum[index] = v1 + cost[index];
            }
            return sum[index];
        } else if(cost.length<=index){
            return 0;
        }
        return sum[index];
    }
}
__________________________________________________________________________________________________
