__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    int res=0;
    public int numDupDigitsAtMostN(int N) {
        res=N;
        int[] x=new int[10];
        int y=N,l=0;
        while(y>0){
            x[l++]=y%10;
            y/=10;
        }
        int[] xx=new int[11];
        xx[0]=1;
        for(int i=1;i<=9;i++)
            xx[i]=xx[i-1]*i;
        int t=9;
        for(int i=0;i<l-1;i++){
            res-=t;
            t=t*(9-i);
        }
        
        boolean[] f=new boolean[10];
        if(x[l-1]>0){
           res-=(x[l-1]-1)*xx[9]/xx[10-l];
        }
        f[x[l-1]]=true;
        t=9;
        boolean ff=false;
        for(int i=l-2;i>=0;i--){
            int tt=0;
            for(int j=0;j<x[i];j++)
                if(!f[j])
                    tt++;
            res-=tt*xx[t-1]/xx[t-1-i];
            if(f[x[i]]){
                ff=true;
                break;
            }
            f[x[i]]=true;
            t--;
        }
        if(!ff) res--;
        return res;
    }
}
__________________________________________________________________________________________________
sample 31920 kb submission
class Solution {
    public int numDupDigitsAtMostN(int N) {
        List<Integer> digits = new ArrayList<>();
        int x = N+1;
        while (x > 0) {
            digits.add(0, x%10);
            x /= 10;
        }
        
        int count = 0, n = digits.size();
        // Count the number with digits < 
        for (int i=1; i<n; i++) {
            count += 9 * nonRepeatedCount(9, i-1);
        }
        
        Set<Integer> set = new HashSet<>();
        // Count the number with same prefix
        for (int i=0; i<n; i++) {
            int d = digits.get(i);

            for (int j=i > 0 ? 0 : 1; j < d; j++) {
                // The digit at i position shouldn't be repeated.
                if (!set.contains(j)) {
                    count += nonRepeatedCount(9-i, n-i-1);    
                }
            }
            
            // N has repeated digits, so don't need to count further.
            if (set.contains(d)) {
                break;
            }
            
            set.add(d);
        }
        
        return N - count;
    }
    
    public int nonRepeatedCount(int m, int n) {
        int rs = 1;
        for (int i=0; i<n; i++) {
            rs *= m;
            m--;
        }
        
        return rs;
    }
}
__________________________________________________________________________________________________
