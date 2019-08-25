__________________________________________________________________________________________________
class Solution {
    public int minCostToSupplyWater(int n, int[] wells, int[][] pipes) {
        DJSet ds = new DJSet(n+2);
        int m = pipes.length;
        pipes = Arrays.copyOf(pipes, m+n);
        for(int i = 0;i < n;i++){
            pipes[m+i] = new int[]{n+1, i+1, wells[i]};
        }
        Arrays.sort(pipes, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[2] - b[2];
            }
        });
        int ans = 0;
        for(int[] e : pipes){
            if(!ds.union(e[0], e[1])){
                ans += e[2];
            }
        }
        return ans;
    }
    
    public class DJSet {
        public int[] upper;

        public DJSet(int n) {
            upper = new int[n];
            Arrays.fill(upper, -1);
        }

        public int root(int x) {
            return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
        }

        public boolean equiv(int x, int y) {
            return root(x) == root(y);
        }

        public boolean union(int x, int y) {
            x = root(x);
            y = root(y);
            if (x != y) {
                if (upper[y] < upper[x]) {
                    int d = x;
                    x = y;
                    y = d;
                }
                upper[x] += upper[y];
                upper[y] = x;
            }
            return x == y;
        }

        public int count() {
            int ct = 0;
            for (int u : upper)
                if (u < 0)
                    ct++;
            return ct;
        }
    }

}	

__________________________________________________________________________________________________

__________________________________________________________________________________________________
