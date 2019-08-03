__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int orangesRotting(int[][] grid) {
        int dirs[][] = {{1,0},{-1,0},{0,1},{0,-1}};
        LinkedList<int[]> s = new LinkedList<>();
        for (int i=0;i<grid.length;i++){
            for (int j=0;j<grid[0].length;j++){
                if (grid[i][j] == 2) s.add( new int[]{i,j} );
            }
        }
        int time = 0, size, curx, cury;
        int[] pos;
        while (s.size()!=0){
            size = s.size();
            for (int k=0;k<size;k++){
                pos = s.poll();
                for (int p=0;p<dirs.length;p++){
                    curx = pos[0] + dirs[p][0];
                    cury = pos[1] + dirs[p][1];
                    if (curx<0||curx>=grid.length
                        ||cury<0||cury>=grid[0].length) continue;
                    if (grid[curx][cury]==1){
                        grid[curx][cury] = 2;
                        s.add(new int[]{curx,cury});
                    }
                }
            }
            time ++;
        }
        for (int i=0;i<grid.length;i++){
            for (int j=0;j<grid[0].length;j++){
                if (grid[i][j] == 1) return -1;
            }
        }
        return time-1>=0? time-1 : 0;
    }
}
__________________________________________________________________________________________________
sample 36960 kb submission
class Solution {
    public int orangesRotting(int[][] grid) {
        if(grid == null)
            throw new IllegalArgumentException("Null grid");
        if(grid.length == 0)
            return 0;
        int fresh = 0;
        int ans = 0;
        
        List<int[]> rotten = new ArrayList<>();
        
        for(int i=0; i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j] == 1)
                    fresh++;
                if(grid[i][j] == 2)
                    rotten.add(new int[]{i,j});
            }
        }
        
        if(fresh == 0)
            return 0;
        
        
        while(rotten.size() > 0){
            List<int[]> temp = new ArrayList<>();
            for(int[] coord: rotten){
                int i = coord[0];
                int j = coord[1];
                
                if(i-1 >= 0 && grid[i-1][j] == 1){
                    fresh--;
                    grid[i-1][j] = 2;
                    temp.add(new int[]{i-1,j});
                }
                if(j-1 >= 0 && grid[i][j-1] == 1){
                    fresh--;
                    grid[i][j-1] = 2;
                    temp.add(new int[]{i,j-1});
                }                
                if(i+1 < grid.length && grid[i+1][j] == 1){
                    fresh--;
                    grid[i+1][j] = 2;
                    temp.add(new int[]{i+1,j});
                }
                if(j+1 < grid[0].length && grid[i][j+1] == 1){
                    fresh--;
                    grid[i][j+1] = 2;
                    temp.add(new int[]{i,j+1});
                }                
            }
            rotten = temp;
            ans ++;
        }
        
        if(fresh > 0)
            return -1;
        return ans - 1;
    }
}
__________________________________________________________________________________________________
