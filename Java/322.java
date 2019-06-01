__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        int min = minCoins(coins, amount, coins.length - 1, 0, Integer.MAX_VALUE);
        return min == Integer.MAX_VALUE ? -1 : min;
    }

    private static int minCoins(int[] coins, int amount, int biggestCoinIndex, int count, int currMin) {
        if (biggestCoinIndex < 0) {
            return currMin;
        }
        if (amount % coins[biggestCoinIndex] == 0) {
            return Math.min(currMin, count + amount / coins[biggestCoinIndex]);
        }
        for (int i = amount / coins[biggestCoinIndex]; i >= 0; i--) {
            if (count + i >= currMin - 1) {
                return currMin;
            }
            currMin = minCoins(
                    coins,
                    amount - i * coins[biggestCoinIndex],
                    biggestCoinIndex - 1,
                    count + i,
                    currMin
            );
        }
        return currMin;
    }
}
__________________________________________________________________________________________________
sample 34744 kb submission
class Solution {
    public int coinChange(int[] coins, int amount) {
         int [] result =
                IntStream.range(0, amount + 1).map(e -> Integer.MAX_VALUE).toArray();
        result[0] = 0;

        for (int i = 1; i < result.length; i++) {

            for (int j = 0; j < coins.length; j++) {
               
                if (i >= coins[j]) {
                    int subResult = result[i - coins[j]];
                    if (subResult != Integer.MAX_VALUE
                            && 1 + subResult < result[i]) result[i] = 1 + subResult;
                }

            }
        }

        return result[amount] == Integer.MAX_VALUE ? - 1 : result[amount];
    }
}
__________________________________________________________________________________________________
