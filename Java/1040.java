__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public int[] numMovesStonesII(int[] stones) {
        Arrays.sort(stones);
        int n = stones.length;
        int high = Math.max(stones[n-2]-stones[0]-n+2,stones[n-1]-stones[1]-n+2);
        int i = 0, low = n;
        for (int j = 0; j < n; ++j) {
            while (stones[j] - stones[i] >= n) ++i;
            if (j - i + 1 == n - 1 && stones[j] - stones[i] == n - 2)
                low = Math.min(low, 2);
            else
                low = Math.min(low, n - (j - i + 1));
        }
        return new int[] {low,high};
    }
}
__________________________________________________________________________________________________
sample 6 ms submission
class Solution {
   public int[] numMovesStonesII(int[] stones) {
        Arrays.sort(stones);
        return new int[]{findMin(stones), findMax(stones)};
    }
    
    int findMin(int[] stones) {
        int n = stones.length;
        int j = 0;
        int min = n;
        for(int i = 0; i < n; ++i) { // first move fast pointer, 
            while(stones[i] - stones[j] +1 > n) j++; // if window is over, move slow pointer
            
            int count = i-j+1;
            if(count == n-1 && stones[i] - stones[j] == n-2) {
                min = Math.min(min, 2);
            }
            else {
                int gapcount = n - count;
                min = Math.min(min, gapcount);                            
            }
        }
        return min;
    }
    
    int findMax(int[] stones) {
        int sum = 0;
        for(int i = 1; i < stones.length; ++i) {
            sum += stones[i] - stones[i-1] - 1;
        }
        int n = stones.length;
        if(n >= 1 && stones[1] != stones[0] + 1) { // single element gap at the beginning
            if(n >= 2 && stones[n-1] != stones[n-2] + 1) { // single element end at the end 
                int gap1 = stones[1] - stones[0]-1;
                int gap2 = stones[n-1] - stones[n-2]-1;
                return sum - Math.min(gap1, gap2);
            }
        }
        return sum;
    }
}
__________________________________________________________________________________________________
sample 7 ms submission
class Solution {
    public int[] numMovesStonesII(int[] stones) {
        Arrays.sort(stones);
        int n = stones.length;
        int max = Math.max(stones[n - 2] - stones[0] - n + 2, stones[n - 1] - stones[1] - n + 2);
        int min = stones.length;
        int i = 0;
        for(int j = 0; j < stones.length; j++){
            while(stones[j] - stones[i] + 1 > n) i++;
            if(j - i + 1 == n - 1 && stones[j] - stones[i] == n - 2){
                min = Math.min(min, 2);
            }else{
                min = Math.min(min, n - (j - i + 1));
            }
        }
        return new int[]{min, max};
    }
}