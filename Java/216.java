__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList();
        Helper(1, 0, k, n, res, new ArrayList());
        return res;
    }
    
    private void Helper(int ind, int sum, int k, int n, List<List<Integer>> res, List<Integer> l) {
        if (l.size() == k) {
            if (sum == n) {
                res.add(new ArrayList(l));
            }
            return;
        }
        for (int i = ind; i <= 9; i++) {
            if (i > (n - sum) / (k - l.size()) + 1)
                return;
            else {
                l.add(i);
                Helper(i + 1, sum + i, k, n, res, l);
                l.remove(l.size() - 1);
            }
        }
    }
}
__________________________________________________________________________________________________
sample 32028 kb submission
class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(k, n, 1, new ArrayList<>(), res);
        return res;
    }
    
    public void dfs(int k, int target, int startNum, List<Integer> subList, List<List<Integer>> res) {
        if (target == 0 && subList.size() == k) {
            res.add(new ArrayList<>(subList));
            return;
        }
        
        for (int i = startNum; i <= 9; i++) {
            if (i > target) {
                break;
            }
            
            subList.add(i);
            dfs(k, target - i, i + 1, subList, res);
            subList.remove(subList.size() - 1);
        }
    }
}
__________________________________________________________________________________________________
