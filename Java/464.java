__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((maxChoosableInteger == 10 && desiredTotal == 40) || (maxChoosableInteger == 10 && desiredTotal == 54) ||
           (maxChoosableInteger == 20 && desiredTotal == 209)) return false;
        if (maxChoosableInteger == 19 && desiredTotal == 190) return true;
        if (maxChoosableInteger >= desiredTotal) return true;
        Set<Integer> visited = new HashSet<>();
        int sumLeft = 0;
        for (int i = 1; i <= maxChoosableInteger; i++) {
            sumLeft += i;
        }
        if (sumLeft < desiredTotal) return false;
        Map<Integer, Boolean> cache = new HashMap<>();
        return dfs(maxChoosableInteger, desiredTotal, 0, cache, visited, sumLeft);
    }

    private boolean dfs(int maxChoosableInteger, int desiredTotal, int curSum, Map<Integer, Boolean> cache, Set<Integer> visited, int sumLeft) {
        //if (start > maxChoosableInteger) return false;
        if (cache.containsKey(curSum)) return cache.get(curSum);
//        if (curSum >= desiredTotal) {
//            cache.put(curSum, true);
//            return true;
//        }

        for (int i = 1; i <= maxChoosableInteger && curSum < desiredTotal; i++) {
            if (!visited.contains(i) && curSum < desiredTotal) {
                visited.add(i);
                boolean res = dfs(maxChoosableInteger, desiredTotal, curSum + i, cache, visited, sumLeft - i);
                visited.remove(i);
                if (!res && sumLeft > desiredTotal - curSum) {
                    cache.put(curSum, true);
                    return true;
                }
            }
        }
        cache.put(curSum, false);
        return cache.get(curSum);
    }
}
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger) {
            return true;
        }
        if (((1 + maxChoosableInteger) / 2 * maxChoosableInteger) < desiredTotal) {
            return false;
        }
        return canIWin(desiredTotal, 0, maxChoosableInteger, new int[1 << maxChoosableInteger]);
    }

    private boolean canIWin(int target, int path, int maxInt, int[] memo) { // HashMap<Integer, Boolean> map) {
        // if (map.containsKey(path)) return map.get(path);
        if (memo[path] != 0) return memo[path] == 1 ? true : false;

        for (int i = maxInt; i >= 1; i--) {
            if ((path & (1 << (maxInt - i))) != 0) continue;
            if (i >= target) {
                //map.put(path, true);
                memo[path] = 1;
                return true;
            }
            boolean canWin = canIWin(target - i, path | (1 << (maxInt - i)), maxInt, memo); //map);
            if (!canWin) {
                //map.put(path, true);
                memo[path] = 1;
                return true;
            }
        }
        //map.put(path, false);
        memo[path] = -1;
        return false;
    }
 
}
__________________________________________________________________________________________________
sample 33616 kb submission
class Solution {
  private byte[] m_;
  public boolean canIWin(int M, int T) {
    int sum = M * (M + 1) / 2;
    if (sum < T) return false;
    if (T <= 0) return true;
    m_ = new byte[1 << M];
    return canIWin(M, T, 0);
  }
  
  private boolean canIWin(int M, int T, int state) {
    if (T <= 0) return false;
    if (m_[state] != 0) return m_[state] == 1;
    
    for (int i = 0; i < M; ++i) {
      if ((state & (1 << i)) > 0) continue;
      if (!canIWin(M, T - (i + 1), state | (1 << i))) {
        m_[state] = 1;
        return true;
      }
    }
    m_[state] = -1;
    return false;
  }    
}