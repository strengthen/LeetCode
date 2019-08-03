__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[] numMovesStones(int a, int b, int c) {
        int min = 0;
        int max = 0;
        
        int x = a;
        int y = b;
        
        if (a > b) {
            x = b;
            y = a;
        }
        int z = c;
        if (c < x) {
            z = y;
            y = x;
            x = c;
        } else if (c < y) {
            z = y;
            y = c;
        }
       // System.out.println(""+ x + y + z)  ;     
        
            max += z-x-2;
            if (y-x == 2 || z-y == 2 || (y-x == 1 && z-y >1) || (z-y == 1 && y-x > 1))
                min = 1;
            else if (y-x >1 || z-y > 1)
                min = 2;
        
        
        return new int[] {min, max};
    }
}
__________________________________________________________________________________________________
sample 32652 kb submission
class Solution {
    public int[] numMovesStones(int a, int b, int c) {
        if(a > b){
        	int temp = a;
        	a = b;
        	b = temp;
        }
        if(a > c){
        	int temp = a;
        	a = c;
        	c = temp;
        }
        if(c < b){
        	int temp = c;
        	c = b;
        	b = temp;
        }
        int maxStep = b - a - 1 + c - b - 1;
        int minStep = 2;
        if(b - a <= 2 || c - b <= 2){
        	minStep = 1;
        }
        if(b - a == 1 && c - b == 1){
        	minStep = 0;
        }
        return new int[]{minStep, maxStep};
    }
}
__________________________________________________________________________________________________
