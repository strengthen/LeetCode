__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public int distributeCandies(int[] candies) {
        int maxNum = candies.length >> 1;
        boolean[] exists = new boolean[200001];
        int uniqueNum = 0;
        for(int candy : candies){
        	if(!exists[candy + 100000]){
        		exists[candy + 100000] = true;
        		if(++uniqueNum == maxNum){
        			return maxNum;
        		}
        	}
        }
        return uniqueNum;
    }
}
__________________________________________________________________________________________________
sample 39816 kb submission
class Solution {
    public int distributeCandies(int[] candies) {
        int candyCount = 1; 
        int ptr=0;
        for (int x=0; x<candies.length-1; x++) {
            int min = x;
            for (int y=x+1; y<candies.length; y++) {
                if (candies[y]<candies[min]) {
                    min = y;
                }
            }
            int temp= candies[x];
            candies[x] = candies[min];
            candies[min] = temp;
        } 
        for (int k=0; k<candies.length-1; k++) {
            if (candies[k] != candies[k+1]) {
                ptr=k+1;
                candyCount++;
            }
        }
        
        return Math.min(candyCount, candies.length/2);
    }
}
__________________________________________________________________________________________________
