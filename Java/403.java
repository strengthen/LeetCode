__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    boolean found;
    public boolean canCross(int[] stones) {
        for (int i = 3; i < stones.length; i++) {
            if (stones[i] > 2 * stones[i - 1]) {
                return false;
            }
        }
        check(stones, 0, 1);
        return found;
    }
    private void check(int[] stones, int index, int step) {
        if (step == 0 || found) {
            return;
        }
        if (index == stones.length - 1) {
            found = true;
            return;
        }
        int reach = stones[index] + step;
        for (int i = index + 1; i < stones.length; i++) {
            if (reach > stones[i]) {
                continue;
            }
            if (reach < stones[i]) {
                break;
            }
            check(stones, i, step + 1);
            check(stones, i, step);
            check(stones, i, step - 1);
        }
    }
}
__________________________________________________________________________________________________
sample 36892 kb submission
class Solution {
    public boolean canCross(int[] stones) {
        if (stones.length <=1) return false;
        if (stones[1] != 1) return false;
        
        Set<Integer> set = new HashSet<Integer>();
        for (int i = 0; i < stones.length; i++ ) {
          if (i > 3 && stones[i] > stones[i - 1] * 2) {return false;}  
          set.add(stones[i]);  
        } 
        return canCross(1, 1, set, stones[stones.length-1]);
        
    }
    
    private boolean canCross(int pos, int jump, Set<Integer> set, int last) {
        if (last >= pos+jump-1 && last <= pos+jump+1) return true;
        
        if (set.contains(pos+jump+1) && canCross(pos+jump+1, jump+1, set, last)) return true;
        if (set.contains(pos+jump) && canCross(pos+jump, jump, set, last)) return true;
        if (jump >1 && set.contains(pos+jump-1) && canCross(pos+jump-1, jump-1, set, last)) return true;
        
        
        return false;
        
    }
}
__________________________________________________________________________________________________
