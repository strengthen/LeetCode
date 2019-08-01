__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String[] findRelativeRanks(int[] nums) {
        String[] result = new String[nums.length];
        int max = 0;
        for (int i : nums) {
            if (i > max) max = i;
        }
        int[] hash = new int[max + 1];
        for (int i = 0; i < nums.length; i++) {
            hash[nums[i]] = i + 1;
        }
        int place = 1;
        for (int i = hash.length - 1; i >= 0; i--) {
            if (hash[i] != 0) {
                if (place == 1) {
                    result[hash[i] - 1] = "Gold Medal";
                } else if (place == 2) {
                    result[hash[i] - 1] = "Silver Medal";
                } else if (place == 3) {
                    result[hash[i] - 1] = "Bronze Medal";
                } else {
                    result[hash[i] - 1] = place + "";
                }
                place++;
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________
sample 37972 kb submission
class Solution {
    public String[] findRelativeRanks(int[] nums) {
        // boundary situations
        if(nums == null) return null;// unnecessary but added this anyways
        // nums.length >= 3, normal situation
        PriorityQueue<Integer> pq = new PriorityQueue<>((i1, i2) -> i2 - i1);
        
        for(int n : nums) pq.offer(n);
        Map<Integer, String> map = new HashMap();
        map.put(pq.poll(), "Gold Medal");
        if(!pq.isEmpty())
            map.put(pq.poll(), "Silver Medal");
        if(!pq.isEmpty())
            map.put(pq.poll(), "Bronze Medal");
        int rank = 4;
        while(!pq.isEmpty())
            map.put(pq.poll(), "" + (rank++));
        String[] strArr = new String[nums.length];
        for(int i = 0; i < nums.length; i++)
            strArr[i] = map.get(nums[i]);
        return strArr;
        
    }
}
__________________________________________________________________________________________________
