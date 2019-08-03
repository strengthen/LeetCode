__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int snakesAndLadders(int[][] board) {
        int N = board.length;
        boolean[] visited = new boolean[N * N];
        Queue<Integer> queue = new LinkedList<>();
        int steps = 1;
        queue.add(0); visited[0] = true;
        int target = N * N - 1;
        while(!queue.isEmpty()){
            int size = queue.size();
            for(int i = 0; i < size; ++i){
                int v = queue.poll();
                for(int j = 1; j <= 6; ++j){
                    ++v;
                    if(visited[v]) continue;
                    visited[v] = true;
                    if(v == target) return steps;
                    int x = N - 1 - v / N, y = ((v / N) % 2 == 0? (v % N): (N - 1 - v % N));
                    if(board[x][y] < 0)
                        queue.add(v);
                    else{
                        if(board[x][y] == target + 1) return steps;
                        if(!visited[board[x][y] - 1])
                            queue.add(board[x][y] - 1);
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
}
__________________________________________________________________________________________________
sample 38676 kb submission
class Solution {
    public int snakesAndLadders(int[][] board) {
        if(board==null || board.length==0)
            return -1;
        
        Set<Integer> seen=new HashSet<Integer>();
        Queue<Integer> queue = new LinkedList();
        
        queue.offer(1);
        seen.add(1);
        queue.offer(null);
        
        int m = board.length;
        int n=board[0].length;
        int step = 0;
        while(!queue.isEmpty()){
            Integer current = queue.poll();
            
            if(current == null){
                step++;
                if(!queue.isEmpty()){
                    queue.offer(null);
                }
                continue;
            }
            
            if(current == m*n){
                return step;
            }
            
            for(int i=1; i<=6; i++){
                int next = current + i;
                if(next>m*n)
                    continue;
                int[] pos = getPos(next,n,n);
                
                if(board[pos[0]][pos[1]]!=-1){
                     next = board[pos[0]][pos[1]];
                }
                if(seen.contains(next)){
                    continue;
                }
                queue.offer(next);
                seen.add(next);
            }
        }
            
        return -1;
    }
    
    //map id to x,y coordinates
    int[] getPos(int id, int m, int n){
        id--;
        int row = (id)/n;
        int col = row%2==0?(id)%n: (n-1-id%n);
        return new int[]{n-1-row, col};
    }
}
__________________________________________________________________________________________________
