__________________________________________________________________________________________________
class Solution {
    public int confusingNumberII(int N) {
        int[] b = {0, 1, 6, 8, 9};
        int[] c = {0, 1, 9, 8, 6};
        
        int ans = 0;
        if(N == 1000000000)ans++;
        for(int d = 1;d <= 9;d++){
            int[] a = new int[d];
            do{
                if(a[0] == 0)continue;
                int or = 0;
                int ro = 0;
                for(int i = 0;i < d;i++){
                    or = or * 10 + b[a[i]];
                }
                for(int i =d-1;i >= 0;i--){
                    ro = ro * 10 + c[a[i]];
                }
                if(or <= N && or != ro){
                    ans++;
                }
            }while(inc(a, 5));
        }
        return ans;
    }
    
    public boolean inc(int[] a, int base) {
        int n = a.length;
        int i;
        for (i = n - 1; i >= 0 && a[i] == base - 1; i--)
            ;
        if (i == -1)
            return false;

        a[i]++;
        Arrays.fill(a, i + 1, n, 0);
        return true;
    }
}

__________________________________________________________________________________________________

__________________________________________________________________________________________________
