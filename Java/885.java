__________________________________________________________________________________________________
sample 1 ms submission
class Solution {    
    int[][] res;
    int R;
    int C;
    
    public int[][] spiralMatrixIII(int R, int C, int r0, int c0) {
        this.res = new int[R * C][];
        this.R = R;
        this.C = C;
        
        fillArr(r0, c0, 0, 1);
        return res;
    }
    
    private boolean isValid(int i, int j) {
        return i >= 0 && i < R && j >= 0 && j < C;
    }
    
    private void fillArr(int row, int col, int index, int len) {
        if (index == res.length) {
            return;
        }
        if (len == 1) {
            res[index] = new int[]{row, col};
            index++;
            len += 2;
            
            fillArr(row, col + 1, index, len);
            return;
        }
        int i = row;
        int j = col;
        
        int count = len - 1;
        while (count > 0) {
            if (isValid(i, j)) {
                res[index] = new int[]{i, j};
                index++;
            }
            i++;
            count--;
        }
        i--;
        j--;
        
        count = len - 1;
        while (count > 0) {
            if (isValid(i, j)) {
                res[index] = new int[]{i, j};
                index++;
            }
            j--;
            count--;
        }
        j++;
        i--;
        
        count = len - 1;
        while (count > 0) {
            if (isValid(i, j)) {
                res[index] = new int[]{i, j};
                index++;
            }
            i--;
            count--;
        }
        i++;
        j++;
        
        count = len -1;
        while (count > 0) {
            if (isValid(i, j)) {
                res[index] = new int[]{i, j};
                index++;
            }
            j++;
            count--;
        }
        
        len += 2;
        fillArr(i, j, index, len);
    }
}
__________________________________________________________________________________________________
sample 36420 kb submission
class Solution {
    public int[][] spiralMatrixIII(int R, int C, int r0, int c0) {
        int[] dirMoves = new int[4];
        dirMoves[0] = 1; // right
        dirMoves[1] = 1; // down
        dirMoves[2] = 2; // left
        dirMoves[3] = 2; // up
        
        int[][] dirMap = new int[4][2];
        dirMap[0] = new int[]{0, 1};
        dirMap[1] = new int[]{1, 0};
        dirMap[2] = new int[]{0, -1};
        dirMap[3] = new int[]{-1, 0};
        
        int maxVisit = R*C;
        int visit = 0;
        int[][] result = new int[maxVisit][2];
        
        int currentDir = 0;
        int currentR = r0;
        int currentC = c0;
        while(visit < maxVisit) {
            int numMoves = 0;
            
            while(numMoves < dirMoves[currentDir]) {
                if(isValid(currentR, R - 1) && isValid(currentC, C - 1)) {
                    result[visit][0] = currentR;
                    result[visit][1] = currentC;
                    
                    visit++;
                }

                currentR += dirMap[currentDir][0];
                currentC += dirMap[currentDir][1];
                
                numMoves++;
            }
            
            dirMoves[currentDir] += 2;
            
            currentDir = (currentDir + 1) % 4;
        }
        
        return result;
    }
    
    private boolean isValid(int currentVal, int maxVal) {
        if(currentVal < 0 || currentVal > maxVal) return false;
        
        return true;
    }
}
__________________________________________________________________________________________________
