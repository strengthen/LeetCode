__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    private List<Integer> result = new ArrayList<>();
    
    public List<Integer> grayCode(int n) {
        helper(0, n, false);
        
        return result;
    }
    
    private void helper(int base, int count, boolean swap) {
        if (count == 0) {
            result.add(base);
            return;
        }
        
        if (!swap) {
            helper(base+0, count-1, false);
            helper(base+(1<<(count-1)), count-1, true);
        } else {
            helper(base+(1<<(count-1)), count-1, false);
            helper(base+0, count-1, true);
        }
    }
}
__________________________________________________________________________________________________
sample 35376 kb submission
class Solution {
    public List<Integer> grayCode(int n) {
    List<Integer> result = new ArrayList<>();
    result.add(0);
    dfs(0, n, result);
    return result;
}

private void dfs(int i, int n, List<Integer> result) {
 if (i == n) return;
 else {
   int flipper = 1 << i;
   for (int j = result.size() - 1; j >= 0; j--)
     result.add(result.get(j) | flipper);
   
   dfs(i + 1, n, result);
  }
 }
}
__________________________________________________________________________________________________
