__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        for(int i=0; i<flowerbed.length; i++){
            if(n==0)
                return true;
            if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) 
               && (i==flowerbed.length-1 || flowerbed[i+1]==0)){
                n--;
                flowerbed[i] = 1;
            }
        }
        return n==0;
    }
}
__________________________________________________________________________________________________
sample 37184 kb submission
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        markUnplant(flowerbed);
        Arrays.stream(flowerbed).forEach(System.out::print);
        for (int i = 0; i < flowerbed.length; i++) {
            if (flowerbed[i] == 0) {
                flowerbed[i++] = 1;
                n--;
            }
        }
        return n <= 0;
    }
    
    private void markUnplant(int[] flowerbed) {
        for (int i = 0; i < flowerbed.length; i++) {
            if (flowerbed[i] == 1) {
                markUnplant(i++, flowerbed);
            }
        }
    }
    
    private void markUnplant(int pos, int[] flowerbed) {
        if (isValid(pos - 1, flowerbed)) flowerbed[pos - 1] = 1;
        if (isValid(pos + 1, flowerbed)) flowerbed[pos + 1] = 1;
    }
    
    private boolean isValid(int pos, int[] flowerbed) {
        return pos >= 0 && pos < flowerbed.length;
    }
}
__________________________________________________________________________________________________
