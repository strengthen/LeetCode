__________________________________________________________________________________________________
2ms
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> comb = new ArrayList<>();
        Arrays.sort(candidates); // need sort to make this work.
        combination(candidates, target, 0, comb, ans);
        return ans;
    }
    
    private void combination(int[] candi, int target, int start,
            List<Integer> comb, List<List<Integer>> ans) {
        for (int i = start; i < candi.length; i++) {
            if (i > start && candi[i] == candi[i - 1]) //remove duplicates.
                continue;
            if (candi[i] == target) {
                //recursion exit.
                List<Integer> newComb = new ArrayList<>(comb);
                newComb.add(candi[i]);
                ans.add(newComb);
            } else if (candi[i] < target) {
                //continue to look for the rest.
                List<Integer> newComb = new ArrayList<>(comb);
                newComb.add(candi[i]);
                combination(candi, target - candi[i], i + 1, newComb, ans);
            } else 
                break; //invalid path, return nothing.
        }
    }
}
__________________________________________________________________________________________________
3ms
class Solution {
    public List<List<Integer>> combinationSum2(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        backtrack(nums, res, new ArrayList<Integer>(), target, 0);
        return res;
    }
    public void backtrack(int[] nums, List<List<Integer>> res, List<Integer> list, int remain, int start){
        if(remain<0) return;
        if(remain==0){
            res.add(new ArrayList<Integer>(list));
            return;
        }
        for(int i = start;i<nums.length;i++){
            if(i!=start && nums[i] == nums[i-1]) continue;
            list.add(nums[i]);
            backtrack(nums, res, list, remain-nums[i],i+1);
            list.remove(list.size()-1);
        }
    }
}
__________________________________________________________________________________________________
4ms
class Solution {
    
    public List<List<Integer>> result = new ArrayList<List<Integer>>();
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        if(candidates == null || candidates.length == 0) return result;
        
        Arrays.sort(candidates);
        
        findCombination(candidates, 0, new ArrayList<Integer>(), target);
        
        return result;
        
    }
    
    public void findCombination(int[] candidates, int index, List<Integer> solution, int left) {
        if(index > candidates.length) return;
        if(left == 0) {
            result.add(new ArrayList<Integer>(solution));
            return;
        }
        
        if(left < 0) return;
        
        for(int i = index; i < candidates.length; i ++) {
           
            solution.add(candidates[i]);
            findCombination(candidates, i + 1, solution, left - candidates[i]);
            solution.remove(solution.size() - 1);
            
             while(i < candidates.length - 1 && candidates[i] == candidates[i + 1]) {
                i ++;              
            }
        } 
    }
}
__________________________________________________________________________________________________
35752 kb
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        helper(res, new ArrayList<>(), 0, target, candidates);
        return res;
    }
    
    public void helper(List<List<Integer>> res, List<Integer> prev, int idx, int target, int[] arr) {
       for(int i = idx; i < arr.length; i++) {
            if (i == idx || arr[i] != arr[i-1]) {
                if (target < arr[i]) break;
                prev.add(arr[i]);
                if (target == arr[i]) {
                    res.add(new ArrayList(prev));
                    prev.remove(prev.size()-1);
                    break;
                }
                
                helper(res, prev, i+1, target - arr[i], arr);
                prev.remove(prev.size()-1);
            }
        }
    }
}
__________________________________________________________________________________________________
35824 kb
class Solution {
    public void bt(List<List<Integer>> res, int[] candidates, List<Integer> cur, int target, int pos){
        if (target == 0) {
            res.add(new ArrayList(cur));
            return;
        }
        for (int i = pos; i < candidates.length; i++) {
            if (candidates[i] > target) break;
            cur.add(candidates[i]);
            bt(res, candidates, cur, target - candidates[i], i + 1);
            while (i + 1 < candidates.length && candidates[i] == candidates[i + 1]) i++;
            cur.remove(cur.size() - 1);
        }
        
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        bt(res, candidates, new ArrayList<>(), target, 0);
        return res;
    }
}
__________________________________________________________________________________________________