__________________________________________________________________________________________________
sample 10 ms submission
class Solution {
    public boolean isPowerOfThree(int n) {
        return ( n>0 &&  1162261467%n==0);
    }
}
__________________________________________________________________________________________________
sample 34036 kb submission
class Solution {
    public boolean isPowerOfThree(int n) {        
        //if(n<3) return false;
        
        while(n>1){
            if(n%3!=0) return false;
            
            n=n/3;
        }
        
        if(n==1) return true;
        
        return false;        
    }
}
__________________________________________________________________________________________________
