__________________________________________________________________________________________________
struct DSU {
    int n;
    vector<int> uf;
    DSU(int n): n(n) {
        uf.resize(n);
        iota(begin(uf), end(uf), 0);
    }
    int find(int x) {
        return uf[x] = x == uf[x] ? x : find(uf[x]);
    }
    int merge(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr) return 0;
        uf[xr] = yr;
        return 1;
    }
};

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& edges) {
        sort(begin(edges), end(edges), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2]; 
        });
        
        DSU dsu(N);
        int cc = N;
        int ans = 0;
        for (auto& edge : edges) {
            if (dsu.merge(edge[0] - 1, edge[1] - 1)) {
                --cc;
                ans += edge[2];
            }
        }
        
        if (cc == 1) {
            return ans;
        } else {
            return -1;
        }
    }
};

__________________________________________________________________________________________________
class Solution {
private: 
    
    struct Edge {
        int u,v,w;
    };
    
    static bool comp(Edge a, Edge b) {
        if(a.w < b.w) {
            return true;
        } else {
            return false;
        }
    }
    
    vector<int> size, parent;

    int Find(int x) {
        if(parent[x]!=x) {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }

public:
    int minimumCost(int N, vector<vector<int>>& costs) {
        vector<Edge> E;
        
        for(vector<int> edge : costs) {
            E.push_back({edge[0], edge[1], edge[2]});
        }
        
        sort(E.begin(),E.end(),comp); //increasing order
        
        size = vector<int>(N+1);
        parent = vector<int>(N+1);

        // individual sets
        for(int i=1;i<=N;i++) {  
            size[i] = 1;
            parent[i] = i;
        }
        
        int minCost = 0;
        // Minimum Spanning Tree
        for(int i=0;i<E.size();i++) {
            int p = Find(E[i].u);
            int q = Find(E[i].v);

            if(p!=q) {
                if(size[p]<size[q]) {
                    parent[p] = q;
                    size[q]+=size[p];
                } else {
                    parent[q] = p;
                    size[p]+=size[q];
                }
                minCost+=E[i].w;
            }
        }


        bool MST_Present=false;

        for(int i=1;i<=N;++i) {
            if(size[i]==N) {
                MST_Present = true;
                break;
            }
        }
        
        if(!MST_Present) {
            minCost = -1;
        }
        
        return minCost;
    }
};
__________________________________________________________________________________________________
// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
// initialize: UnionFind UF(N)

class UnionFind {                                              // OOP style
private:
	vector<int> p, rank, setSize;
	// p = path toward the root of disjoint set; p[i] = i means it is root
	// rank = upper bound of the actual height of the tree; not reliable as accurate measure
	// setSize = size of each disjoint set

	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N, 1);
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++) p[i] = i;	// each belongs to its own set
	}

	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));		// path compression: cut short of the path if possible
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			numSets--;
			int x = findSet(i), y = findSet(j);
			// rank is used to keep the tree short
			if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
			else {
				p[x] = y; setSize[y] += setSize[x];
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}

	int numDisjointSets() {		// # of disjoint sets
		return numSets;
	}

	int sizeOfSet(int i) {		// size of set
		return setSize[findSet(i)];
	}
};

class Solution {
public:
	int minimumCost(int N, vector<vector<int>>& conn) {
		UnionFind uf(N + 1);
		int i, j, k, ans = 0;

		for (i = 0; i < conn.size(); i++) swap(conn[i][0], conn[i][2]);
		sort(conn.begin(), conn.end());

		for (auto p : conn) {
			if (!uf.isSameSet(p[1], p[2])) {
				uf.unionSet(p[1], p[2]);
				ans += p[0];
			}
		}

		if (uf.sizeOfSet(1) != N) return -1;
		else return ans;
	}
};
