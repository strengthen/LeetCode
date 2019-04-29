__________________________________________________________________________________________________
sample 28 ms submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void DFS(vector <vector <int>>& A, queue <int>& to_expand, int x, int y)
    {
        A[x][y] = 2;
        to_expand.push(x * N + y);
        for(int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i], next_y = y + dy[i];
            if(0 <= next_x && next_x < N && 0 <= next_y && next_y < N && A[next_x][next_y] == 1)
                DFS(A, to_expand, next_x, next_y);
        }
        return;
    }
    int shortestBridge(vector<vector<int>>& A) 
    {
        N = A.size();
        queue <int> to_expand;
        for(int x = 0; x < N && to_expand.empty(); x++)
            for(int y = 0; y < N && to_expand.empty(); y++)
                if(A[x][y] == 1)
                    DFS(A, to_expand, x, y);
        int distance = 0;
        while(to_expand.size() > 0)
        {
            int num = to_expand.size();
            for(int i = 0; i < num; i++)
            {
                int position = to_expand.front();
                to_expand.pop();
                int x = position / N, y = position % N;
                for(int j = 0; j < 4; j++)
                {
                    int next_x = x + dx[j], next_y = y + dy[j];
                    if(0 <= next_x && next_x < N && 0 <= next_y && next_y < N)
                    {
                        if(A[next_x][next_y] == 1)
                            return distance;
                        if(A[next_x][next_y] == 0)
                        {
                            A[next_x][next_y] = 2;
                            to_expand.push(next_x * N + next_y);
                        }
                    }
                }
            }
            distance++;
        }
        return 0;
    }
private:
    int N, dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
};
__________________________________________________________________________________________________
sample 12936 kb submission
class Solution {
public:
    int dsf(vector<vector<int>>& A, int i, int j) {
        if (i < 0 || j < 0 || 
            i == A.size() || j == A.size() || 
            A[i][j] != 1)               
            return 0;
        A[i][j] = 2;
        return 1 + dsf(A, i + 1, j) + \
               dsf(A, i - 1, j) + \
               dsf(A, i, j + 1) + dsf(A, i, j - 1);
    }
    
    bool expand(vector<vector<int>>& A, int i, int j, int cl) {
        if (i < 0 || j < 0 || i == A.size() || j == A.size()) 
            return false;
        if (A[i][j] == 0) 
            A[i][j] = cl + 1;
        return A[i][j] == 1;
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        for (int i = 0, found = 0; !found && i < A.size(); ++i) {
            for (int j = 0; !found && j < A[0].size(); ++j) 
                found = dsf(A, i, j);
        }
    
        for (int cl = 2; ; ++cl)
            for (int i = 0; i < A.size(); ++i)
                for (int j = 0; j < A.size(); ++j) 
                    if (A[i][j] == cl && 
                        ((expand(A, i - 1, j, cl) || 
                          expand(A, i, j - 1, cl) || 
                          expand(A, i + 1, j, cl) || 
                          expand(A, i, j + 1, cl))))
                        return cl - 2;
    }
};
__________________________________________________________________________________________________
