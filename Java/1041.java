__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    private static int[][] DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
  
    public boolean isRobotBounded(String instructions) {
        int facing = 0;
        int[] pos = new int[2];
        for(char c : instructions.toCharArray()) {
            switch(c) {
                case 'G':
                    pos[0] += DIRECTIONS[facing][0];
                    pos[1] += DIRECTIONS[facing][1];
                    break;
                case 'R':
                    facing = (facing+1)%4;
                    break;
                case 'L':
                    facing = (facing+4-1)%4;
                    break;
            }
        }
        return pos[0] == 0 && pos[1] ==0 || facing > 0;
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean isRobotBounded(String instructions) {
         StringBuilder sb = new StringBuilder(instructions.length()*4);
        for(int i=0;i<4;++i) sb.append(instructions);//走四次 看能否回到远点
        int x=0,y=0,direction = 0;//上下左右
        for(int i=0;i<sb.length();++i) {
        	char c = sb.charAt(i);
        	if(c == 'G') {
        		if(direction == 0) x++;
        		else if(direction == 1) x--;
        		else if(direction == 2) y--;
        		else y++;
        	}else if(c == 'L') {
        		if(direction == 0) direction = 2;
        		else if(direction == 1) direction = 3;
        		else if(direction == 2) direction = 1;
        		else direction = 0;
        	}else {
        		if(direction == 0) direction = 3;
        		else if(direction == 1) direction = 2;
        		else if(direction == 2) direction = 0;
        		else direction = 1;
        	}
        }
        return x==0&&y==0;
    }
}
__________________________________________________________________________________________________
