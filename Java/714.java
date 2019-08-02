__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    //感觉还是贪心
    //最多是不交易那些达不到标准的
    
    //dp，第i天要么hold，要么sold
    //两个数组，代表第i天为hold或者sold状态
    //hold可以是第i天才买入或者之前就hold。
    //sold可以是第i天才卖或者之前就sold
    
    //还有一个直接每个坡都累加的写法的变种
    //思路是记录最小值
    //如果遇到能盈利，就加上结果。（到这里之前都还和无限制的相同）
    //但是加了盈利之后，min更新的值不能是之前的prices[i]，而是prices[i]-fee，因为fee只交1次，所以min下调来抵消这个fee
    //这个写法实在牛逼
    
    public int maxProfit(int[] prices, int fee) {
        //保证长度最少为1
        int min=prices[0],max=prices[0],result=0;
        
        for(int i=1,length=prices.length;i<length;i++){
            if(min>prices[i])
                min=prices[i];
            else if(prices[i]>fee+min){
                result+=prices[i]-min-fee;
                min=prices[i]-fee;
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________
sample 52456 kb submission
class Solution {
    public int maxProfit(int[] prices, int fee) {
        if (prices == null || prices.length < 2) return 0;
        int[] s0 = new int[prices.length];
        int[] s1 = new int[prices.length];
        int[] s2 = new int[prices.length];
        s1[0] = -prices[0];
        for (int i = 1; i < prices.length; i++) {
            s0[i] = Math.max(s0[i-1], s2[i-1]);
            s1[i] = Math.max(s1[i-1], Math.max(s0[i-1]-prices[i], s2[i-1]-prices[i]));
            s2[i] = s1[i-1] + prices[i] - fee;
        }
        return Math.max(s0[prices.length-1], s2[prices.length-1]);
    }
}
__________________________________________________________________________________________________
