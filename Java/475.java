__________________________________________________________________________________________________
sample 7 ms submission
class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        int i = 0, res = 0;
        for(int h: houses) {
            while(i < heaters.length - 1 && heaters[i] + heaters[i + 1] <= h * 2) i++;
            res = Math.max(res, Math.abs(heaters[i] - h));
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        if(houses == null || heaters == null || houses.length == 0 || heaters.length == 0)
        		return -1;
        Arrays.sort(houses);
        Arrays.sort(heaters);
        
        int max = 0,i = 0;
        
        for(int house : houses) {
        		while(i < heaters.length - 1 && heaters[i] + heaters[i + 1] <= house * 2)
        			i++;
        			max = Math.max(max, Math.abs(house - heaters[i]));
        		}
        
        return max;
    }
}
__________________________________________________________________________________________________
sample 40136 kb submission
public class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        
        int i = 0, res = 0;
        for (int house : houses) {
            while (i < heaters.length - 1 && heaters[i] + heaters[i + 1] <= house * 2) {
                i++;
            }
            res = Math.max(res, Math.abs(heaters[i] - house));
        }
        
        return res;
    }
}