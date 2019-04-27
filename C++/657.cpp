__________________________________________________________________________________________________
sample 8 ms submission
int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	bool judgeCircle(string moves) {
		int count[2] = { 0 };
		for (char l : moves)
			switch (l) {
			case 'U':
				++count[0];
				break;
			case 'D':
				--count[0];
				break;
			case 'L':
				++count[1];
				break;
			case 'R':
				--count[1];
				break;
			}
		return count[0] == 0 && count[1] == 0;
	}
};
__________________________________________________________________________________________________
sample 9988 kb submission
class Solution {
public:
    bool judgeCircle(string& moves) {
        int movementHeight = 0;
        int movementWeight = 0;
        for (int i = 0; i < moves.length(); i++ ) {
            if(moves[i] == 'U') {
                movementHeight ++;
            }
            else if(moves[i] == 'D') {
                movementHeight --;
            }
            else if(moves[i] == 'L') {
                movementWeight --;
            }
            else {
                movementWeight ++;
            }
        }
        
        if(movementWeight == 0 && movementHeight == 0){
            return true;
        }
        else return false;
        
    }
};
__________________________________________________________________________________________________
