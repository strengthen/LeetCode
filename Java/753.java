__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    private int n;
    private int k;
    private int groupsize;
    private boolean[] used;
    
    public String crackSafe(int n, int k) {
        this.n = n;
        this.k = k;
        
        groupsize = (int) Math.pow(k, n - 1);
        
        int size = (int) Math.pow(k, n);
        used = new boolean[size];
        
        StringBuilder sb = new StringBuilder();
        helper(sb, 0, size);
        
        for (int i = 0; i < n - 1; i++)
            sb.append("0");
        
        return sb.toString();
    }
    
    private boolean helper(StringBuilder sb, int lastNum, int unused) {
        if (unused == 0)
            return true;
        
        int newNumBase = (lastNum % groupsize) * k;
        
        for (int i = 0; i < k; i++)
        {
            int newNum = newNumBase + i;
            if (used[newNum])
                continue;
            
            used[newNum] = true;
            unused--;
            
            if (helper(sb, newNum, unused))
            {
                sb.append(i);
                return true;
            }
            
            used[newNum] = false;
            unused++;
        }
        
        return false;
    }
}
__________________________________________________________________________________________________
sample 36680 kb submission
class Solution {
    public String crackSafe(int n, int k) {
        int M = (int) Math.pow(k, n-1);
        int[] P = new int[M * k];
        for (int i = 0; i < k; ++i)
            for (int q = 0; q < M; ++q)
                P[i*M + q] = q*k + i;

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < M*k; ++i) {
            int j = i;
            while (P[j] >= 0) {
                ans.append(String.valueOf(j / M));
                int v = P[j];
                P[j] = -1;
                j = v;
            }
        }

        for (int i = 0; i < n-1; ++i)
            ans.append("0");
        return new String(ans);
    }
   
}
__________________________________________________________________________________________________
