__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        
        int len1 = nums1.length;
        int len2 = nums2.length;
        int[] result = new int[((len1<len2)? len2 : len1) + 1];
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<len1 && j < len2){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                result[k] = nums1[i];
                k++;
                i++;
                j++;
            }
        }
        return Arrays.copyOfRange(result, 0, k);
    }
}
__________________________________________________________________________________________________
sample 34548 kb submission
import java.util.HashMap;

class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> hashMap = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums1.length; i++){
            if (hashMap.containsKey(nums1[i])){
                hashMap.put(nums1[i], hashMap.get(nums1[i]) + 1);
            }
            else{
                hashMap.put(nums1[i], 1);
            }
        }
        
        int[] arr = new int[10000];
        int count = 0;
        
        for(int i = 0; i < nums2.length; i++){
            if (hashMap.containsKey(nums2[i]) && hashMap.get(nums2[i]) > 0){
                arr[count++] = nums2[i];
                hashMap.put(nums2[i], hashMap.get(nums2[i]) - 1);
                
            }
        }
        
        int[] arr2 = new int[count];
        for(int i =  0; i < count; i++){
            arr2[i] = arr[i];
        }
       return arr2; 
        
    }
}
__________________________________________________________________________________________________
