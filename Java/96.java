__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int numTrees(int n) {
        long c = 1;
        for (int i = 0; i < n; i++) {
            c = c * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)c;
    }
}
__________________________________________________________________________________________________
sample 34168 kb submission
class Solution {
    public int numTrees(int n) {
        if(n<=1) return 1;
        int res[] = new int[n+1];
        res[0] =1;
        res[1] =1;
        
        for(int i=2; i<=n; i++)
            for(int j=1; j<=i; j++)
                res[i]+= res[j-1]*res[i-j];
        return res[n];
    }
}
__________________________________________________________________________________________________
