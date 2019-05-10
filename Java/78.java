__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res=new ArrayList<>();
        if(nums.length==0 || nums==null) return res;
        helper(nums, res, new ArrayList<>(), 0);
        return res;
    }
    
    private void helper(int[] nums, List<List<Integer>> res, List<Integer> list, int index){
        res.add(new ArrayList<Integer>(list));
        for(int i=index; i<nums.length; i++){
            int num=nums[i];
            list.add(num);
            helper(nums, res, list, i+1);
            list.remove(list.size()-1);
        }
    }
}
__________________________________________________________________________________________________
sample 34488 kb submission
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        findSubsets(nums, result, new ArrayList<>(), 0);
        return result;
    }
    
    private void findSubsets(int[] nums, List<List<Integer>> result, List<Integer> tempList, int start){
        result.add(new ArrayList<>(tempList));
        
        for(int i=start; i<nums.length; i++){
            tempList.add(nums[i]);
            findSubsets(nums, result, tempList, i+1);
            tempList.remove(tempList.size()-1);
        }
    }
}
__________________________________________________________________________________________________
