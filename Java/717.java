__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
         int ones = 0;
        //Starting from one but last, as last one is always 0.
        for (int i = bits.length - 2; i >= 0 && bits[i] != 0 ; i--) { 
            ones++;
        }
        if (ones % 2 > 0) return false; 
        return true;
    }
}
__________________________________________________________________________________________________
sample 37208 kb submission
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int twoCharsStatus = 0;
        for(int i = 0; i < bits.length; i++) {
            
            if(bits[i] == 1) {
                // if(bits.length % 2 == 1)
                //     return true;
                if(twoCharsStatus != 1)
                    twoCharsStatus = 1;
                else
                    twoCharsStatus = 2;
                
            } else {
                if(twoCharsStatus == 1)
                    twoCharsStatus = 2;
                else {
                    twoCharsStatus = 0;
                }
            }
            
        }
        if(twoCharsStatus == 0)
            return true;
        return false;
        
    }
}
__________________________________________________________________________________________________
