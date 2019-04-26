__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    
    string insert(string & board, int pos, char ball){
        string new_board = board.substr(0, pos);
        new_board.push_back(ball);
        new_board += board.substr(pos, board.size() - pos);
        int left = pos-1;
        int right = pos+1;
        int before = 0;
        int length = new_board.size();
        int a = pos-1;
        int b = pos;
        while(true){
            while(left >= 0 && new_board[left] == ball)
                left--;
            
            while(right < length && new_board[right] == ball)
                right++;
            if(right - left - before < 4)
                return new_board.substr(0, a + 1) + new_board.substr(b, length - b);
            else{
                if(left == -1 || right == length)
                    return new_board.substr(0, left + 1) + new_board.substr(right, length - right);
                a = left;
                b = right;
                ball = new_board[left];
                before = right - left - 1;
            }
        }
    }
    
    void dfs(string &board, string & hand, int & res, int times, int start){
        //cout<<board<<" ---- "<<hand<<" ---- "<<res<<" "<<times<<endl;
        if(board.size() == 0){
            if(times < res)
                res = times;
            return;
        }
        if(hand.size() == times || times >= res)
            return;
        
        string str;
        
        for(int i = start; i < hand.size(); i++){
            char current_ball = hand[i];
            if(i > start && current_ball == hand[i-1])
                continue;
            times++;
            for(int j = 0; j < board.size(); j++){
                if(current_ball != board[j] || (j > 0 && current_ball == board[j-1]))
                    continue;
                //cout<<current_ball<<endl;
                str = insert(board, j, current_ball);
                dfs(str, hand, res, times, i+1);
            }
            times--;
            //cout<<i<<" "<<times<<endl;
        }
    }
    
    int findMinStep(string board, string hand) {
        vector<int> ball(5);
        vector<bool> clear(5);
        vector<int> hball(5);
        for(char & c : board){
            switch(c){
                case 'R':
                    ball[0] += 1;
                    break;
                case 'Y':
                    ball[1] += 1;
                    break;
                case 'B':
                    ball[2] += 1;
                    break;
                case 'G':
                    ball[3] += 1;
                    break;
                case 'W':
                    ball[4] += 1;
                    break;
            }
        }
        for(char & c : hand){
            switch(c){
                case 'R':
                    hball[0] += 1;
                    break;
                case 'Y':
                    hball[1] += 1;
                    break;
                case 'B':
                    hball[2] += 1;
                    break;
                case 'G':
                    hball[3] += 1;
                    break;
                case 'W':
                    hball[4] += 1;
                    break;
            }
        }
        int num = -1;
        for(int i = 0; i < 5; i++){
            if(ball[i] == 0){
                clear[i] = true;
                num = 0;
            }
            else{
                if(ball[i] == 1){
                    if(hball[i] < 2)
                        return -1;
                }
                else if(ball[i] == 2){
                    if(hball[i] < 1)
                        return -1;
                }
            }
        }
        if(num == 0){
            unordered_map<char, int> table;
            table['R'] = 0;
            table['Y'] = 1;
            table['B'] = 2;
            table['G'] = 3;
            table['W'] = 4;
            hand = "";
            if(!clear[0]) hand += string(hball[0], 'R');
            if(!clear[1]) hand += string(hball[1], 'Y');
            if(!clear[2]) hand += string(hball[2], 'B');
            if(!clear[3]) hand += string(hball[3], 'G');
            if(!clear[4]) hand += string(hball[4], 'W');
        }
        //cout<<board<<endl;
        
        int res = INT_MAX;
        
        dfs(board, hand, res, 0, 0);
        
        if (res == INT_MAX)
            return -1;
        return res;
    }
};
__________________________________________________________________________________________________
sample 8972 kb submission
class Solution {
public:
    
    void backtrack(string& board, map<char,int>& counts, int moves)
    {
        if (board.empty())
            minStep = min(minStep, moves);
        
        for (int i = 0; i < board.size();)
        {
            char c = board[i];
            int j;
            for (j = i; j < board.size() && board[j] == c; ++j);
            int groupSize = j - i;
            int countNeeded = groupSize < 3 ? 3 - groupSize : 0;
            if (counts[c] >= countNeeded)
            {
                board.erase(board.begin() + i, board.begin() + j);
                counts[c] -= countNeeded;
                backtrack(board, counts, moves + countNeeded);
                counts[c] += countNeeded;
                board.insert(i,groupSize, c);
            }
            i = j;
        }
    }
    
    int findMinStep(string board, string hand) {
        map<char, int> counts;
        for (int i = 0; i < hand.size(); ++i)
            ++counts[hand[i]];
        minStep = INT_MAX;
        backtrack(board, counts, 0);
        return minStep == INT_MAX ? -1 : minStep;
            
    }
private:
    int minStep;
};
__________________________________________________________________________________________________
