__________________________________________________________________________________________________
sample 0 ms submission
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
       int count =0;
        while(n!=0){
           count+=(n & 0x1);
            n = n>>>1;
            
       } 
        return count;
    }
}
__________________________________________________________________________________________________
sample 31760 kb submission
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count = 0;
        while(n!=0){
            if((n&1) == 1){count++;}
            n = n>>>1; //这里的无符号位移
        }
        return count;
    }
}
__________________________________________________________________________________________________
