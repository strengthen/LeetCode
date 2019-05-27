__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        
        int n = barcodes.length;
        int[] cnt = new int[10005];
        int[] ret = new int[n];
        for(int i=0;i<n;++i){
            cnt[ barcodes[i] ]++;
        }
        int mx=0;
        int id =0;
        for(int i=1;i<=10000;++i){
            if(cnt[i]>mx){
                mx=cnt[i];
                id=i;
            }
        }
        int j = 0;
        for(;j<n;j+=2){
            if(cnt[id]>0){
                --cnt[id];
                ret[j] = id;
            }
            else{
                break;
            }
        }
        if(j>=n){
               j=1;
            }
        for(int i=1;i<=10000;++i){
            
            while(cnt[i]>0){
                --cnt[i];
                ret[j]=i;
                j+=2;
                if(j>=n){
                    j=1;
                }
            }
        }
        return ret;
    }
}
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        if(barcodes.length==1)
            return barcodes;
        for (int i = 1; i < barcodes.length; i++) {
          if(barcodes[i]==barcodes[i-1]){
            int j=i+1;
            while ((j<barcodes.length)&&(barcodes[i]==barcodes[j])) {
              j++;
            }
            if(j<barcodes.length){
                int tmp=barcodes[i];
                barcodes[i]=barcodes[j];
                barcodes[j]=tmp;
            }
          }
        }
        for (int i = barcodes.length-1; i >=1; i--) {
          if(barcodes[i]==barcodes[i-1]){
            int j=i-1;
            while ((j>=0)&&(barcodes[i]==barcodes[j])) {
              j--;
            }
            if(j>=0){
                int tmp=barcodes[i-1];
                barcodes[i-1]=barcodes[j];
                barcodes[j]=tmp;
            }
          }
        }
        return barcodes;
    }
}
__________________________________________________________________________________________________
