__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int movesToChessboard(int[][] board) {
        int n=board.length;
        int t=0,tt=0;
        int m=n-n/2;
        for(int i=0;i<n;i++){
            t+=board[0][i];
            tt+=board[i][0];
            if(t>m||(i+1-t)>m)
                return -1;
            if(tt>m||(i+1-tt)>m)
                return -1;
        }
        int t1=1,tt1=0,tt2=0,t2=1;
        for(int i=1;i<n;i++){
            boolean f=true,f1=true;
            if(board[i][0]!=board[0][0])
                f=false;
            if(board[0][i]!=board[0][0])
                f1=false;
            for(int j=1;j<n;j++){
                if((!f&&board[i][j]==board[0][j])||(f&&board[i][j]!=board[0][j]))
                    return -1;
                if((!f1&&board[j][i]==board[j][0])||(f1&&board[j][i]!=board[j][0]))
                    return -1;
            }
            if(f){
                if(i%2==1)
                    tt1++;
                t1++;
            }
            if(f1){
                if(i%2==1)
                    tt2++;
                t2++;
            }
            if(t1>m||(i+1-t1)>m)
                return -1;
            if(t2>m||(i+1-t2)>m)
                return -1;
        }
        if(n%2==0)
            return Math.min(m-tt1,tt1)+Math.min(m-tt2,tt2);
        else
            return (t1==m?tt1:m-1-tt1)+(t2==m?tt2:m-1-tt2);
    }
}
__________________________________________________________________________________________________
class Solution {
    public int movesToChessboard(int[][] b) {
        int N = b.length, rowSum = 0, colSum = 0, rowSwap = 0, colSwap = 0;
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j)
                if ((b[0][0] ^ b[i][0] ^ b[0][j] ^ b[i][j]) == 1) return -1;
        for (int i = 0; i < N; ++i) {
            rowSum += b[0][i];
            colSum += b[i][0];
            if (b[i][0] == i % 2) rowSwap ++;
            if (b[0][i] == i % 2) colSwap ++ ;
        }
        if (rowSum != N / 2 && rowSum != (N + 1) / 2) return -1;
        if (colSum != N / 2 && colSum != (N + 1) / 2) return -1;
        if (N % 2 == 1) {
            if (colSwap % 2 == 1) colSwap = N - colSwap;
            if (rowSwap % 2 == 1) rowSwap = N - rowSwap;
        } else {
            colSwap = Math.min(N - colSwap, colSwap);
            rowSwap = Math.min(N - rowSwap, rowSwap);
        }
        return (colSwap + rowSwap) / 2;
    }
}
__________________________________________________________________________________________________
sample 42672 kb submission
class Solution {
    public int movesToChessboard(int[][] board) {
        int n = board.length, rowSum = 0, colSum = 0, rowDiff = 0, colDiff = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if ((board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) != 0)
					return -1;
			}
		}

		for (int i = 0; i < n; ++i) {
			rowSum += board[0][i];
			colSum += board[i][0];
			rowDiff += (board[i][0] == (i % 2)) ? 0 : 1;
			colDiff += (board[0][i] == (i % 2)) ? 0 : 1;
		}

		if (n / 2 > rowSum || rowSum > (n + 1) / 2)
			return -1;
		if (n / 2 > colSum || colSum > (n + 1) / 2)
			return -1;

		if ((n % 2) != 0) {
			if ((rowDiff % 2) != 0)
				rowDiff = n - rowDiff;
			if ((colDiff % 2) != 0)
				colDiff = n - colDiff;
		} else {
			rowDiff = Math.min(n - rowDiff, rowDiff);
			colDiff = Math.min(n - colDiff, colDiff);
		}

		return (rowDiff + colDiff) / 2;
    }
}