__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int[][] toright = new int[grid.length][grid[0].length];
        int[][] tobottom = new int[grid.length][grid[0].length];
        
        for (int i = 0; i < grid[0].length; i++){
            int temp = 0;
            for(int j = 0; j < grid.length; j++){
                if (grid[j][i] == 0) temp = 0;
                else {
                    temp += 1;
                    tobottom[j][i] = temp;
                }
            }
        }
        
        int side = 0;
        
        for (int j = 0; j < grid.length; j++){
            int temp = 0;
            for(int i = 0; i < grid[0].length; i++){
                if (grid[j][i] == 0) temp = 0;
                else {
                    temp += 1;
                    toright[j][i] = temp;
                    int temp_side = temp;
                    while(temp_side > side){
                        if (tobottom[j][i] >= temp_side
                            && j - temp_side +1 >= 0 && toright[j - temp_side+1][i] >= temp_side 
                            && i-temp_side +1 >= 0 && tobottom[j][i-temp_side+1] >= temp_side){
                            side = temp_side;
                        }
                        temp_side--;
                    }
                }
                //System.out.println("bottom"+tobottom[j][i]);
                //System.out.println(side);
            }
        }
        
        return side*side;  
    }
}
__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[][] hor = new int[n][m];
        int[][] ver = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    hor[i][j] = ver[i][j] = 0;
                } else {
                    hor[i][j] = (j == 0) ? 1 : hor[i][j - 1] + 1;
                    ver[i][j] = (i == 0) ? 1 : ver[i - 1][j] + 1;
                }
            }
        }
        int max = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int cur = Math.min(hor[i][j], ver[i][j]);
                while (cur > max) {
                    if (ver[i][j - cur + 1] >= cur && hor[i - cur + 1][j] >= cur) {
                        max = Math.max(max, cur);
                    }
                    cur--;
                }
            }
        }
        return max * max;
    }
}
__________________________________________________________________________________________________
