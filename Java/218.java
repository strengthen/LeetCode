__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    
    private int begin = 0;
    
    public List<int[]> getSkyline(int[][] buildings) {
        List<int[]> roofs = new ArrayList<>();
        int[] floor = {0, 0};
        roofs.add(floor);
        for ( int[] building : buildings ) {
            helpAdd(roofs, building);
        }
        for ( int i = 0; i < roofs.size() - 1; i++ ) {
            int[] roof = roofs.get(i);
            int[] next = roofs.get(i+1);
            if ( roof[1] == next[1] ) {
                roofs.remove(i+1);
                i--;
            }
        }
        int[] first = roofs.get(0);
        if ( first[1] == 0 ) {
            roofs.remove(0);
        }
        return roofs;
    }
    
    private void helpAdd(List<int[]> roofs, int[] bu) {
        for ( int i = begin; i < roofs.size() - 1; i++ ) {
            int[] roof = roofs.get(i);
            int[] next = roofs.get(i+1);
            if ( roof[0] >= bu[1] ) {
                break;
            }
            if ( roof[1] >= bu[2] || next[0] <= bu[0] ) {
                continue;
            }
            if ( roof[0] < bu[0] ) {
                if ( next[0] <= bu[1] ) {
                    int[] nroof = {bu[0], bu[2]};
                    roofs.add(++i, nroof);
                    begin = i;
                } else {
                    int[] nroof = {bu[0], bu[2]};
                    int[] nroof2 = {bu[1], roof[1]};
                    roofs.add(i+1, nroof2);
                    roofs.add(i+1, nroof);
                    begin = i + 1;
                    break;
                }
            } else {
                if ( next[0] <= bu[1] ) {
                    roof[1] = bu[2];
                } else {
                    int[] nroof = {bu[1], roof[1]};
                    roof[1] = bu[2];
                    roofs.add(i+1, nroof);
                    break;
                }
            }
            
        }
        int[] last = roofs.get(roofs.size()-1);
        if ( last[1] < bu[2] && last[0] < bu[1] ) {
            if ( last[0] < bu[0] ) {
                int[] nroof = {bu[0], bu[2]};
                int[] nroof2 = {bu[1], last[1]};
                roofs.add(nroof);
                roofs.add(nroof2);
                begin = roofs.size() - 2;
            } else {
                int[] nroof = {bu[1], last[1]};
                last[1] = bu[2];
                roofs.add(nroof);
            }
        }
    }
}
__________________________________________________________________________________________________
sample 36968 kb submission
class Solution {
    List<List<Integer>> ans;
    PriorityQueue<Node> queue;
    public List<List<Integer>> getSkyline(int[][] buildings) {
        queue = new PriorityQueue<Node>((a, b)->(b.h - a.h));
        ans = new ArrayList<>();
        for (int i=0; i<buildings.length; i++) {
            int[] building = buildings[i];
            Node node = new Node(building[0], building[1], building[2]);
            while (!queue.isEmpty() && queue.peek().r < node.l) {
                checkQueue();
            } 
            
            queue.offer(node);
            Node top = queue.poll();
            if (ans.size() == 0 || ans.get(ans.size()-1).get(1) != top.h) {
                if (ans.size() != 0 && ans.get(ans.size()-1).get(0) == top.l) {
                    ans.remove(ans.size()-1);
                }
                addPoint(top.l, top.h);
            }
            queue.offer(top);
        }
        
        while (!queue.isEmpty()) {
            checkQueue();
        }
        return ans;
    }
    
    private void checkQueue() {
        Node lastNode = queue.poll();
        while (!queue.isEmpty() && queue.peek().r <= lastNode.r) queue.poll();
        if (queue.isEmpty()) {
            addPoint(lastNode.r, 0);
        } else {
            addPoint(lastNode.r, queue.peek().h);
        }
    }
    
    private void addPoint(int r, int h) {
        List<Integer> newPoint = new ArrayList<>();
        newPoint.add(r);
        newPoint.add(h);
        ans.add(newPoint);
    }
    
    class Node {
        public int l;
        public int r;
        public int h;
        public Node(int li, int ri, int hi) {
            this.l = li;
            this.r = ri;
            this.h = hi;
        }
    }
}
__________________________________________________________________________________________________
