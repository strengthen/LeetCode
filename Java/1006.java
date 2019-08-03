__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int clumsy(int N) {
        switch (N) {
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 6;
        }
        
        return N * (N - 1) / (N - 2) + N - 3 - helper(N - 4);
    }
    
    private int helper(int n) {
        switch (n) {
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 6;
        }

        return n * (n - 1) / (n - 2) - (n - 3) + helper(n - 4);
    }
}
__________________________________________________________________________________________________
sample 31652 kb submission
class Solution {
    // N*(N-1)/(N-2) + (N-3) - ...
    public int clumsy(final int N) {
        assert N > 0;
        switch (N) {
            case 1:
                return 1;
            case 2:
                return 2 * 1;
            case 3:
                return 3 * 2 / 1;
            default:
                return N * (N-1) / (N-2) + clumsy2(N-3);
        }
    }
    
    // N-(N-1)*(N-2)/(N-3) + ...
    private int clumsy2(final int N) {
        switch (N) {
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 2 - 1;
            case 3:
                return 3 - 2 * 1;
            default:
                return N - (N-1) * (N-2) / (N-3) + clumsy2(N-4);
        }
    }
}
__________________________________________________________________________________________________
