__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
    private:
    int find( int x, vector<int> &p ) {
        int r = x;
        while ( r != p[r] ) {
            r = p[r];
        }
        return r;
    }
public:
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0), candA, candB;
        for(auto &edge : edges)
        {
            if( parent[edge[1]] == 0 )
            {
                parent[edge[1]] = edge[0];
            }
            else
            {
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = 0;
            }
        }
        for( int i=0; i<=n; i++ )
        {
            parent[i] = i;
        }
        for ( int i=0; i<n; i++ ) {
            int x = edges[i][0];
            int y = edges[i][1];
            //无环
            if ( find(y, parent) != x) {
                //无环有双父亲节点
                parent[x] = find(y,parent); 
            }
            //有环
            else {
                //有环无双父亲节点
                if ( candA.size() == 0 ) {
                    return edges[i];
                }
                //有环有双父亲节点
                else {
                    return candA;
                }
            }
        }
        return candB;
    }
};
__________________________________________________________________________________________________
sample 10248 kb submission
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent_ = vector<int>(n + 1, 0);
        vector<int> ans1, ans2;

        // step 1, check whether there is a node with two parents
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (parent_[v] == 0) {
                parent_[v] = u;
            } else {
                ans1 = {parent_[v], v};
                ans2 = edge;
                edge[1] = 0;                // invalid the second edge
            }
        }

        // step 2, union find
        for (int i = 0; i < parent_.size(); i++) {
            parent_[i] = i;
        }
        for (auto& edge : edges) {
            if (edge[1] == 0) {             // the invalid edge in step 1
                continue;
            }
            int u = edge[0], v = edge[1];
            int pu = find(u);
            if (pu == v) {                  // find a circle
                if (ans1.empty()) {
                    return edge;            // case 2
                } else {
                    return ans1;            // case 3
                }
            }
            parent_[v] = pu;
        }
        return ans2;                        // case 1, no loop
    }
private:
    vector<int> parent_;

    int find(int x) {
        if (parent_[x] != x) {
            parent_[x] = find(parent_[x]);
        }
        return parent_[x];
    }
};
__________________________________________________________________________________________________
