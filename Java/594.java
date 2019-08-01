__________________________________________________________________________________________________
sample 15 ms submission
class Solution {
    public int findLHS(int[] nums) {
        if (nums.length == 0) return 0;
        Arrays.sort(nums);
        
        int preCount = 0;
        int cur = nums[0];  
        int curCount = 0;
        int max = 0;
        
        for (int num: nums) {
            if (cur == num) {
                curCount++;
                continue;
            } 
            if (preCount != 0) max =  Math.max(curCount + preCount, max);
            preCount = cur + 1 == num ? curCount : 0;
            cur = num;
            curCount = 1;
        }

        return preCount != 0 ?  Math.max(curCount + preCount, max) : max;
    }
}
__________________________________________________________________________________________________
sample 39516 kb submission
class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : nums) {
            if (map.containsKey(i)) {
                map.put(i, map.get(i) + 1);
            } else {
                map.put(i, 1);
            }
        }
        int result = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int key = entry.getKey();
            if (map.containsKey(key + 1)) {
                result = Math.max(result, entry.getValue() + map.get(key + 1));
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________
