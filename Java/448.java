__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
         List<Integer> list = new ArrayList<>();

        boolean[] b = new boolean[nums.length + 1];

        for (int i = 0; i < nums.length ; i++) {
            b[nums[i]] = true;
        }

        for (int i = 1; i < b.length; i++) {
            if (!b[i]) {
                list.add(i);
            }
        }
        return list;
    }
}
__________________________________________________________________________________________________
sample 46084 kb submission
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> list = new ArrayList<>();
        if(nums == null || nums.length == 0) {
            return list;
        }
        int res = 0;
        for(int i = 0; i < nums.length; i++) {
            int index = Math.abs(nums[i]) - 1;
            if(nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] > 0) {
                list.add(i+1);
            }
        }
        return list;
    }
}
__________________________________________________________________________________________________
