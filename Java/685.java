__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[] findRedundantDirectedConnection(int[][] edges) {
        int n = edges.length;
        int[] parent = new int[n+1], ds = new int[n+1];
        Arrays.fill(parent, -1);
        int first = -1, second = -1, last = -1;
        for(int i = 0; i < n; i++) {
            int p = edges[i][0], c = edges[i][1];
            if (parent[c] != -1) {
                first = parent[c];
                second = i;
                continue;
            }
            parent[c] = i;
            
            int p1 = find(ds, p);
            if (p1 == c) last = i;
            else ds[c] = p1;
        }

        if (last == -1) return edges[second]; // no cycle found by removing second
        if (second == -1) return edges[last]; // no edge removed
        return edges[first];
    }
    
    private int find(int[] ds, int i) {
        return ds[i] == 0 ? i : (ds[i] = find(ds, ds[i]));
    }
}

__________________________________________________________________________________________________
sample 37380 kb submission
class Solution {
    public int[] findRedundantDirectedConnection(int[][] edges) {
        if (edges == null || edges.length == 0 || edges[0] == null || edges[0].length == 0)
            return null;
        Set<Integer> points = new HashSet<>();
        Map<Integer, Integer> parent = new HashMap<>();
        List<int[]> candidates = new ArrayList<>();
        for (int[] edge : edges) {
            int src = edge[0];
            int dst = edge[1];
            points.add(src);
            points.add(dst);
            if (!parent.containsKey(dst)) {
                parent.put(dst, src);
                continue;
            }
            candidates.add(new int[]{src, dst});
            candidates.add(new int[]{parent.get(dst), dst});
            edge[1] = 0;

        }
        UnionFind uf = new UnionFind(points.size());
        for (int[] edge : edges) {
            if (edge[1] == 0)
                continue;
            int src = edge[0] - 1;
            int dst = edge[1] - 1;
            if (uf.isUnion(src, dst)) {
                if (candidates.size() == 0)
                    return edge;
                return candidates.get(1);
            }

            uf.union(src, dst);
        }
        return candidates.get(0);
    }

    class UnionFind{
        private int[] uf;
        UnionFind(int n) {
            uf = new int[n];
            for (int i = 0; i < n; i++) {
                uf[i] = i;
            }
        }

        private int getRoot(int i) {
            while (i != uf[i]) {
                i = uf[i];
            }
            return i;
        }

        public void union(int i, int j) {
            int rooti = getRoot(i);
            int rootj = getRoot(j);
            uf[rooti] = rootj;
        }

        public boolean isUnion(int i, int j) {
             return getRoot(i) == getRoot(j);
        }
    }
}
__________________________________________________________________________________________________
