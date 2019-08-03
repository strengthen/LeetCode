__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean stoneGame(int[] piles) {
        return true;
    }
}
__________________________________________________________________________________________________
sample 35872 kb submission
class Solution {
    public boolean stoneGame(int[] piles) {
        int sum = Arrays.stream(piles).sum();
        int n = piles.length;
        Boolean[][] memo = new Boolean[n][n];
        return wins(piles, 0, piles.length-1, sum/2, memo);
    }

    static boolean wins(int piles[], int from, int to, int target, Boolean[][] memo) {
        if(memo[from][to] != null) return memo[from][to];
        boolean wins = false;
        if(from == to) {
            if(piles[from] > target) wins = true;
        }else if(from == to-1) {
            wins = Math.max(piles[from], piles[to]) > target;
        }else {
            wins =  wins(piles, from+2, to, target-piles[from], memo) ||
                    wins(piles, from+1, to-1, target-piles[from], memo) ||
                    wins(piles, from, to-2, target-piles[to], memo) ||
                    wins(piles, from+1, to-1, target-piles[to], memo);
        }
        memo[from][to] = wins;
        return wins;
    }
}
__________________________________________________________________________________________________
