__________________________________________________________________________________________________
sample 4 ms submission
    class Solution {
    public:
        int slidingPuzzle(vector<vector<int>>& board) {
            int s = 0, t = 0, d = 0;
            std::unordered_set<int> visited;
            for (auto& x : board) {
                for (auto y : x) {
                    t++;
                    s |= y << (3 * t);
                    d |= (t % 6) << (3 * t);
                    if (y == 0) s |= t;
                }
            }
            d |= 6;

            std::queue<int> q;
            q.push(s);
            visited.insert(s);

            vector<int> diff = { -3, -1, 1, 3 };

            int res = 0;
            while (!q.empty()) {
                int len = q.size();
                for (int j = 0; j < len; j++) {
                    int h = q.front();
                    if (h == d) return res;
                    q.pop();
                    int ind = h & 7;  // 0's pos from 1 to 6
                    //std::cout << "h=" << std::bitset<21>(h) << std::endl;;
                    for (int i : diff) {
                        if (ind == 3 && i == 1) continue;
                        if (ind == 4 && i == -1) continue;
                        int x = ind + i;
                        if (x >= 1 && x <= 6) {  // exchange pos
                            int mask = 7 << (3 * x);
                            int y = (h & ~7 & ~mask) | (((h & mask) >> (3 * x)) << (3 * ind)) | x;
                            //std::cout << "\ty=" << std::bitset<21>(y) << std::endl;;
                            if (visited.find(y) == visited.end()) {
                                q.push(y);
                                visited.insert(y);
                            }
                        }
                    }
                }
                res++;
            }
            return -1;
        }
    };
__________________________________________________________________________________________________
sample 9984 kb submission
class Solution {
public:
    //time: O(R*C*(R*C)!)  //R*C是string size, 總共有(R*C)! 種permutation
    //space: O(R*C*(R*C)!)
    int slidingPuzzle(vector<vector<int>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        string orig_str;
        int zero_idx;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                orig_str += board[i][j] + '0';
                if(board[i][j] == 0)
                    zero_idx = i*n+j;
            }
        }
        queue<pair<string,int>> q;
        q.push({orig_str,zero_idx});
        string target = "123450";
        
        int result=0;
        int dirs[4]={-3,3,-1,1};
        unordered_set<string> visited;
        while(!q.empty()){
            int size = q.size();
            for(int i =0;i<size;i++){
                auto p = q.front();q.pop();
                if(p.first == target)
                    return result;
                
                for(int k=0;k<4;k++){
                    int from_idx = p.second;
                    int to_idx = p.second +dirs[k];
                    if(to_idx < 0 || to_idx > 5 ||(  from_idx == 2 && to_idx ==3 || from_idx == 3 && to_idx ==2 ))continue;
                    swap(p.first[from_idx], p.first[to_idx]);
                    if(visited.count(p.first) == 0){
                        visited.insert(p.first);
                        q.push({p.first,to_idx});
                    }
                    
                    swap(p.first[from_idx], p.first[to_idx]);
                }
                
            }
            result++;
        }
        return -1;
    }
};
__________________________________________________________________________________________________
sample 9996 kb submission
class Solution
{
public:
    
    Solution()
    {
        std::vector<int> board{1, 2, 3, 4, 5, 0};
        solved = board2int(board);
        fillMemo(board, 1, 2, 0);
    }
    
    
    int slidingPuzzle(std::vector<std::vector<int>>& board)
    {
        auto print = board2int(board);
        
        if (print == solved)
        {
            return 0;
        }
        
        if (auto it = memo.find(print)
            ; it != std::cend(memo))
        {
            return it->second;
        }
        
        return -1;
    } // slidingPuzzle
    
    
    static void fillMemo(std::vector<int>& board, int zi, int zj, int steps = 0)
    {
        auto print = board2int(board);
        
        auto it = memo.find(print);
        if ((it != std::end(memo)) && (it->second < steps))
        {
            return;
        }
        
        memo.insert_or_assign(it, print, steps);
        
        std::swap(board[0 * 3 + zj], board[1 * 3 + zj]);
        fillMemo(board, zi ^ 1, zj, steps + 1);
        std::swap(board[0 * 3 + zj], board[1 * 3 + zj]);
        
        if (zj == 1)
        {
            std::swap(board[zi * 3 + zj], board[zi * 3 + zj + 1]);
            fillMemo(board, zi, zj + 1, steps + 1);
            std::swap(board[zi * 3 + zj], board[zi * 3 + zj + 1]);
            
            std::swap(board[zi * 3 + zj], board[zi * 3 + zj - 1]);
            fillMemo(board, zi, zj - 1, steps + 1);
            std::swap(board[zi * 3 + zj], board[zi * 3 + zj - 1]);
        }
        else
        {
            std::swap(board[zi * 3 + zj], board[zi * 3 + 1]);
            fillMemo(board, zi, 1, steps + 1);
            std::swap(board[zi * 3 + zj], board[zi * 3 + 1]);
        }
    } // slidingPuzzleImpl
    
    
    static int board2int(const std::vector<int>& board)
    {
        return board[0]
               + board[1] * 6
               + board[2] * 6 * 6
               + board[3] * 6 * 6 * 6
               + board[4] * 6 * 6 * 6 * 6
               + board[5] * 6 * 6 * 6 * 6 * 6;
    } // board2int
    
    
    static int board2int(const std::vector<std::vector<int>>& board)
    {
        return board[0][0]
               + board[0][1] * 6
               + board[0][2] * 6 * 6
               + board[1][0] * 6 * 6 * 6
               + board[1][1] * 6 * 6 * 6 * 6
               + board[1][2] * 6 * 6 * 6 * 6 * 6;
    } // board2int
    
    
private:
    
    static inline int solved;
    static inline std::unordered_map<int, int> memo;
};