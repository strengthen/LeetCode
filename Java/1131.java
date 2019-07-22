__________________________________________________________________________________________________
class Solution {
    public int maxAbsValExpr(int[] a, int[] b) {
        int n = a.length;
        
        int ans = 0;
        int maxmm = Integer.MIN_VALUE / 2;
        int maxmp = Integer.MIN_VALUE / 2;
        int maxpm = Integer.MIN_VALUE / 2;
        int maxpp = Integer.MIN_VALUE / 2;
        for(int i = 0;i < n;i++){
            maxmm = Math.max(maxmm, -a[i]-b[i]-i);
            maxmp = Math.max(maxmp, -a[i]+b[i]-i);
            maxpm = Math.max(maxpm, a[i]-b[i]-i);
            maxpp = Math.max(maxpp, a[i]+b[i]-i);
            ans = Math.max(ans, maxmm + a[i]+b[i]+i);
            ans = Math.max(ans, maxmp + a[i]-b[i]+i);
            ans = Math.max(ans, maxpm - a[i]+b[i]+i);
            ans = Math.max(ans, maxpp - a[i]-b[i]+i);
        }
        return ans;
    }
}	

__________________________________________________________________________________________________

__________________________________________________________________________________________________
