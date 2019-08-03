__________________________________________________________________________________________________
sample 11 ms submission
/*

"@...a"
".###A"
"b.BCc"


*/

class Solution {
    private static final int NO_SOLUTION = -1;
    private static final char WALL = '#';
    private static final char START = '@';
    
    private static final int[][] MOVES = new int[][] {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    
    private boolean[][][] discovered;
    private Queue<State> queue;
    private String[] grid;
    private int m, n;
    private int goalKeys;
    
    private static boolean isKey(char c) {
        return c >= 'a' && c <= 'f';
    }
    
    private static boolean isLock(char c) {
        return c >= 'A' && c <= 'F';
    }
    
    private static int addKey(int keys, char key) {
        return keys | (1 << ((int)key - 'a'));
    }
    
    // returns true if goal state is reached
    private boolean queueNeighbors(State from) {
        boolean goalReached = false;
        for (int[] move : MOVES) {
            int x = from.x() + move[0];
            int y = from.y() + move[1];
            if (x < 0 || y < 0 || x >= m || y >= n) continue;
            char c = grid[x].charAt(y);
            if (c == WALL) continue;
            if (isLock(c) && !from.hasKey(c)) continue;
            if (discovered[x][y][from.keys()]) continue;
            
            int neighborKeys = isKey(c) ? addKey(from.keys(), c) : from.keys();
            discovered[x][y][from.keys()] = true;
            queue.offer(new State(neighborKeys, x, y));
            goalReached |= neighborKeys == goalKeys;
        }
        return goalReached;
    }
    
    public int shortestPathAllKeys(String[] grid) {
        if (grid == null || grid.length < 1 || grid[0].length() < 1) return 0;
        
        m = grid.length;
        n = grid[0].length();
        discovered = new boolean[m][n][64];
        this.grid = grid;
        int x = 0, y = 0;
        for (int i = 0; grid.length > i; i++) {
            String row = grid[i];
            for (int j = 0; row.length() > j; j++) {
                char c = row.charAt(j);
                if (c == START) {
                    x = i;
                    y = j;
                } else if (isKey(c)) {
                    goalKeys = addKey(goalKeys, c);
                }
            }
        }
        
        if (goalKeys == 0) return 0;
        
        queue = new LinkedList<>();
        queue.offer(new State(0, x, y));
        discovered[x][y][0] = true;
        int moveCount = 0;
        while (!queue.isEmpty()) {
            moveCount++;
            int qSize = queue.size();
            while (qSize-- > 0) {
                State current = queue.poll();
                if (queueNeighbors(current)) {
                    return moveCount;
                }
            }
        }
        
        return NO_SOLUTION;
    }
    
    class State {
        private int keys;
        private int x;
        private int y;
        
        State(int keys, int x, int y) {
            this.keys = keys;
            this.x = x;
            this.y = y;
        }
        
        public boolean hasKey(char lock) {
            return ((keys >> ((int)lock - 'A')) & 1) == 1;
        }
        
        public int keys() {
            return keys;
        }
        
        public int x() {
            return x;
        }
        
        public int y() {
            return y;
        }
    }
}
__________________________________________________________________________________________________
sample 37888 kb submission
import java.awt.Point;
class Solution {
    int[][] dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    private int[][] bfs(int i, int j, String[] grid) {
            int[][] dist = new int[grid.length][grid[0].length()];
            boolean[][] visited = new boolean[grid.length][grid[0].length()];
            Queue<Point> queue = new ArrayDeque<>();
            
            for (int ii=0;ii<grid.length;ii++) {
                for (int jj=0;jj<grid[ii].length();jj++) {
                    dist[ii][jj]=Integer.MAX_VALUE;
                }
            }
        
            visited[i][j] = true;
            dist[i][j] = 0;
            queue.add(new Point(i,j));
    
            while (!queue.isEmpty()) {
                Point cur = queue.poll();
                int curI = cur.x;
                int curJ = cur.y;
                
                    
                for (int k=0;k<dirs.length;k++) {               
                    int newI = curI + dirs[k][0];
                    int newJ = curJ + dirs[k][1];
                    if (newI >= 0 && newJ >= 0 &&
                        newI < grid.length && newJ < grid[0].length() &&
                        !visited[newI][newJ] &&
                        grid[newI].charAt(newJ) != '#'
                       ) {
                        
                        dist[newI][newJ]=dist[curI][curJ]+1;
                        visited[newI][newJ]=true;
                        
                        if ( grid[newI].charAt(newJ) == '.' ||  grid[newI].charAt(newJ) == '@') {
                            queue.add(new Point(newI,newJ));
                        }
                    }  
                }   
            }
        return dist;
    }
    public int shortestPathAllKeys(String[] grid) {
            HashMap<Character,Point> indexer = new HashMap<>();
            int allKeysMask=0;
            for (int i=0;i<grid.length;i++) {
                for (int j=0;j<grid[i].length();j++) {
                    char c = grid[i].charAt(j);
                    if (c != '.' && c != '#') {
                        indexer.put(c,new Point(i,j));
                    }
                    if (Character.isLowerCase(c)) {
                           allKeysMask |= (1 << (c - 'a'));
                    }
                }
            }
        
            HashMap<Character,HashMap<Character,Integer>> dists = new HashMap<>();
            for (char startPlace : indexer.keySet()) {
                dists.putIfAbsent(startPlace,new HashMap<Character,Integer>());
                int startI = indexer.get(startPlace).x;
                int startJ = indexer.get(startPlace).y;
                int[][] dArr = bfs(startI,startJ,grid);
                for (char destPlace : indexer.keySet()) {
                    int endI = indexer.get(destPlace).x;
                    int endJ = indexer.get(destPlace).y;
                    dists.get(startPlace).put(destPlace,dArr[endI][endJ]);
                } 
            }
        
        
                       //System.out.println("dists "+dists);

        
            //dijkstra
            HashMap<String,Integer> finalDist = new HashMap<>();
            HashSet<String> visited = new HashSet<>();
            PriorityQueue<String> pq = new PriorityQueue<>((a,b)->{
                int d= finalDist.getOrDefault(a,Integer.MAX_VALUE).compareTo(finalDist.getOrDefault(b,Integer.MAX_VALUE));
                if (d != 0) return d;
                return a.compareTo(b);
            });
        
        
            pq.add(("@"+0));
            visited.add(("@"+0));

            finalDist.put(("@"+0),0);
            
            while (!pq.isEmpty()) {
                String node = pq.poll();
                visited.add(node);
                //System.out.println("node "+node);
                char c = node.charAt(0);
                int nodeState = Integer.valueOf(node.substring(1));
                int d = finalDist.getOrDefault(node,Integer.MAX_VALUE);
                              //  System.out.println("d "+d);

                if (c == '*') return finalDist.getOrDefault(String.valueOf('*')+allKeysMask,Integer.MAX_VALUE); 

                if (nodeState == allKeysMask) { //another nei (last node)
                    char dest = '*';
                    int newState = nodeState;
                    if (d < finalDist.getOrDefault(String.valueOf(dest)+newState, Integer.MAX_VALUE)) {
                        pq.remove(String.valueOf(dest)+newState);
                        finalDist.put(String.valueOf(dest)+newState,d);
                        pq.add(String.valueOf(dest)+newState);
                    }
                }
                
                for (char dest : dists.get(c).keySet()) {
                    int newState = nodeState;
                    int dToDest =  dists.get(c).get(dest);
                    if (Character.isLowerCase(dest)) //key
                        newState |= (1 << (dest - 'a'));
                    if (Character.isUpperCase(dest)) //lock
                        if ((nodeState & (1 << (dest - 'A'))) == 0 ) continue; //no key
                    
                    if (visited.contains(String.valueOf(dest)+newState)) continue;
                    
                    
                    if (dToDest != Integer.MAX_VALUE &&
                       dToDest + d < finalDist.getOrDefault(String.valueOf(dest)+newState, Integer.MAX_VALUE)) {
                        pq.remove(String.valueOf(dest)+newState);
                        finalDist.put(String.valueOf(dest)+newState,dToDest + d);
                        pq.add(String.valueOf(dest)+newState);
                    }
                    
                }
                
            }        

      return -1;
    }
}
__________________________________________________________________________________________________
