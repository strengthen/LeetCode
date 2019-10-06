__________________________________________________________________________________________________
0ms
class Solution {
    public int minCostToMoveChips(int[] chips) {
        if(chips.length == 0) {
            return 0;
        }
        int even = 0, odd = 0;
        for (int c : chips) {
            if (c % 2 == 1) {
                even++;
            } else {
                odd++;
            }
        }
        return Math.min(even, odd);
    }
}
__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int minCostToMoveChips(int[] chips) {
        int ans = 200;
        for(int target : chips) {
            int temp = 0;
            for(int num : chips) temp += Math.abs(num - target) % 2;
            ans = Math.min(ans, temp);
        }
        return ans;
    }
}
__________________________________________________________________________________________________
