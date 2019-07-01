__________________________________________________________________________________________________
class Solution {
    static int groups = 0;
    static int[] fa;
    static int[] sz;

    static void init(int n) {
        groups = n;
        fa = new int[n];
        for (int i = 1; i < n; ++i) {
            fa[i] = i;
        }
        sz = new int[n];
        Arrays.fill(sz, 1);
    }

    static int root(int p) {
        while (p != fa[p]) {
            fa[p] = fa[fa[p]];
            p = fa[p];
        }
        return p;
    }

    static void combine(int p, int q) {
        int i = root(p);
        int j = root(q);
        if (i == j) {
            return;
        }
        if (sz[i] < sz[j]) {
            fa[i] = j;
            sz[j] += sz[i];
        } else {
            fa[j] = i;
            sz[i] += sz[j];
        }
        groups--;
    }
    
    
    public int earliestAcq(int[][] logs, int N) {
        Arrays.sort(logs,(x,y)->{return x[0]-y[0];});
        init(N);
        
        for(int[] ck:logs){
            combine(ck[1],ck[2]);
            if(groups==1){
                return ck[0];
            }
        }
        return -1;
        
    }
}

__________________________________________________________________________________________________

__________________________________________________________________________________________________
