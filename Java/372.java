__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int superPow(int a, int[] b) {
        if(a%1337==0) {
        	return 0;
        }
        int p = 0;
        for(int i=0;i<b.length;i++) {
        	p = (p * 10 + b[i])%1140;
        }
        if(p==0) {
        	p = 1140;
        }
        return power(a, p, 1337);
    }
    int power(int a, int p, int mod) {
    	a = a % mod;
    	int res = 1;
    	while(p!=0) {
    		if((p&1)!=0) {
    			res = (res * a)%mod;
    		}
    		a = (a * a)%mod;
    		p = p>>1;
    	}
    	return res;
    }
}
__________________________________________________________________________________________________
sample 34676 kb submission
class Solution {
    public int superPow(int a, int[] b) {
        int idx=b.length;
        return helper(a,b, idx-1);
    }
    public int base=1337;
    public int helper(int a,int[] b,int idx){
        
        if(idx<0) return 1;
        return mod(helper(a,b,idx-1),10)  * mod(a,b[idx])%base;
    }
    
    public int mod(int a,int b){
        int res=1;
        a=a%base;
        for(int i=0;i<b;i++)
            res=    res* a % base;
        return res;
    }
}
__________________________________________________________________________________________________
