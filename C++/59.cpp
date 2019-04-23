__________________________________________________________________________________________________
4ms
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int data=0;
        int i=0,j=0,ch=1,c=0;
        int row_in=0,col_in=-1,row_end=n,col_end=n;
        while(true){
            while(j<col_end&&ch){
                ++data;
                res[i][j]=data;
                j++;
                c=1;
            }
            if(!c) break;
            i++;j--;col_end--;
            while(i<row_end&&c){
                ++data;
                res[i][j]=data;
                i++;
                ch=0;
            }
            if(ch) break;
            i--;j--;row_end--;
            while(j>col_in&&!ch){
                ++data;
                res[i][j]=data;
                j--;
                c=0;
            }
            if(c) break;
            i--;j++;col_in++;
            while(i>row_in&&!c){
                ++data;
                res[i][j]=data;
                i--;
                ch=1;
            }
            if(!ch) break;
            i++;j++;row_in++;
            
        }
        return res;
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int num = 1;
        for(int i = 0; i < n / 2 + n % 2; i++){
            int row = i;
            int col = i;
            for(col; col < n - i; col++){
                result[row][col] = num; 
                num++;
            }
            if(num > n * n) return result;
            col--;
            for(row = row + 1; row < n - i; row++){
                result[row][col] = num;
                num++;
            }
            if(num > n * n) return result;
            row--;
            for(col = col - 1; col >= i; col--){
                result[row][col] = num;   
                num++;
            }
            if(num > n * n) return result;
            col++;
            for(row = row - 1; row > i; row--){
                result[row][col] = num;
                num++;
            }
            if(num > n * n) return result;
        }
        return result;
    }
};
__________________________________________________________________________________________________
 8848 kb
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> solution(n, vector<int>(n,1));
        if (n == 1) {
            return solution;
        }
        int square = n * n;
        int num = 1;
        int c1 = 0;
        int c2 = n - 1;
        int r1 = 0;
        int r2 = n - 1;
        int dir = 0;
        while (num <= square) {
            switch(dir) {
                case 0:
                    for (int i = c1; i <= c2; ++i) {
                        solution[r1][i] = num;
                        ++num;
                    }
                    ++r1;
                    break;
                case 1:
                    for (int i = r1; i <= r2; ++i) {
                        solution[i][c2] = num;
                        ++num;
                    }
                    --c2;
                    break;
                case 2:
                    for (int i = c2; i >= c1; --i) {
                        solution[r2][i] = num;
                        ++num;
                    }
                    --r2;
                    break;
                case 3:
                    for (int i = r2; i >= r1; --i) {
                        solution[i][c1] = num;
                        ++num;
                    }
                    ++c1;
                    break;
            }
            dir = (++dir) % 4;
        }
        return solution;
    }
};
__________________________________________________________________________________________________
