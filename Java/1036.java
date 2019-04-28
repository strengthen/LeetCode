__________________________________________________________________________________________________
class Solution {
    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for(int[] item: blocked) {
            Set<Integer> set = map.get(item[0]);
            if(null == set) {
                set = new HashSet<>();
                map.put(item[0], set);
            }
            set.add(item[1]);
        }
        
        if(bfsBlocked(map, blocked.length+1, source, target) || bfsBlocked(map, blocked.length+1, target, source)) {
            return false;
        }
        return true;
    }
    
    boolean bfsBlocked(Map<Integer, Set<Integer>> blocked, int maxsteps, int[] source, int[] target) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(source);
        int steps = 0;
        Map<Integer, Set<Integer>> visited = new HashMap<>();
        Set<Integer> set0 = new HashSet<>();
        set0.add(source[1]);
        visited.put(source[0], set0);
        
        int[][] dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        
        while(!queue.isEmpty()) {
            Queue<int[]> nextQueue = new LinkedList<>();
            while(!queue.isEmpty()) {
                int[] cur = queue.poll();
                //System.out.println(cur[0] + "," + cur[1]);
                
                for(int k = 0; k < dirs.length; ++k) {
                    int nextx = cur[0] + dirs[k][0];
                    int nexty = cur[1] + dirs[k][1];
                    if(nextx < 0 || nexty < 0 || nextx >= 1000000 || nexty >= 1000000) continue;
                    
                    Set<Integer> blockedSet = blocked.get(nextx);
                    if(null != blockedSet && blockedSet.contains(nexty)) {
                        continue;
                    }
                    
                    if(nextx == target[0] && nexty == target[1]) {
                        return false;
                    }
                    
                    Set<Integer> visitedSet = visited.get(nextx);
                    if(null == visitedSet || !visitedSet.contains(nexty)) {
                        if(null == visitedSet) {
                            visitedSet = new HashSet<>();
                            visited.put(nextx, visitedSet);
                        }
                        visitedSet.add(nexty);
                        nextQueue.add(new int[]{nextx, nexty});
                    }
                }        
            }
            queue = nextQueue;
            steps++;
            if(steps > maxsteps) {
                return false;
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
