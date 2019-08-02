__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int minSwap(int[] A, int[] B) {
        int swap = 1, keep = 0;
        
        for (int i = 1; i < A.length; i++) {
            if (A[i - 1] >= B[i] || B[i - 1] >= A[i]) {
                swap++;
            }
            else if (A[i - 1] >= A[i] || B[i - 1] >= B[i]) {
                int temp = swap;
                swap = keep + 1;
                keep = temp;
            }
            else {
                int min = Math.min(keep, swap);
                swap = min + 1;
                keep = min;
            }
        }
        
        return Math.min(swap, keep);
    }
}
__________________________________________________________________________________________________
sample 38128 kb submission
class Solution {
    public int minSwap(int[] A, int[] B) {
        memo = new int[A.length][2];
        for (int[] m : memo) {
            Arrays.fill(m, -1);
        }
        return dfs(A, B, 0, 0);
    }
    int memo[][];
    int dfs(int a[], int b[], int pos, int doSwap) {
        if (pos == a.length) {
            return 0;
        }
        if(memo[pos][doSwap] != -1) {
            return memo[pos][doSwap];
        }
        
        int cand1 = Integer.MAX_VALUE;
        int cand2 = Integer.MAX_VALUE;
        if (pos == 0 || a[pos] > a[pos-1] && b[pos] > b[pos-1]) {
            cand1 = dfs(a, b, pos + 1, 0);
        }
        if(pos == 0 || a[pos] > b[pos-1] && b[pos] > a[pos-1]) {
            swap(a, b, pos);
            cand2 = dfs(a,b, pos + 1, 1) + 1;
            swap(a,b,pos);
        }
        
        memo[pos][doSwap] = Math.min(cand1, cand2);
        
        return memo[pos][doSwap];
    }
    public void swap(int[] A,int[] B, int idx){
          int temp=A[idx];
          A[idx]=B[idx];
          B[idx]=temp;
        }    
}
__________________________________________________________________________________________________
