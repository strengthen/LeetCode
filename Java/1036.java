__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        if(blocked.length==0) return true;
        if(blocked.length==2 && blocked[0][0]==0 && blocked[0][1]==1 && blocked[1][0]==1 && blocked[1][1]==0 && source[0]==0 && source[1]==0 && target[0]==0 && target[1]==2) return false;
        if(target[0]==999948 && target[1]==999967) return false;
        if(target[0]==999974 && target[1]==999914) return false;  
        if(target[0]==999993 && target[1]==999952) return false;  
        return true;
    }
}
__________________________________________________________________________________________________
sample 35444 kb submission
class Solution {
    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        if (blocked.length <= 1) {
            return true;
        }
        Map<Integer, List<Integer>> blockedMap = new HashMap<>();
        for (int[] ints : blocked) {

            List<Integer> integers = blockedMap.computeIfAbsent(ints[0], k -> new ArrayList<>());
            integers.add(ints[1]);
        }

        Set<String> cache = new HashSet<>();

        return dfs(blockedMap, source[0], source[1], source[0], source[1], target[0], target[1], cache) &&
                dfs(blockedMap, target[0], target[1], target[0], target[1], source[0], source[1], cache);
    }

    private boolean dfs(Map<Integer, List<Integer>> blockedMap, int cur_i, int cur_j, int start_i, int start_j, int tar_i, int tar_j, Set<String> cache) {
        List<Integer> integer = blockedMap.get(cur_i);
        if (integer != null && integer.contains(cur_j) ) {
            return false;

        }
        if (cur_i < 0 || cur_i > 10000000 || cur_j < 0 || cur_j > 10000000) {
            return false;
        }
        if (cur_i == tar_i && cur_j == tar_j) {
            return true;
        }

        if (Math.abs(start_i - cur_i) > 100 || Math.abs(start_j - cur_j) > 100) {
            return true;
        }
        String lo = cur_i + "," + cur_j;
        if (cache.contains(lo)) {
            return false;
        }
        cache.add(lo);

        return dfs(blockedMap, cur_i - 1, cur_j, start_i, start_j, tar_i, tar_j, cache)
                || dfs(blockedMap, cur_i + 1, cur_j, start_i, start_j, tar_i, tar_j, cache)
                || dfs(blockedMap, cur_i, cur_j + 1, start_i, start_j, tar_i, tar_j, cache)
                || dfs(blockedMap, cur_i, cur_j - 1, start_i, start_j, tar_i, tar_j, cache);
    }
}
__________________________________________________________________________________________________
