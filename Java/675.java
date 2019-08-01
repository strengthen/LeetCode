__________________________________________________________________________________________________
sample 78 ms submission
class Solution {
    private int[][] f;
    private int lenY, lenX;

    private int[][] c;
    private int[][] n;
    private int lenC, lenN;
    
    private int dist(int sy, int sx, int dy, int dx, int k) {
        lenC = 1; lenN = 0;
        c[0][0] = sy; c[0][1] = sx;
        f[sy][sx] = k;
        
        int s = 0;
        while (lenC > 0) {
            for (int i = 0; i < lenC; i++) {
                sy = c[i][0]; sx = c[i][1];
                if (sy == dy && sx == dx) return s;

                int x, y;
                if (sy > 0 && f[sy-1][sx] > 0 && f[sy-1][sx] < k) {
                    n[lenN][0] = sy-1; n[lenN][1] = sx; lenN++;
                    f[sy-1][sx] = k;
                }
                
                if (sx > 0 && f[sy][sx-1] > 0 && f[sy][sx-1] < k) {
                    n[lenN][0] = sy; n[lenN][1] = sx-1; lenN++;
                    f[sy][sx-1] = k;
                }
                
                if (sy < lenY-1 && f[sy+1][sx] > 0 && f[sy+1][sx] < k) {
                    n[lenN][0] = sy+1; n[lenN][1] = sx; lenN++;
                    f[sy+1][sx] = k;
                }
                
                if (sx < lenX-1 && f[sy][sx+1] > 0 && f[sy][sx+1] < k) {
                    n[lenN][0] = sy; n[lenN][1] = sx+1; lenN++;
                    f[sy][sx+1] = k;
                }
            }

            s++;
            lenC = lenN; lenN = 0;
            int[][] t = c; c = n; n = t;
        }
        
        return -1;
    }
    
    public int cutOffTree(List<List<Integer>> f) {
        lenY = f.size();
        lenX = f.get(0).size();
        this.f = new int[lenY][lenX];
        this.c = new int[lenY*lenX][2];
        this.n = new int[lenY*lenX][2];
        
        List<int[]> seq = new ArrayList<>();
        
        int k;
        for (int y = 0; y < this.f.length; y++)
            for (int x = 0; x < this.f[0].length; x++) {
                k = f.get(y).get(x);
                if (k > 0) this.f[y][x] = 1;
                if (k > 1) seq.add(new int[] {y, x, k});
            }
        
        Collections.sort(seq, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[2]-b[2];
            }
        });
        
        int sy = 0, sx = 0;
        int sum = 0, d;
        
        for (int[] dxy : seq) {
            d = dist(sy, sx, (sy = dxy[0]), (sx = dxy[1]), dxy[2]);
            if (d == -1) return -1;
            sum += d;
        }
        
        return sum;
    }
}
__________________________________________________________________________________________________
sample 42424 kb submission
class Solution {
    int[][] dirs = new int[][]{{0,1},{0,-1},{1,0},{-1,0}};
    
    public int cutOffTree(List<List<Integer>> forest) {
        if (forest == null || forest.size() == 0) 
            return 0;
        
        int br = forest.size();
        int bc = forest.get(0).size();
        PriorityQueue<int[]> q = new PriorityQueue<int[]>((a, b) -> a[2] - b[2]);
        int[] start = new int[]{0,0};
        
        for(int i = 0; i < forest.size(); i++){
            for(int j = 0; j < forest.get(i).size(); j++){
                if(forest.get(i).get(j) > 1)
                    q.add(new int[]{i, j, forest.get(i).get(j)});
            }
        }
        int minStep = 0;
        while(!q.isEmpty()){
            int[] dest = q.poll();
            int step = bfs(forest, start, dest, br, bc);
            if(step < 0){
                return -1;
            }
            minStep+=step;
            start[0] = dest[0];
            start[1] = dest[1];
        }
        return minStep;
    }
    
    public int bfs(List<List<Integer>> forest, int[] start, int[] dest, int br, int  bc){
        boolean[][] visited = new boolean[br][bc];
        Queue<int[]> q = new ArrayDeque<int[]>();
        q.add(start);
        visited[start[0]][start[1]] = true;
        int dist = 0;
        while(!q.isEmpty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                int[] c = q.poll();

                if(c[0] == dest[0] && c[1] == dest[1]){
                    return dist;
                }
                for(int[] d : dirs){
                    int row = c[0] + d[0];
                    int col = c[1] + d[1];

                    if(row < 0 || col < 0 || row >= br || col >= bc || forest.get(row).get(col) == 0 || visited[row][col]){
                        continue;
                    }

                    visited[row][col] = true;
                    q.add(new int[]{row, col});
                }
            }
            dist++;
        }
        return -1;
    }
}
__________________________________________________________________________________________________
