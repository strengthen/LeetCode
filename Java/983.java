__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int mincostTickets(int[] days, int[] costs) {
         int[] result = new int[days.length];
         for (int i=0;i<result.length;i++) {
             result[i] = -1;
         }
         return util(days, 0, costs , result);
    }

    private int util(int[] days, int i, int[]  costs, int[] result) {
        if (i>=days.length) {
            return 0;
        }
        if (result[i] != -1) {
            return result[i];
        }
        //1 day cost
        int oneDayCost = costs[0];
        oneDayCost += util(days, i+1, costs, result);

        int sevenDayCost = costs[1];
        int j = i+1;
        while (j < days.length && days[j] < days[i]+7) {
            j++;
        }
        sevenDayCost += util(days, j, costs, result);

        int thirtyDayCost = costs[2];
        j = i+1;
        while (j < days.length && days[j] < days[i]+30) {
            j++;
        }
        thirtyDayCost += util(days, j, costs, result);

        int minCost = Math.min(oneDayCost, Math.min(sevenDayCost, thirtyDayCost));

        result[i] = minCost;
        return minCost;
    }
}
__________________________________________________________________________________________________
sample 35036 kb submission
class Solution {
    public int mincostTickets(int[] days, int[] costs) {

        int[] minCost = new int[366];
        minCost[0] = 0;
        for (int i = 1; i <= 365; i++) {
            final int index = i;
            if (!IntStream.of(days).anyMatch(x -> x == index)) {
                minCost[i] = minCost[i - 1];
                continue;
            }
            
            minCost[i] = Math.min(minCost[i - 1] + costs[0], Math.min((i >= 7 ? minCost[i - 7] : 0 ) + costs[1], (i >= 30 ? minCost[i - 30] : 0 ) + costs[2]));
        }
        return minCost[365];
    }
}
__________________________________________________________________________________________________
