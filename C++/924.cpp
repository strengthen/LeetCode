__________________________________________________________________________________________________
sample 84 ms submission
class Solution 
{
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) 
    {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        sort(begin(initial), end(initial));
        
        vector<int> parent(graph.size());
        for(int i = 0; i < graph.size(); i++)
            parent[i] = i;
        for(int i = 0; i < graph.size() - 1; i++)
            for(int j = i + 1; j < graph.size(); j++)
                if(graph[i][j] == 1)
                    unite(parent, i, j);
        
        vector<int> area(graph.size()), malware(graph.size());
        for(int i = 0; i < graph.size(); i++)
            area[find(parent, i)]++;
        for(int &n : initial)
            malware[find(parent, n)]++;
        
        int mostArea = 0, res = initial[0];
        for(int &n : initial)
        {
            if(malware[find(parent, n)] == 1 && area[find(parent, n)] > mostArea)
            {
                res = n;
                mostArea = area[find(parent, n)];
            }
        }
        return res;    
    }
private:
    int find(vector<int> &parent, int n)
    {
        if(parent[n] != n)
            parent[n] = find(parent, parent[n]);
        return parent[n];
    }
    void unite(vector<int> &parent, int a, int b)
    {
        int rootA = find(parent, a);
        int rootB = find(parent, b);
        //if(rootA != rootB)
        {
            parent[rootB] = rootA;
           /* if(parent[rootA] > parent[rootB])
                parent[rootB] = rootA;
            else
                parent[rootA] = rootB;*/
        }     
    }
};
__________________________________________________________________________________________________
sample 27720 kb submission
class Solution {
private:
    int n;

    void dfs(int x, int c, vector<vector<int>>& graph, int color[], int colorNum[]) {
        for (int y = 0; y < n; y++)
            if (graph[x][y] && !color[y]) {
                color[y] = c;
                colorNum[c]++;
                dfs(y, c, graph, color, colorNum);
            }
    }

public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        n = graph.size();
        // color the graph
        int color[n + 1], colorNum[n + 1];
        memset(color, 0, sizeof(color));
        int c = 1;
        for (int i = 0; i < n; i++) {
            if (!color[i]) {
                color[i] = c;
                colorNum[c] = 1;
                dfs(i, c, graph, color, colorNum);
                c++;
            }
        }
        sort(initial.begin(), initial.end());
        int initialsInColors[n + 1];
        memset(initialsInColors, 0, sizeof(initialsInColors));
        for (int x: initial) {
            initialsInColors[color[x]]++;
        }
        int maxn = -1, index = -1;
        for (int x: initial) {
            if (initialsInColors[color[x]] <= 1 && colorNum[color[x]] > maxn) {
                maxn = colorNum[color[x]];
                index = x;
            }
            else if (initialsInColors[color[x]] > 1 && 0 > maxn) {
                maxn = 0;
                index = x;
            }
        }
        return index;
    }
};
__________________________________________________________________________________________________
