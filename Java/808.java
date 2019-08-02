__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public double soupServings(int N) {
        if (N > 4800) {
            return 1;
        }
        
        int servings = N % 25 == 0 ? N/25 : N/25+1;
        return helper(servings, servings, new double[servings+1][servings+1]);
    }
    
    private double helper(int a, int b, double[][] memo) {
        if (a <= 0 && b <= 0) {
            return 0.5;
        }
        
        if (a <= 0) {
            return 1;
        }
        
        if (b <= 0) {
            return 0;
        }
        
        if (memo[a][b] > 0) {
            return memo[a][b];
        }
        
        double p = 0;
        for (int i=1; i<=4; i++) {
            p += 0.25 * helper(a-i, b-(4-i), memo);
        }
        
        memo[a][b] = p;
        return p;
    }
}
__________________________________________________________________________________________________
sample 32228 kb submission
class Solution {
    static double[][] memo = new double[200][200];
    public double soupServings(int N) {
        return N >= 4800 ?  1.0 : f((N + 24) / 25, (N + 24) / 25);
    }

    public double f(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1;
        if (b <= 0) return 0;
        if (memo[a][b] > 0) return memo[a][b];
        memo[a][b] = 0.25 * (f(a - 4, b) + f(a - 3, b - 1) + f(a - 2, b - 2) + f(a - 1, b - 3));
        return memo[a][b];
    }
}

__________________________________________________________________________________________________
