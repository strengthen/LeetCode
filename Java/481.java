__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int magicalString(int n) {
        if(n == 0) return 0;
        if(n < 4) return 1;
       int[] magic = new int[n];
        magic[0] = 1;
        magic[1] = 2;
        magic[2] = 2;
       int oneOrTwo = 1;

       int cnt = 1;
       int idx = 2;
        int r = magic[idx];
       for(int i = 3; i < n; ) {
           while (i < n && r > 0) {
               magic[i++] = oneOrTwo;
               if(oneOrTwo == 1) cnt++;
               r--;
           }
           oneOrTwo = oneOrTwo == 1 ? 2 : 1;
           r = magic[++idx];
       }
        return cnt;      
    }
}
__________________________________________________________________________________________________
sample 32272 kb submission
class Solution {
    public int magicalString(int n) {
        if(n <= 1)
            return n;
        final boolean one = false;
        final boolean two = true;
        boolean[] string = new boolean[n+1];
        string[1] = string[2] = true;
        int size = 3;
        int mapSize = 2;
        int ret = 1;
        boolean oneTurn = true;
        while(size < n){
            if(oneTurn){
                string[size++] = one;
                ret++;
                if(string[mapSize] == two){
                    string[size++] = one;
                    ret++;
                }
            } else {
                string[size++] = two;
                if(string[mapSize] == two)
                    string[size++] = two;
            }
            oneTurn = !oneTurn;
            mapSize++;
        }
        if(size == n+1 && string[size-1] == one)
            return ret - 1;
        return ret;
    }
}
__________________________________________________________________________________________________
