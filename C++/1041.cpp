__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    bool isRobotBounded(string instructions) {
        bool ans = false;
        int x = 0;
        int y = 0;
        int dir = 0;
        for(int i = 0;i<instructions.length();i++){
            if(instructions[i] == 'G'){
                if(dir == 0) y--;
                else if(dir == 1) x++;
                else if(dir == 2) y++;
                else x--;
            }
            else if(instructions[i] == 'L'){
                dir--;
                if(dir<0) dir+=4;
            }
            else {
                dir++;
                if(dir>3) dir-=4;
            }
        }
        if(x==0 && y==0) return true;
        else{
            if(dir == 0) return false;
            else return true;
        }
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool isRobotBounded(string is) {
        int dirs[4][2] = {{0,1}, {-1, 0}, {0, -1}, {1, 0}};
        int pos[2] = {0, 0};
        int dir = 1;
        for (int i = 0; i < 4; i++){
            for (auto c : is){
                if (c == 'G'){
                    pos[0] += dirs[dir][0];
                    pos[1] += dirs[dir][1];
                } else if (c == 'L'){
                    dir = (dir+1) % 4;
                } else if (c == 'R'){
                    dir = ((dir-1)+4) % 4;
                }
            }
        }        
        return (pos[0] == 0 && pos[1] == 0);
    }
};
__________________________________________________________________________________________________
