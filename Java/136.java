__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int singleNumber(int[] nums) {
        int x = 0;
        for (int a : nums) {
            x = x ^ a;
        }
        return x;
    }
}
__________________________________________________________________________________________________
sample 35152 kb submission
class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i:nums){
            
            if(!map.containsKey(i)){
                map.put(i,1);
            }
            else{
                map.replace(i, map.get(i)+1);
            }
        }
        int result = 0;
        for(int j:nums){
            if(map.get(j) == 1) result = j;
        }
        
        return result;
    }
}
__________________________________________________________________________________________________
