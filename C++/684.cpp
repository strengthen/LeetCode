__________________________________________________________________________________________________
sample 8 ms submission
class UnionFind {
public:
    UnionFind(int size) {
        root.resize(size + 1);
        for (int i = 1; i < size; ++i) {
            root[i] = i;
        }
    }
    
    int find(int n) {
        if (root[n] != n) {
            root[n] = find(root[n]);
        }
        return root[n];
    }
    
    void merge(int n1, int n2) {
        int r1 = find(n1);
        int r2 = find(n2);
        if (r1 != r2) {
            root[r1] = r2;
        }
    }
private:
    vector<int> root;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> output(2);
        int size = edges.size();
        UnionFind uf(size);
        
        for (auto e: edges) {
            int r1 = uf.find(e[0]);
            int r2 = uf.find(e[1]);
            if (r1 == r2) {
                output[0] = e[0];
                output[1] = e[1];
            }
            else {
                uf.merge(e[0], e[1]);
            }
        }
        
        return output;
    }
};
__________________________________________________________________________________________________
× Close
sample 9936 kb submission
class Solution {
public:
    int find(int i, int parent[])
    {
        parent[i] = (i == parent[i])? i:find(parent[i], parent);
        return parent[i];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size(), parent[n+1];
        for(int i = 0; i < n+1; ++i)
            parent[i] = i;

        vector<int> res;
        for(int i = 0; i < n; ++i)
        {
            int p1 = find(edges[i][0], parent), p2 = find(edges[i][1], parent);
            if(p1 == p2)
                res = edges[i];
            else
                parent[p1] = parent[p2];
        }  
        return res;
    }
};
__________________________________________________________________________________________________
