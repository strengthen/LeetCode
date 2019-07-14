__________________________________________________________________________________________________
class Solution {
    public int longestWPI(int[] hs) {
        
        int l = hs.length;
        
        int s[] = new int[l+1];
        
        for(int i=0;i<l;++i){
            s[i+1] = s[i]+((hs[i]>8)?1:0);
            //System.out.println(hs[i]);
        }
        int res = 0;
        for(int i=0;i<l;++i){
            for(int j=i;j<l;++j){
                int tot = j-i+1;
                 if(tot<=res){
                     continue;
                 }
                int lao = s[j+1]-s[i];
                if(lao>tot-lao){
                    res = Math.max(res,tot);
                }
            }
        }
        return res;
        
    }
}

__________________________________________________________________________________________________

__________________________________________________________________________________________________
