__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
     public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int i : nums) {
            sum+=i;
        }
        if(sum%2!=0) return false;
        return helper(nums, nums.length-1, sum/2);
    }
    
    private boolean helper(int[] nums, int i, int sum) {
        if(sum == 0) return true;
        
        if(i < 0 || sum < 0 || sum < nums[i]) {
            return false;
        }
        
        
        return helper(nums, i - 1, sum - nums[i]) || helper(nums, i - 1, sum);
        
    }
}
__________________________________________________________________________________________________
sample 34624 kb submission
class Solution {
    public boolean canPartition(int[] nums) {
        if (nums.length < 2) { return false; }

        int sum = IntStream.of(nums).sum();
        if ((sum & 1) == 1) { return false; }

        Map < Integer, Integer > pool = new HashMap < > ();
        for (int num: nums) {
            pool.put(num, pool.getOrDefault(num, 0) + 1);
        }

        Set < Integer > visited = new HashSet < > ();
        return add(0, pool, sum / 2, visited);
    }

    boolean add(int curr, Map < Integer, Integer > pool, int target, Set < Integer > visited) {
        if (curr == target) {
            return true;
        } else if (curr > target) {
            return false;
        }

        List < Integer > list = new ArrayList < > (pool.keySet());
        for (int num: list) {
            if (visited.contains(curr + num)) { continue; }
            visited.add(curr + num);
            
            int count = pool.get(num);
            if (count > 1) {
                pool.put(num, count - 1);
            } else {
                pool.remove(num);
            }
            if (add(curr + num, pool, target, visited)) {
                return true;
            }
            pool.put(num, count);
        }

        return false;
    }
}
__________________________________________________________________________________________________
