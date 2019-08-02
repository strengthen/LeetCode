__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int flipgame(int[] fronts, int[] backs) {
        boolean[] crossout = new boolean[2000];
        for (int i = 0; i < fronts.length; i++) {
            if (fronts[i] == backs[i]) {
                crossout[fronts[i]] = true;
            }
        } 
        int i = 0;
        int min = 0;
        for (; i < fronts.length; i++) {
            if (!crossout[fronts[i]]) {
                min = fronts[i];
                break;
            } else if (!crossout[backs[i]]) {
                min = backs[i];
                break;
            }
        }

        for (; i < fronts.length; i++) {
            if (!crossout[fronts[i]] && min > fronts[i]) {
                min = fronts[i];
            }
            if (!crossout[backs[i]] && min > backs[i]) {
                min = backs[i];
            }
        }
        return min;
    }
}
__________________________________________________________________________________________________
sample 40448 kb submission
class Solution {
    public int flipgame(int[] fronts, int[] backs) {
        Set<Integer> same = new HashSet<>();
        for(int i = 0; i < fronts.length; i++) {
            if(fronts[i] == backs[i]) {
                same.add(fronts[i]);
            }
        }
        
        int answer = Integer.MAX_VALUE;
        for(int i = 0; i < fronts.length; i++) {
            if(!same.contains(fronts[i])) {
                answer = Math.min(answer, fronts[i]);
            }
            if(!same.contains(backs[i])) {
                answer = Math.min(answer, backs[i]);
            }
        }
        
        return answer == Integer.MAX_VALUE ? 0 : answer;
    }
}
__________________________________________________________________________________________________
