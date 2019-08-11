__________________________________________________________________________________________________
class MajorityChecker {
    int[] a;
    int[] big;
    int[][] fs;
    int B;

    public MajorityChecker(int[] a) {
        this.a = a;
        int n = a.length;
        B = (int)Math.sqrt(n);
        int[] f = new int[20001];
        for(int v : a){
            f[v]++;
        }
        int[] bigger = new int[n];
        int p = 0;
        for(int i = 1;i <= 20000;i++){
            if(f[i] >= B){
                bigger[p++] = i;
            }
        }
        big = Arrays.copyOf(bigger, p);
        
        fs = new int[p][n+1];
        for(int i = 0;i < p;i++){
            for(int j = 0;j < n;j++){
                if(a[j] == big[i]){
                    fs[i][j+1] = fs[i][j] + 1;
                }else{
                    fs[i][j+1] = fs[i][j];
                }
            }
        }
    }
    
    public int query(int left, int right, int threshold) {
        if(right - left + 1 <= 2*B){
            int best = -1, f = 0;
            for(int i = left;i <= right;i++){
                if(best == a[i]){
                    f++;
                }else if(f == 0){
                    best = a[i];
                }else{
                    f--;
                }
            }
            int ct = 0;
            for(int i = left;i <= right;i++){
                if(a[i] == best){
                    ct++;
                }
            }
            return ct >= threshold ? best : -1;
        }else{
            for(int i = 0;i < big.length;i++){
                int ff = fs[i][right+1] - fs[i][left];
                if(ff >= threshold)return big[i];
            }
            return -1;
        }
    }
}	
__________________________________________________________________________________________________

__________________________________________________________________________________________________
