__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        helper(nums, Integer.MIN_VALUE, 0, new ArrayList<>(), res);
        return res;
    }
    
    private void helper(int[] nums, int pre, int start, List<Integer> path, List<List<Integer>> res) {
        if (path.size() >= 2) res.add(new ArrayList<>(path));
        if (start == nums.length) return;

        boolean[] visited = new boolean[201];
        for (int i=start; i<nums.length; i++) {
            if (visited[nums[i]+100]) continue;
            visited[nums[i]+100] = true;
            if (nums[i] >= pre) {
                path.add(nums[i]);
                helper(nums, nums[i], i+1, path, res);
                path.remove(path.size() - 1);
            }
        }
        
    }
}
__________________________________________________________________________________________________
sample 50128 kb submission
class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        if (nums == null || nums.length < 2) {
            return new ArrayList<>();
        }
        Set<String> seqs = new HashSet<>();
        findAllSequences(seqs, nums, "", 0, 0);
        
        List<List<Integer>> res = new ArrayList<>();
        for (String seq : seqs) {
            String[] splits = seq.split(" ");
            if (splits.length > 1) {
                res.add(Arrays.stream(splits).map(Integer::valueOf).collect(Collectors.toList()));
            }
        }
        return res;
    }
    
    private void findAllSequences(Set<String> res, int[] nums, String str, int prev, int idx) {
        if (!str.isEmpty()) {
            res.add(str);
        }
        if (idx >= nums.length) {
            return;
        }
        
        if (str.isEmpty() || nums[idx] >= prev) {
            String newStr = str.isEmpty() ? str + nums[idx] : str + " " + nums[idx];
            findAllSequences(res, nums, newStr, nums[idx], idx + 1);
        }
        findAllSequences(res, nums, str, prev, idx + 1);
    }
}
__________________________________________________________________________________________________
