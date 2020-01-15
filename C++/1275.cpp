__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> vec(3, vector<int>(3, 0));
        
        for (int i = 0; i < moves.size(); i++) {
            if (i % 2 == 0)
                vec[moves[i][0]][moves[i][1]] = 1;
            else
                vec[moves[i][0]][moves[i][1]] = -1;
        }
        
        int sum3 = 0;
        int sum4 = 0;
        int z_count = 0;
        for (int i = 0; i < 3; i++) {
            int sum1 = 0;
            int sum2 = 0;
            for (int j = 0; j < 3; j++) {
                sum1 += vec[i][j];
                sum2 += vec[j][i];
                if (vec[i][j] == 0) {
                    z_count++;
                }
            }
            if (sum1 == 3 || sum2 == 3) {
                return "A";
            }
            if (sum1 == -3 || sum2 == -3) {
                return "B";
            }
            sum3 += vec[i][i];
            sum4 += vec[i][2 - i];
        }
        if (sum3 == 3 || sum4 == 3)
            return "A";
        else if (sum3 == -3 || sum4 == -3)
            return "B";
        else if (z_count > 0) {
            return "Pending";
        }
        else {
            return "Draw";
        }
    }
};
__________________________________________________________________________________________________
0ms
class Solution {
public:
     string tictactoe(vector<vector<int>>& moves) {
      vector<int> A(8,0), B(8,0); // 3 rows, 3 cols, 2 diagonals
      for(int i=0; i<moves.size(); i++) {
          int r=moves[i][0], c=moves[i][1];
          vector<int>& player = (i%2==0)?A:B;
          player[r]++;
          player[c+3]++; 
          if(r==c) player[6]++;
          if(r==2-c) player[7]++;
      }
      for(int i=0; i<8; i++) {
          if(A[i]==3) return "A";
          if(B[i]==3) return "B";
      }
      return moves.size()==9 ? "Draw":"Pending";
  }
};
__________________________________________________________________________________________________
