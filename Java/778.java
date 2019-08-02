__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int swimInWater(int[][] grid) {
        int n=grid.length,low=0,high=n*n-1,mid;
        while(low<high){
            mid = (low+high)/2;
            if( possible(grid,mid) )
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
    public static boolean possible(int grid[][],int time){
        boolean visited[][] = new boolean[ grid.length ][ grid.length ];
        return dfs( visited,grid,time,0,0 );
    }
    public static boolean dfs( boolean v[][],int g[][],int t,int i,int j){
        if( i<0 || i>=g.length || j<0 || j>=g.length || v[i][j] )
            return false;
        v[i][j] = true;
        if( g[i][j] > t )
            return false;
        if(i==g.length-1 && j==g.length-1)
            return true;
        return dfs(v,g,t,i+1,j) || dfs(v,g,t,i,j+1) || dfs(v,g,t,i-1,j) || 
            dfs(v,g,t,i,j-1);   
    }
}
__________________________________________________________________________________________________
sample 36772 kb submission
class Solution {

	public int swimInWater(int[][] grid) {
        int N = grid.length;
        Set<Integer> seen = new HashSet<Integer>();
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>((k1, k2) ->
                grid[k1 / N][k1 % N] - grid[k2 / N][k2 % N]);
        pq.offer(0);
        int ans = -1;

        int[] dr = new int[]{1, -1, 0, 0};
        int[] dc = new int[]{0, 0, 1, -1};

        while (!pq.isEmpty()) {
            int k = pq.poll();
            int r = k / N, c = k % N;
            ans = Math.max(ans, grid[r][c]);
            if (r == N-1 && c == N-1) return ans;

            for (int i = 0; i < 4; ++i) {
                int cr = r + dr[i], cc = c + dc[i];
                int ck = cr * N + cc;
                if (0 <= cr && cr < N && 0 <= cc && cc < N && !seen.contains(ck)) {
                    pq.offer(ck);
                    seen.add(ck);
                }
            }
        }
        
        return ans;

	}
}
__________________________________________________________________________________________________
