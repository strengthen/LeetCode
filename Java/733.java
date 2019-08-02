__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        dfs(image, sr, sc, newColor, color);
        return image;
    }
    
    private void dfs(int[][] image, int sr, int sc, int newColor, int color) {
        int row = image.length;
        int col = image[0].length;
        
        if (sr < 0 || sr >= row || sc < 0 || sc >= col || image[sr][sc] != color || image[sr][sc] == newColor) 
            return;
        
        image[sr][sc] = newColor;
        
        dfs(image, sr - 1, sc, newColor, color);
        dfs(image, sr + 1, sc, newColor, color);
        dfs(image, sr, sc - 1, newColor, color);
        dfs(image, sr, sc + 1, newColor, color);
    }
}
__________________________________________________________________________________________________
sample 38812 kb submission
class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        
        int oldColor = image[sr][sc];
        if(newColor == oldColor) {
            return image;
        }
        Queue<int[]> q = new LinkedList<int[]>();
        q.offer(new int[] {sr,sc});
        int[][] dir = new int[][] {
            {1,0},
            {-1,0},
            {0,-1},
            {0,1}
        };
        while(!q.isEmpty()) {
            int levelSize = q.size();
            int[] curPixel = q.poll();
            int cr = curPixel[0];
            int cc = curPixel[1];
            image[cr][cc] = newColor;
            
            for(int[] d: dir) {
                if(cr + d[0] >= 0 && cr + d[0] < image.length &&
                  cc + d[1] >= 0 && cc + d[1] < image[0].length &&
                  image[cr + d[0]][cc + d[1]] == oldColor) {
                    image[cr + d[0]][cc + d[1]] = newColor;
                    q.offer(new int[] {cr + d[0] , cc + d[1]});
                }
            }
        }
        
        return image;
    }
}
__________________________________________________________________________________________________
