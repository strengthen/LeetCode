__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    /**
     *O(N);该方法比较妙。
     */
    public int canCompleteCircuit(int[] gas, int[] cost) {
        if (gas == null || cost == null || gas.length == 0 || cost.length == 0) return -1;
        int startGasStation = 0, currGas = 0, remindGas = 0;//currGas当前油量；remindGas总共油剩余量
        for (int i = 0; i < gas.length; i++) {//从第一个油站开始加油
            remindGas += gas[i] - cost[i];
            currGas += gas[i] - cost[i];
            if (currGas < 0) {//当前流量小于0
                currGas = 0;
                startGasStation = i + 1;
            }
        }
        return remindGas >= 0 ? startGasStation : -1;
    }
}
__________________________________________________________________________________________________
sample 34436 kb submission
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int[] left_gas = new int[gas.length];
        int sum_gas = 0;
        for (int i = 0; i < gas.length; i++) {
            left_gas[i] = gas[i] - cost[i];
            sum_gas += left_gas[i];
        }
        if (sum_gas < 0) return -1;
        int index = -1;
        int pos_sum_gas = 0;
        int maximum_gas = -1;
        int len = 0;
        for (int i = 0; i < gas.length; i++) {
            pos_sum_gas += left_gas[i];
            if (pos_sum_gas < 0) {
                pos_sum_gas = 0;
                len = 0;
                maximum_gas = 0;
            } else {
                if (pos_sum_gas > maximum_gas) {
                    index = i - len;
                    maximum_gas = pos_sum_gas;
                }
                len++;
            }
        }
        return index;
    }
}
__________________________________________________________________________________________________
