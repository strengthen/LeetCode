__________________________________________________________________________________________________
sample 32 ms submission
class Solution {
public:
    static vector<int> findMinHeightTrees(const int n, const vector<pair<int, int>>& edges) {
        if(n == 1) return {0};
        if(n == 2) return {0, 1};

        vector<pair<int, int>> adjList(n, make_pair(0, 0));

        for(const auto &n: edges) {
            adjList[n.first].second ^= n.second;
            adjList[n.second].second ^= n.first;
            ++adjList[n.first].first;
            ++adjList[n.second].first;
        }

        queue<int> tmp;
        vector<int> sol;
        for(int i = 0; i < n; ++i) {
            if(adjList[i].first == 1) tmp.push(i);
        }
        while(true) {
            int size = tmp.size();
            if(size == 0) return sol;
            sol.clear();
            for(int i = 0; i < size; ++i) {
                int cur = tmp.front(); tmp.pop();
                sol.push_back(cur);
                --adjList[adjList[cur].second].first;
                adjList[adjList[cur].second].second ^= cur;
                if(adjList[adjList[cur].second].first == 1) tmp.push(adjList[cur].second);
            }
        }
    }
};

auto gucciGang = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
__________________________________________________________________________________________________
sample 14888 kb submission
class Solution {
private:
    // delete from edge list the edge that contains i
    // and return i's neighbor
    // NOTE : i is a single-edge node, thus has only one neighbor
    int edgeDel(vector<pair<int, int>>& edges, int i) {
/*   ===============================================
 *                     Attention
 *   ===============================================
 *   in the following code, use auto c as iterator will
 *   result in wrong result when swapping
 */
        for(int k=0; k<edges.size(); k++) {
            if(edges[k].first == i) {
                int temp = edges[k].second;
                swap(edges[k], edges[edges.size()-1]);
                edges.pop_back();
                return temp;
            }
            else if(edges[k].second == i) {
                int temp = edges[k].first;
                swap(edges[k], edges[edges.size()-1]);
                edges.pop_back();
                return temp;
            }
        }
        return -1;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ans;
        if(n == 1) {
            ans.push_back(0);
            return ans;
        }
        vector<int> degree(n, 0);
        for(auto c : edges) {
            degree[c.first]++;
            degree[c.second]++;
        }
        int nodeLeft = n;
        while(nodeLeft > 2) {
            vector<int> oneDegreeNodes;
            for(int i=0; i<degree.size(); i++)
                if(degree[i] == 1)
                    oneDegreeNodes.push_back(i);
            for(int j=0; j<oneDegreeNodes.size(); j++) {
                int neighbor = edgeDel(edges, oneDegreeNodes[j]);
                degree[oneDegreeNodes[j]] = -1;
                degree[neighbor]--;
                nodeLeft--;
            }
        }
        for(int i=0; i<n; i++) {
            if(degree[i] >= 0)
                ans.push_back(i);
        }
        return ans;
    }
};
__________________________________________________________________________________________________
