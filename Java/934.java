__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public int shortestBridge(int[][] A) {
        Queue<int[]> expandingLayer = new LinkedList<>();
        
        outerloop:
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[0].length; j++) {
                if (A[i][j] == 1) {
                    dfs(A, i, j, expandingLayer);
                    break outerloop;
                }
            }
        }

        int res = 0;
        while(!expandingLayer.isEmpty()) {
            int size = expandingLayer.size();
            res++;
            while (size > 0) {
                int[] p = expandingLayer.poll();
                if (expandAndConnected(A, p[0], p[1], expandingLayer)) {
                    return res;
                }
                size--;
            }
        }
        
        return res;
    }
    
    
    private void dfs(int[][] A, int i, int j, Queue<int[]> expandingLayer) {
	    // 跳过已经被标记为边界（-1）的点和已经被标记为island（2）的点们
        if (i < 0 || i >= A.length || j < 0 || j >= A[0].length || A[i][j] == -1 || A[i][j] == 2) {
            return;
        }
        // 只考虑0和1
        if (A[i][j] == 0) {
	        // 边界点，标记加记录
            A[i][j] = -1;
            expandingLayer.add(new int[] {i, j});
        } else if (A[i][j] == 1) {
	        // 标记island
            A[i][j] = 2;
            dfs(A, i + 1, j, expandingLayer);
            dfs(A, i - 1, j, expandingLayer);
            dfs(A, i, j + 1, expandingLayer);
            dfs(A, i, j - 1, expandingLayer);
        }
    }
    
    private boolean expandAndConnected(int[][] A, int i, int j, Queue<int[]> expandingLayer) {
	    // 所有的输入点都是边界，A[i][j] === -1
		// 将边界拓展为island
        A[i][j] = 2;
        int[][] dirs = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        for (int[] d : dirs) {
            int x = i + d[0];
            int y = j + d[1];
            if (x >= 0 && x < A.length && y >= 0 && y < A[0].length) {
	            // 开拓新的边界
                if (A[x][y] == 0) {
                    A[x][y] = -1;
                    expandingLayer.add(new int[] {x, y});
                } else if (A[x][y] == 1) {
	                // 已经连通
                    return true;
                }
                // A[x][y]还可能是-1或2，直接跳过
            }
        }
        return false;
    }
    
}
__________________________________________________________________________________________________
sample 39244 kb submission
class Solution {
    public int shortestBridge(int[][] A) {
        if(A ==null || A.length ==0) return 0;
        
        Queue<int[]> boundry = new LinkedList<>();
        boolean foundOneIsland = false;
        Set<String> visited = new HashSet<>();
        int rowMax = A.length;
        int colMax = A[0].length;
        for(int i =0; i< rowMax && !foundOneIsland ;i++){
            for(int j =0; j< colMax && !foundOneIsland;j++){
                if(A[i][j] == 1){
                    dfs(i, j, rowMax, colMax, A, visited,boundry);
                    foundOneIsland = true;
                }
            }
        }
        
        int distance =-1;
        
        while(!boundry.isEmpty()){
            int size = boundry.size();
            distance++;
            while(size>0){
                int[] next = boundry.poll();
                int nextX = next[0];
                int nextY = next[1];
                if(A[nextX][nextY] ==1) return distance;
                
                visited.add(nextX+"-"+nextY);
                
                addNextCoordinatesForProcess(boundry, nextX+1, nextY,rowMax, colMax, A, visited);
                addNextCoordinatesForProcess(boundry, nextX-1, nextY,rowMax, colMax, A, visited);
                addNextCoordinatesForProcess(boundry, nextX, nextY+1,rowMax, colMax, A, visited);
                addNextCoordinatesForProcess(boundry, nextX, nextY-1,rowMax, colMax, A, visited);
                
                size--;
            }
        }
        return 0;
    }
    private void dfs(int i, int j,int rowMax,int colMax, int[][] A, Set<String> visited,Queue<int[]> boundry){
        
        String c = i+"-"+j;
        if(i<0 ||i>= rowMax || j<0 || j>=colMax || visited.contains(c)) return;
        
        visited.add(c);
        
        if(A[i][j] == 0)boundry.add(new int[]{i,j});
        else{
            dfs(i+1, j,rowMax,colMax, A,visited, boundry);
            dfs(i-1, j, rowMax,colMax, A,visited, boundry);
            dfs(i, j+1, rowMax,colMax, A,visited, boundry);
            dfs(i, j-1, rowMax,colMax, A,visited, boundry);
        }
    }
    private void addNextCoordinatesForProcess(Queue<int[]> boundry, int i, int j,int rowMax,int colMax,int[][] A, Set<String> visited){
        String c = i+"-"+j;
        if(i<0 ||i>= rowMax || j<0 || j>=colMax || visited.contains(c)) return;
        visited.add(c);
        boundry.add(new int[]{i,j});
    }
}
__________________________________________________________________________________________________
