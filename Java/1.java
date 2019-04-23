__________________________________________________________________________________________________
2ms
class Solution {
    public int[] twoSum(int[] nums, int target) 
    {
         if(nums==null || nums.length<2)
             return new int[]{0,0};
        
        HashMap<Integer, Integer> hm = new HashMap<>();
        
        for(int i=0; i<nums.length; i++)
        {
            int temp = target-nums[i];
            
            if(hm.containsKey(temp))
            {
                return new int[] {hm.get(temp), i};
            }
            
            hm.put(nums[i], i);
        }
        
        throw new IllegalArgumentException("No two sum solution");
    }
}
__________________________________________________________________________________________________
3ms
 class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        int[] result = new int[2];
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i])){
                result[0] = map.get(target - nums[i]);
                result[1] = i;
            }
            map.put(nums[i], i);
        }
        return result;
    }
}
__________________________________________________________________________________________________
4ms
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) map.put(nums[i], i);
        
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i]) && map.get(target - nums[i]) != i)
                return new int[] {i, map.get(target - nums[i])};
        }
     throw new IllegalArgumentException("No soln");   
    }
}
__________________________________________________________________________________________________
5ms
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] diff = new int[nums.length];
        HashMap<Integer, List<Integer>> vals = new HashMap<Integer, List<Integer>>();
        for(int i=0; i < nums.length; i++){
            diff[i] = target - nums[i];
            if(vals.get(nums[i]) == null){
                vals.put(new Integer(nums[i]), new ArrayList<Integer>());
            }
            
            vals.get(nums[i]).add(i);
        }
        
        for(int i=0; i < nums.length; i++){
            if(vals.get(diff[i]) != null){
                List posVals = vals.get(diff[i]);
                for(int k=0; k<posVals.size(); k++){
                    Integer posIndex = (Integer) posVals.get(k);
                    if(posIndex != i) return new int[]{i, posIndex};
                }
            }
        }
        
        return null;
    }
}
__________________________________________________________________________________________________
34888 kb
class Solution {
    public int[] twoSum(int[] nums, int target) {        
        if(nums.length==0||nums==null)
            return null;        
        Map<Integer,Integer> set = new HashMap<>();
        for(int i=0;i<nums.length;i++)
        {            
            if(set.containsKey(target-nums[i]))
                return new int[]{set.get(target-nums[i]),i};
            else
            {
                set.put(nums[i],i);
            }
        }
        
        return new int[]{};
    }
}
__________________________________________________________________________________________________