__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {        
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        
        for(int num: nums1){
            if(num  > max){
                max = num;
            }
            
            if(num < min){
                min = num;
            }
        }        
        boolean [] check = new boolean[max -min +1];   
        
        for(int num: nums1){
            check[num - min] = true;
        }
        
        int size = 0;
        int [] res = new int[max - min + 1];
        
        for(int num: nums2){
            if(num>=min && num<= max && check[num -min]){
                res[size++] = num;
                check[num-min] = false;
            }
        }
        
        int [] result = new int[size];
        
        for(int i = 0; i < size; i++){
            result[i] = res[i];
        }
        
        return result;
    }
}
__________________________________________________________________________________________________
sample 34508 kb submission
import java.util.*;

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
                if (nums1 == null || nums2 == null || nums1.length == 0 || nums2.length == 0)
            return new int[]{};

        HashSet<Integer> hs = new HashSet<>();
        HashSet<Integer> result = new HashSet<>();

        if (nums1.length < nums2.length)
        {
            for (int i = 0; i < nums1.length; i++)
                hs.add(nums1[i]);
            for (int i = 0; i < nums2.length; i++)
                if (hs.contains(nums2[i]))
                    result.add(nums2[i]);
        }
        else
        {
            for (int i = 0; i < nums1.length; i++)
                hs.add(nums1[i]);
            for (int i = 0; i < nums2.length; i++)
                if (hs.contains(nums2[i]))
                    result.add(nums2[i]);
        }
        int[] toReturn = new int[result.size()];
        int c = 0;
        for (Integer i : result)
            toReturn[c++] = i;
        
        return toReturn;
    }
}
__________________________________________________________________________________________________
