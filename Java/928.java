__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int minMalwareSpread(int[][] graph, int[] initial) {
        int n = graph.length;
        
        boolean mals[] = new boolean[n];
        for (int i:initial) {
            mals[i] = true;
        }
        
        int res = initial[0], cnt = -1;
        for (int i : initial) {
            boolean[] visits = new boolean[n];
            visits[i] = true;
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (j != i && graph[i][j] == 1) {
                    int ret = dfs(graph, mals, visits, j);
                    if (ret > 0) {
                        sum += ret;
                    }
                }
            }
  //          System.out.println(i+":"+sum +":"+cnt);
            if (sum > cnt) {
                cnt = sum;
                res = i;
            } else if (cnt == sum) {
                res = Math.min(res, i);
            }
        }
        return res;
    }
    
    int dfs(int[][] graph, boolean mals[], boolean visits[], int c) {
 //       System.out.println("vvvv:"+c);
        if (visits[c]) {
            return 0;
        }
        if (mals[c]) {
            return -1;
        }
        visits[c] = true;
        int cnt = 1;
        for (int i = 0; i < graph.length; i++) {
            if (c!=i&&graph[c][i] == 1) {
                if (!visits[i]) {
                    int ret = dfs(graph, mals, visits, i);
                    if (ret < 0) {
                        mals[i] = true;
                        return -1;
                    }
                    cnt += ret;
                }
            }
        }
        return cnt;
    }
}
__________________________________________________________________________________________________
sample 63972 kb submission
class Solution {
    public int minMalwareSpread(int[][] graph, int[] initial) {
        // graph is adjacency matrix...
        int size = graph.length;
        if (size == 0)  return -1;  // nothing to remove
        if (initial.length == 0)    return -1;
        
        int node2remove = -1;
        int minInfection = Integer.MAX_VALUE;
        Arrays.sort(initial);
        for (int x = 0; x < initial.length; x++) {
            // suppose we will remove initial[x]
            int node = initial[x];
            int[][] newgraph = new int[size][size];
            for (int i = 0; i < graph.length; i++) {
                for (int y = 0; y < graph.length; y++) {
                    if (i == node || y == node)
                        newgraph[i][y] = 0;
                    else
                        newgraph[i][y] = graph[i][y];
                }
            }
            
            List<List<Integer>> subCG = new ArrayList();    // all the connected sub-graph
            boolean[] visited = new boolean[size];
            for (int i = 0; i < size; i++) {
                if (!visited[i]) {
                    List<Integer> newsubG = new ArrayList();
                    newsubG.add(i);
                    subCG.add(newsubG);
                    visited[i] = true;
                    dfs(newgraph, i, newsubG, visited);
                }
            }

            for (List<Integer> sub : subCG)
                System.out.println(sub);

            int infectCnt = infected(subCG, initial, node);
            System.out.println("infected is " + infectCnt);
            if (infectCnt < minInfection) {
                minInfection = infectCnt;
                node2remove = node;
            }
        }
        return node2remove;
    }
    
    public int infected(List<List<Integer>> subCG, int[] newinit, int removed) {
        int sum = 0;
        // List<List<Integer>> workCGs = new ArrayList(subCG);
        for (int init: newinit) {
            if (init != removed) {
                List<Integer> sub2remove = null;
                for (List<Integer> sub: subCG) {
                    if (sub.contains(init)) {
                        sum += sub.size();
                        sub2remove = sub;
                    }
                }
                subCG.remove(sub2remove);
            }
        }
        return sum;
    }
    public void dfs(int[][] graph, int current, List<Integer> newsubG, boolean[] visited) {
        for (int i = 0; i < graph.length; i++) {
            // i is the tgt node
            if (graph[current][i] == 1) {  // current & i is directly connected
                if (!visited[i]) {
                    newsubG.add(i); visited[i] = true;
                    dfs(graph, i, newsubG, visited);
                }
            }
        }
    }
}
__________________________________________________________________________________________________
