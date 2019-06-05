__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean validUtf8(int[] data) {
       if(data == null || data.length == 0) {
           return false ;
       } 
       boolean isValid = true ;
       for(int i = 0 ; i < data.length ; i++) {
           if(data[i] > 255) {
               return false ;
           }
           int numberOfBytes = 0 ;
           if((data[i] & 128 )== 0) {
               numberOfBytes = 1 ;
           }
           else if((data[i] & 224) == 192) {
               numberOfBytes = 2 ;
           }
           else if((data[i] & 240) == 224) {
               numberOfBytes = 3 ;
           }
           else if((data[i] & 248) == 240){
               numberOfBytes = 4 ;
           }
           else {
               return false ;
           }
           for(int j = 1 ; j < numberOfBytes ; j++) {
               if(i+j >= data.length) {
                   return false ;
               }
               if((data[i+j] & 192) != 128) {
                   return false ;
               }
           } 
           i += (numberOfBytes-1) ;
       }
       return isValid ;
    }
}
__________________________________________________________________________________________________
sample 38036 kb submission
class Solution {
    public boolean validUtf8(int[] data) {
        if (data == null || data.length == 0) return false;
        
        int cur = 0;
        int n = data.length;
        
        for (int i = 0; i < n; ++i) {
            int d = data[i];
            int c = count(d);
            
            if (cur == 0) {
                if (c == 1 || c > 4)
                    return false;
                cur = Math.max(0, c - 1);
            } else {
                if (c != 1) 
                    return false;
                --cur;
            }
        }
        return cur == 0;
    }
    
    private int count(int d) {
        int mask = 1 << 7;
        int c = 0;
        while ((d & mask) > 0) {
            mask >>= 1;
            ++c;
        }
        return c;
    }
}
__________________________________________________________________________________________________
