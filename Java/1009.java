__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int bitwiseComplement(int N) {
        int X = 1;
        while (N > X){
            X = X * 2 + 1;
        }
        return X - N;
    }
}
__________________________________________________________________________________________________
sample 31672 kb submission
class Solution {
    public int bitwiseComplement(int N) {
        if(N==0) return 1;
        int r = 0;
        int f = 1;
        while(N!=0){            
            if((N&1)==0){
                r = r + f;
            }                
            f=f<<1;
            N>>=1;
        }
        
        return r;
    }
}
__________________________________________________________________________________________________
