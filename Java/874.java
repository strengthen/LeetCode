__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
    static final int dx[] = {0,1,0,-1};
    static final int dy[] = {1,0,-1,0};
    public int robotSim(int[] commands, int[][] obstacles) {
        HashSet<Pos> walls = new HashSet<>(obstacles.length*2);
        for(int obs[]:obstacles)
            walls.add(new Pos(obs[0],obs[1]));
        Pos pos = new Pos(0,0);
        int incx=0,incy =0;
        int k,d=0;
        int max = 0;
        for(int command:commands){
            switch(command){
                case -2:
                    d = (d+3)%4;
                    break;
                case -1:
                    d = (d+1)%4;
                    break;
                default:
                    incx = dx[d];
                    incy = dy[d];
                    for(k=1;k<=command;k++){
                        pos.x+=incx;
                        pos.y+=incy;
                        if(walls.contains(pos)){
                            pos.x -= incx;
                            pos.y -= incy;
                            break;
                        }
                    }
                    max = Math.max(max,pos.dis());
                    break;
            }       
        }
        return max;
    }
    
    class Pos{
        int x,y;
        public Pos(int x,int y){
            this.x = x;
            this.y = y;
        }
        public int hashCode(){
            return x*31+y;
        }
        public boolean equals(Object obj){
            Pos p = (Pos)obj;
            return x==p.x && y==p.y;
        }
        public int dis(){
            return x * x + y * y;
        }
    }
}
__________________________________________________________________________________________________
sample 50368 kb submission
class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        Set<String> set = new HashSet<>();
        for (int[] obs : obstacles) {
            set.add(obs[0] + " " + obs[1]);
        }
        int[][] dirs = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0, x = 0, y = 0, result = 0;
        for (int c : commands) {
            if (c == -1) {
                d++;
                if (d == 4) {
                    d = 0;
                }
            } else if (c == -2) {
                d--;
                if (d == -1) {
                    d = 3;
                }
            } else {
                while (c-- > 0 && !set.contains((x + dirs[d][0]) + " " + (y + dirs[d][1]))) {
                    x += dirs[d][0];
                    y += dirs[d][1];
                }
            }
            result = Math.max(result, x * x + y * y);
        }
        return result;
    }
}
__________________________________________________________________________________________________
