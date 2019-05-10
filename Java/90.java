__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> sr = new ArrayList<Integer>();
        Arrays.sort(nums);
        helper(result,sr,nums,0);
        return result;
    }
    
    public void helper(List<List<Integer>> result, List<Integer> sr, int[] nums, int level){
        result.add(sr);
        for(int i=level;i<nums.length;++i){
            sr.add(nums[i]);
            helper(result,new ArrayList(sr),nums,i+1);
            sr.remove(sr.size()-1);
            while(i+1<nums.length&&nums[i]==nums[i+1])i++;
        }
    }
}
__________________________________________________________________________________________________
sample 34828 kb submission
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(nums);
        backtrack(list, new ArrayList<>(), nums, 0);
        return list;
    }
    
    private void backtrack(List<List<Integer>> list, List<Integer> tempList, int[] nums, int start) {
        list.add(new ArrayList<>(tempList));
        for (int i = start; i < nums.length; i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;//skip duplicate
            tempList.add(nums[i]);
            backtrack(list, tempList, nums, i + 1);
            tempList.remove(tempList.size() - 1);
        }
    }
}
__________________________________________________________________________________________________
