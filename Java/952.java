__________________________________________________________________________________________________
sample 20 ms submission
class DisjointSet{
    private int[] parent;
    private int[] rank;
    private int[] count;
    public int max;
    
    public DisjointSet(int n){
        parent = new int[n];
        rank = new int[n];
        count = new int[n];
        Arrays.fill(parent, -1);
        Arrays.fill(count, 1);
        max = 1;
    }
    public int find(int a){
        if(parent[a] == -1){
            return a;
        } else {
            return parent[a] = find(parent[a]);
        }
    }
    public boolean union(int a, int b){
        int rootA = find(a), rootB = find(b);
        if(rootA == rootB){
            return false;
        }
        if(rank[rootA] < rank[rootB]){
            parent[rootA] = rootB;
            count[rootB] += count[rootA];
            max = Math.max(max, count[rootB]);
        } else {
            parent[rootB] = rootA;
            count[rootA] += count[rootB];
            max = Math.max(max, count[rootA]);
            if(rank[rootA] == rank[rootB]) {
                rank[rootB]++;
            }
        }
        return true;
    }
}

class Solution {
    public int largestComponentSize(int[] A) {
        int n = A.length;
        DisjointSet dSet = new DisjointSet(n);
        int max = Integer.MIN_VALUE;
        for(int tmp : A){
            max = Math.max(max, tmp);
        }
        boolean[] notPrime = new boolean[max + 1];
        int[] map = new int[max + 1];
        Arrays.fill(map, -1);
        for(int i = 0;i < n;++i){
            map[A[i]] = i;
        }
        for(int i = 2;i <= max;++i){
            if(notPrime[i]) continue;
            int last = map[i];
            for(int j = i * 2;j <= max;j += i){
                notPrime[j] = true;
                int cur = map[j];
                if(cur != -1) {
                    if(last != -1){
                        dSet.union( last, cur);
                    }
                    last = cur;
                }
            }
        }
        return dSet.max;
    }
}
__________________________________________________________________________________________________
sample 43036 kb submission
class Solution {
    public int largestComponentSize(int[] A) {
        
        int[] roots = new int[100001];
        
        for (int i = 0; i < 100001; i++) {
            roots[i] = i;
        }
        
        Arrays.sort(A);
        
        for (int a : A) {
            for (int i = 2; i * i <= a; i++) {
                if (a % i == 0) {
                    union(a, i, roots);
                    union(a, a / i, roots);
                }
            }
        }
        
        Map<Integer, Integer> map = new HashMap<>();
        int res = 0;
        for (int n : A) {
            int f = find(n, roots);
            map.put(f, map.getOrDefault(f, 0) + 1);
            res = Math.max(res, map.get(f));
        }
        
        return res;
    }
    
    public void union(int a, int b, int[] roots) {
        int fa = find(a, roots);
        int fb = find(b, roots);
        
        roots[fa] = fb;
    }
    
    public int find(int n, int[] roots) {
        if (n == roots[n])
            return n;
        
        int r = find(roots[n], roots);
        roots[n] = r;
        
        return r;
    }
}
__________________________________________________________________________________________________
