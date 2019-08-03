__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int count = 0;
        int left = 0;
        int right = limit;
        int[] bucket = new int[limit + 1];
        for (int p : people) bucket[p]++;
        
        while (left <= right) {
            while (left <= right && bucket[left] <= 0) left++;
            while (left <= right && bucket[right] <= 0) right--;
            
            if (left > right) {
               break; 
            }
            // if (bucket[left] <= 0 && bucket[right] <= 0) {
            //     break;
            // }
            if (left + right <= limit) {
                bucket[left]--;
            }
            bucket[right]--;
            count++;
        }
        return count;
    }
}
__________________________________________________________________________________________________
sample 47872 kb submission
class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int[] array = new int[limit + 1];
        for(int person: people){
            array[person]++;
        }
        int l = 1, r = limit;
        int ret = 0;
        while(r >= l){
            if(array[l] == 0){
                l++;
            }else if(array[r] == 0){
                r--;
            }else if(r + l <= limit){
                if(r == l){
                    ret += array[r] / 2 + array[r] % 2;
                    break;
                }else{
                    int min = Math.min(array[r], array[l]);
                    array[r] -= min;
                    array[l] -= min;
                    ret += min;
                }
            }else{
                ret += array[r];
                r--;
            }
        }
        return ret;        
    }
}
__________________________________________________________________________________________________
