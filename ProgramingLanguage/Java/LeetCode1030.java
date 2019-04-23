__________________________________________________________________________________________________
8ms
class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        boolean [][] seen = new boolean[R][C];
        List<int[]> ans = new ArrayList<>();
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] {r0, c0});
        int [] drs = {0, 0, 1, -1};
        int [] dcs = {1, -1, 0, 0};
        seen[r0][c0] = true;
        while (!q.isEmpty()) {
            int [] node = q.poll();
            int r = node[0], c = node[1];
            ans.add(new int [] {r, c});
            for(int k = 0; k < 4; ++k) {
                int newr = r + drs[k], newc = c + dcs[k];
                if (0 <= newr && newr < R && 0 <= newc && newc < C && !seen[newr][newc]) {
                    seen[newr][newc] = true;
                    q.add(new int[] {newr, newc});
                }
            }
        }
        
        return ans.toArray(new int [R * C][]);
    }
}
__________________________________________________________________________________________________
15ms
class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
    boolean[][] visited = new boolean[R][C];
    int[][] result = new int[R * C][2];
    int i = 0;
    Queue<int[]> queue = new LinkedList<int[]>();
    queue.offer(new int[]{r0, c0});
    while (!queue.isEmpty()) {
      int[] cell = queue.poll();
      int r = cell[0];
      int c = cell[1];

      if (r < 0 || r >= R || c < 0 || c >= C) {
        continue;
      }
      if (visited[r][c]) {
        continue;
      }

      result[i] = cell;
      i++;
      visited[r][c] = true;

      queue.offer(new int[]{r, c - 1});
      queue.offer(new int[]{r, c + 1});
      queue.offer(new int[]{r - 1, c});
      queue.offer(new int[]{r + 1, c});
    }
    return result;
  }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________

__________________________________________________________________________________________________

__________________________________________________________________________________________________