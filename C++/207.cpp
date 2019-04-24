__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> visited(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && !acyclic(g, visited, i)) {
                return false;
            }
        }
        return true;
    }
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }
        return g;
    }
    
    bool acyclic(graph& g, vector<int>& visited, int node) {
        if (visited[node]==2) {
            return false;
        }
        if (visited[node]) {
            return true;
        }
        visited[node] =2;
        for (int v : g[node]) {
            if (!acyclic(g, visited, v)) {
                return false;
            }
        }
        visited[node] = 1;
        return true;
    }
};
static auto _=[](){cin.tie(nullptr);ios::sync_with_stdio(false);return 0;}();
__________________________________________________________________________________________________
sample 10568 kb submission
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // 首先检查一门课，需要几门预先课，不关注是哪些课
        vector<int> prepnum(numCourses, 0);
        for (auto& pair : prerequisites)
        {
            prepnum[pair.first]++;
        }
        
        // 可以直接学的课程
        queue<int> fncour;
        for (int i = 0; i < numCourses; i++)
        {
            if (prepnum[i] == 0)
            {
                fncour.push(i);
            }
        }
        
        int cnt = fncour.size();
        while (!fncour.empty())
        {
            int x = fncour.front();
            fncour.pop();
            // 哪些课程可以开始学了
            for (auto& pair : prerequisites)
            {
                if (x == pair.second)
                {
                    prepnum[pair.first]--;
                    // 本课预备课程已学完
                    if (prepnum[pair.first] == 0)
                    {
                        fncour.push(pair.first);
                        cnt++;
                    }
                }
            }
        }
        return cnt == numCourses;
    }
};
__________________________________________________________________________________________________
