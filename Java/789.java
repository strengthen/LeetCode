__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int d = Math.abs(target[0]) + Math.abs(target[1]);
        
        for (int[] g : ghosts) {
            int tmp = Math.abs(g[0] - target[0]) + Math.abs(g[1] - target[1]);
            if (d >= tmp) {
                return false;
            }
        }
        
        return true;
    }
}
__________________________________________________________________________________________________
sample 39428 kb submission
class Solution {
    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int distance = getDistance(0, 0, target[0], target[1]);
        // System.out.println(distance);
        for(int i=0;i<ghosts.length;i++) {
            int l = getDistance(ghosts[i][0], ghosts[i][1], target[0], target[1]);
            // System.out.println(l);
            if(l <= distance) {
                return false;
            }
        }
        return true;
    }
    
    private int getDistance(int x1, int y1, int x2, int y2) {
        return Math.abs(x2-x1) + Math.abs(y2-y1);
    }
}
__________________________________________________________________________________________________
