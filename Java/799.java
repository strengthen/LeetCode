__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        double[] flow = new double[query_row + 1];
        
        flow[0] = poured;
        if (query_row == 0) {
            return flow[0] >= 1 ? 1 : 0;
        }
        
        for (int i = 1; i <= query_row; i++) {
            for (int j = i; j >= 0; j--) {
                if (j == 0) {
                    flow[j] = (flow[j] - 1 >= 0 ? flow[j] - 1 : 0) / 2.0;
                }
                else if (j == i) {
                    flow[j] = (flow[j - 1] - 1 >= 0 ? flow[j - 1] - 1 : 0) / 2.0;
                }
                else {
                    flow[j] = ((flow[j] - 1 >= 0 ? flow[j] - 1 : 0) + (flow[j - 1] - 1 >= 0 ? flow[j - 1] - 1 : 0)) / 2.0;
                }
                
                if (i == query_row && j == query_glass) {
                    return flow[j] >= 1 ? 1 : flow[j];
                }
            }
        }
        
        return 0;
    }
}
__________________________________________________________________________________________________
sample 32340 kb submission
class Solution {
    public double champagneTower(int poured, int row, int glass) {
        double[] current = new double[row + 1];
        current[0] = poured;
        for (int i = 1; i <= row; i++) {
            for (int j = i; j > 0; j--) {
                current[j] = (Math.max(current[j - 1] - 1, 0) + Math.max(current[j] - 1, 0)) / 2.0;
            }
            current[0] = Math.max(current[0] - 1, 0) / 2.0;
        }
        return Math.min(current[glass], 1);
    }
}
__________________________________________________________________________________________________
