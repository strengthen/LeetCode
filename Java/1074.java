__________________________________________________________________________________________________
class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {

        int m = matrix.length;
        int n = matrix[0].length;

        int[] temp = new int[m];
        int ans=0;
        for (int left = 0;left<n;left++) {
            Arrays.fill(temp,0);
            for (int right=left;right<n;right++) {
                for (int i=0;i<m;i++) {
                    temp[i]+=matrix[i][right];
                }
                ans+= subCount(temp,target);
            }
        }
        return ans;
    }

    private int subCount(int[] temp,int target) {
        HashMap<Integer, Integer> prevSum = new HashMap<>();

        int res = 0;
        int currentSum = 0;

        for (int t : temp) {

            currentSum += t;
            if (currentSum == target) {
                res++;
            }
            if (prevSum.containsKey(currentSum - target)) {
                res += prevSum.get(currentSum - target);
            }
            prevSum.merge(currentSum, 1, (a, b) -> a + b);
        }

        return res;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
