__________________________________________________________________________________________________
class Solution {    
    int dir[][] = {{0,-1},{0,1},{1,0},{-1,0}};
    public int maximumMinimumPath(int[][] A) {
        Queue<int[]> q = new ArrayDeque<>();
        
        q.offer(new int[]{0,0,A[0][0]});
        int r = A.length;
        int c = A[0].length;
        
        int dp[][] = new int[r][c];
        dp[0][0] = A[0][0];
        while(q.size()>0){
            int[] ck = q.poll();
            
            for(int d[]:dir){
                
                int nx = d[0]+ck[0];
                int ny = d[1]+ck[1];
                
                if(nx>=0&&ny>=0&&nx<r&&ny<c){
                    int ma = Math.min(ck[2],A[nx][ny]);
                    if(ma>dp[nx][ny]){
                        dp[nx][ny] = ma;
                        q.offer(new int[]{nx,ny,ma});
                    }
                }                
            }           
        }
        return dp[r-1][c-1];
    }
}

__________________________________________________________________________________________________

__________________________________________________________________________________________________
