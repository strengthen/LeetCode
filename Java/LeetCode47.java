__________________________________________________________________________________________________
1ms
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if (nums == null || nums.length == 0) return res;
        
        Arrays.sort(nums);
        helper(nums, res, new ArrayList<Integer>(), new boolean[nums.length]);
        return res;
    }
    
    private void helper(int[] nums, List<List<Integer>> res, 
                        List<Integer> curr, boolean[] used) {
        if (nums.length == curr.size()) {
            res.add(new ArrayList<>(curr));
            return;
        }
        
        for (int i = 0; i < nums.length; i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            used[i] = true;
            curr.add(nums[i]);
            helper(nums, res, curr, used);
            used[i] = false;
            curr.remove(curr.size()-1);
        }
            
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<> ();
        if (nums == null || nums.length == 0) {
            return result;
        }
        
        boolean[] visited = new boolean[nums.length];
        Arrays.sort (nums);
        
        permuteUnique (nums, result, new ArrayList<> (), visited);
        
        return result;
    }
    
    private void permuteUnique (int[] nums, List<List<Integer>> result, List<Integer> permuteEntry, boolean[] visited) {
        if (permuteEntry.size () == nums.length) {
            result.add (new ArrayList<> (permuteEntry));
            return;
        }
        
        for (int i = 0; i < nums.length; i++) {
            // skip self
            if (visited[i]) {
                continue;
            }
            
            // skip the duplicated one 
            if (i > 0 && visited[i - 1] && nums[i] == nums[i - 1]) {
                continue;
            }
            
            visited[i] = true;
            permuteEntry.add (nums[i]);
            permuteUnique (nums, result, permuteEntry, visited);
            permuteEntry.remove (permuteEntry.size () - 1);
            visited[i] = false;
        }
    }
}
__________________________________________________________________________________________________
3ms
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if(nums.length==0) return res;
        List<Integer> li = new ArrayList<>();
        for(int n: nums){
            li.add(n);
        }
        helper(0, li, res);
        return res;
    }
    
    public void helper(int level, List<Integer> li, List<List<Integer>> res){
        if(level >= li.size()){
            res.add(new ArrayList<>(li));
            return;
        }
        
        Set<Integer> set = new HashSet<>();
        for(int i=level; i<li.size(); i++){
            if(set.contains(li.get(i))){
                continue;
            }
            set.add(li.get(i));
            Collections.swap(li, level, i);
            helper(level+1, li, res);
            Collections.swap(li, level, i);
        }
    }
}
__________________________________________________________________________________________________
35708 kb
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if(nums.length == 0){
            return res;
        }
        Arrays.sort(nums);
        helper(res, new ArrayList<>(), nums, new boolean[nums.length]);
        return res;
    }
    
    public void helper(List<List<Integer>> res, List<Integer> list, int[] nums, boolean[] visited){
        if(list.size() == nums.length){
            res.add(new ArrayList<>(list));
            return;
        }
        for(int i = 0; i < nums.length; i++){
            if(visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])){
                continue;
            }
            visited[i] = true;
            list.add(nums[i]);
            helper(res, list, nums, visited);
            visited[i] =false;
            list.remove(list.size() - 1);
        }
    }
}
__________________________________________________________________________________________________
35792 kb
class Solution {
    
    public void traverse(List<List<Integer>> result, List<Integer> current, int[] nums, boolean[] used, int count){
        if( count == nums.length )
            result.add(new ArrayList<Integer>(current));
        else{
            for(int i = 0; i < nums.length; i++){
                if( used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) )
                    continue;
                current.add(nums[i]);
                used[i] = true;
                traverse(result, current, nums, used, count + 1);
                current.remove(current.size() - 1);
                used[i] = false;
            }
        }
            
    }
    
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        boolean used[] = new boolean[nums.length];
        traverse(result, new ArrayList<Integer>(), nums, used, 0);
        return result;
    }
}
__________________________________________________________________________________________________