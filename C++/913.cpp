__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
    vector<vector<int>> graph;
    vector<vector<int>> memo;
    vector<bool> visited;

    bool mouse_can_win(int m_pos, int c_pos) {
        bool can_win = false;
        if (memo[m_pos][c_pos] != -1)
            return memo[m_pos][c_pos];
        
        if (m_pos == 0)
            can_win = true;
        else if (m_pos == c_pos)
            can_win = false;
        else {
            visited[m_pos] = true;
            for (int m_move : graph[m_pos]) {
                if (m_move == 0)
                    can_win = true;
                if (can_win) break;
                
                if (m_move == c_pos) continue;
                if (visited[m_move]) continue;

                bool can_win2 = true;
                for (int c_move : graph[c_pos]) {
                    if (c_move == 0) continue;
                    if (!mouse_can_win(m_move, c_move)) {
                        can_win2 = false;
                        break;
                    }
                }
                if (can_win2)
                    can_win = true;
            }
            visited[m_pos] = false;
        }
        memo[m_pos][c_pos] = can_win;
        return can_win;
    }
    bool cat_can_win(int m_pos, int c_pos) {
        bool can_win = true;
        if (memo[m_pos][c_pos] != -1)
            return memo[m_pos][c_pos];
        
        if (m_pos == 0)
            can_win = false;
        else if (c_pos == m_pos)
            can_win = true;
        else {
            visited[c_pos] = true;
            for (int m_move : graph[m_pos]) {
                if (m_move == 0) can_win = false;
                if (!can_win) break;
                if (m_move == c_pos) continue;

                bool can_win2 = false;
                for (int c_move : graph[c_pos]) {
                    if (c_move == 0) continue;
                    if (visited[c_move]) continue;
                    if (cat_can_win(m_move, c_move)) {
                        can_win2 = true;
                        break;
                    }
                }
                if (!can_win2)
                    can_win = false;
            }
            visited[c_pos] = false;
        }
        memo[m_pos][c_pos] = can_win;
        return can_win;
    }
public:
    int catMouseGame(vector<vector<int>>& graph) {
        this->graph = graph;
        int n = 0;
        for (const auto& v : graph) for (int i : v) n = std::max(n, i);
        
        visited.assign(n + 1, false);
        memo.assign(n + 1, vector<int>(n + 1, -1));
        if (mouse_can_win(1, 2))
            return 1;
        
        visited.assign(n + 1, false);
        memo.assign(n + 1, vector<int>(n + 1, -1));
        if (cat_can_win(1, 2))
            return 2;
        
        return 0;
    }
};
__________________________________________________________________________________________________
sample 10384 kb submission
class Solution {
public:
    int clr[51][51][2], catCount[51][51][2], mouseCount[51][51][2], zero[50];
    
    struct Node {
        int m, c, turn;
    };
    int catMouseGame(vector<vector<int>>& graph) {
        // mouse win states
        for (int i=0;i < 50; ++i)
            for (int j=1;j < 50; ++j) {
                    clr[i][j][0] = clr[i][j][1] = 0;
            }
        
        memset(catCount, 0, sizeof(catCount));
        memset(mouseCount, 0, sizeof(mouseCount));
        memset(zero, 0,sizeof(zero));
        
        for (int v : graph[0])
            zero[v] = 1;
        queue<Node> q;
        for (int i=1;i < graph.size(); ++i) {
            Node node1, node2, node3, node4;
            node1.c = node1.m = node2.c = node2.m = i;
            node1.turn = 0;
            node2.turn = 1;
            
            node3.m = node4.m = 0, node3.c = node4.c = i;
            node3.turn = 0, node4.turn = 1;
            q.push(node1);
            q.push(node2);
            q.push(node3);
            q.push(node4);
            
            clr[i][i][0] = clr[i][i][1] = 2;
            clr[0][i][0] = clr[0][i][1] = 1;
        }
        
        while (!q.empty()) {
            Node node = q.front();
            q.pop();
            
            // cout << clr[node.m][node.c][node.turn] << ' ' << node.m << ' ' << node.c << ' ' << node.turn << '\n';
            if (node.turn == 1) {
                
                for (int v : graph[node.m]) {
                    Node newNode;
                    newNode.c = node.c;
                    newNode.m = v;
                    newNode.turn = 0;
                    if (clr[newNode.m][newNode.c][newNode.turn]) 
                        continue;

                    if (clr[node.m][node.c][node.turn] == 1) {
                        clr[newNode.m][newNode.c][newNode.turn] = 1;
                        // cout << "push " << 1 << ' ' << newNode.m << ' ' << newNode.c << ' ' << newNode.turn << '\n';
                        q.push(newNode);
                    }
                    mouseCount[newNode.m][newNode.c][newNode.turn] += (clr[node.m][node.c][node.turn] == 1);
                    catCount[newNode.m][newNode.c][newNode.turn] += (clr[node.m][node.c][node.turn] == 2);
                    if (catCount[newNode.m][newNode.c][newNode.turn] == graph[newNode.m].size()) {
                        clr[newNode.m][newNode.c][newNode.turn] = 2;
                        // cout << "push " << 2 << ' ' << newNode.m << ' ' << newNode.c << ' ' << newNode.turn << '\n';
                        q.push(newNode);
                    }
                }
            } else {
                // node.turn = 0
                for (int v : graph[node.c]) {
                    if (!v) continue;
                    Node newNode;
                    newNode.c = v;
                    newNode.m = node.m;
                    newNode.turn = 1;
                    if (clr[newNode.m][newNode.c][newNode.turn]) 
                        continue;
                    if (node.m == 3 and node.c == 4 and node.turn == 0) {
                        // cout << "*" << newNode.m << ' ' << newNode.c << ' ' << newNode.turn << '\n';
                    }
                    if (clr[node.m][node.c][node.turn] == 2) {
                        clr[newNode.m][newNode.c][newNode.turn] = 2;
                        // cout << "push " << 2 << ' ' << newNode.m << ' ' << newNode.c << ' ' << newNode.turn << '\n';
                        q.push(newNode);
                    }
                    mouseCount[newNode.m][newNode.c][newNode.turn] += (clr[node.m][node.c][node.turn] == 1);
                    catCount[newNode.m][newNode.c][newNode.turn] += (clr[node.m][node.c][node.turn] == 2);
                    if (mouseCount[newNode.m][newNode.c][newNode.turn] == graph[newNode.c].size()-zero[newNode.c]) {
                        clr[newNode.m][newNode.c][newNode.turn] = 1;
                        // cout << "push " << 1 << ' ' << newNode.m << ' ' << newNode.c << ' ' << newNode.turn << '\n';
                        q.push(newNode);
                    }
                }
            }
        }
        return clr[1][2][0];
        
    }
};
__________________________________________________________________________________________________
