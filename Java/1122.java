__________________________________________________________________________________________________
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        
        int d[] = new int[1001];
        
        int st[] = new int[1001];
        for(int u:arr2){
            st[u]=1;
        }
        
        for(int u:arr1){
            d[u]++;
        }
        
        int res[] = new int[arr1.length];int p = 0;
        for(int u:arr2){
            for(int i=0;i<d[u];++i){
                res[p++] = u;
            }
            d[u] = 0;
        }
        
        for(int i=0;i<=1000;++i){
            for(int j=0;j<d[i];++j){
                res[p++] = i;
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
