__________________________________________________________________________________________________
0ms
class Solution {
    List<List<Integer>> result;
    public List<List<Integer>> permute(int[] nums) {
        result = new ArrayList<>();
        permuteHelper(0, nums.length - 1, nums);
        return result;
    }
    
    public void permuteHelper(int left, int right, int[] currentNums) {
        if(left == right) {
            List<Integer> perm = new ArrayList<Integer>();
            for(int n : currentNums) {
                perm.add(n);
            }
            result.add(perm);
        }
        for(int i = left; i <= right; i++) {
            currentNums = swap(currentNums, left, i);
            permuteHelper(left+1, right, currentNums);
            currentNums = swap(currentNums, left, i);
        }
    }
    public int[] swap(int[] currentNums, int i, int j) {
        int temp = currentNums[i];
        currentNums[i] = currentNums[j];
        currentNums[j] = temp;
        return currentNums;
    }
}
__________________________________________________________________________________________________
1ms
class Solution {
    List<List<Integer>> list = new ArrayList<>();
    List<Integer> temp = new ArrayList<>();
    boolean[] vis;
    public List<List<Integer>> permute(int[] nums) {
        if (null == nums || 0 == nums.length) {
            return list;
        }
        vis = new boolean[nums.length];
        dfs(nums, 0);
        return list;
    }
    public void dfs(int[] nums, int index) {
        if (index == nums.length) {
            list.add(new ArrayList<>(temp));
            return ;
        }
        for (int i = 0; i < nums.length; i++) {
            if (!vis[i]) {
                vis[i] = true;
                temp.add(nums[i]);
                dfs(nums, index + 1);
                vis[i] = false;
                temp.remove(temp.size() - 1);
            }
        }
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        backtrack(res, new ArrayList<>(), nums);
        return res;
    }
    
    public void backtrack(List<List<Integer>> list, List<Integer> tempList, int[] nums){
        if(tempList.size() == nums.length){
            list.add(new ArrayList<>(tempList));
        }else{
            for(int i = 0; i < nums.length; i++){
                if(tempList.contains(nums[i])) continue;
                tempList.add(nums[i]);
                backtrack( list, tempList, nums);
                tempList.remove(tempList.size() - 1);
            }
        }
    }
}
__________________________________________________________________________________________________
34872 kb
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if(nums == null || nums.length == 0){
            return result;
        }
        Set<Integer> hash = new HashSet<>();
        recursion(nums,result,hash,new ArrayList<Integer>());
        return result;
    }
    private void recursion(int[] nums, List<List<Integer>> result, Set<Integer> hash, List<Integer> cur){
        if(cur.size() == nums.length){
            result.add(new ArrayList<>(cur));
            return;
        }
        for(int i = 0; i < nums.length; i++){
            if(!hash.contains(nums[i])){
                cur.add(nums[i]);
                hash.add(nums[i]);
                recursion(nums,result,hash,cur);
                cur.remove(cur.size()-1);
                hash.remove(nums[i]);
            }
            else{
                continue;
            }
        }
    }
}
__________________________________________________________________________________________________
34876 kb
class Solution {    
    public void permute(int[] nums, Set<Integer> bitMap, List<Integer> temp, List<List<Integer>> list){
        if(bitMap.size() == 0)
            list.add(new ArrayList<>(temp));
        else{
            for(int num : nums){
                if(bitMap.contains(num)){
                    bitMap.remove(num);
                    temp.add(num);
                    permute(nums, bitMap, temp, list);
                    temp.remove(temp.size()-1);
                    bitMap.add(num);
                }
            }
        }
    }
    
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        Set<Integer> bitMap = new HashSet<>();
        
        for(int num: nums)
            bitMap.add(num);
        
        permute(nums, bitMap, new ArrayList<>(), list);
        return list;
    }
}
__________________________________________________________________________________________________