__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[] findRedundantConnection(int[][] edges) {
          int n = edges.length;//node #
        int[] uf = new int[n];
        for(int i =0;i<n;i++) uf[i] = i;
        int[] ret = new int[2];
        for(int[] edge: edges){
            int u = find(edge[0]-1,uf);
            int v = find(edge[1]-1,uf);
            if(u==v) ret = edge;
            uf[u] =v;
        }
        return ret;
    }
    public static int find(int i, int[] uf){
        while(i!=uf[i]) i = uf[i];
        return i;
    
    }
}
__________________________________________________________________________________________________
sample 35444 kb submission
class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        for (int[] edge : edges) {
            graph.computeIfAbsent(edge[0], unused -> new HashSet<>())
                .add(edge[1]);
            graph.computeIfAbsent(edge[1], unused -> new HashSet<>())
                .add(edge[0]);            
        }
        
        for (int i = edges.length - 1; i >= 0; i--) {
            int[] edgeToSkip = edges[i];
            int reachableNodes = dfs(graph, edgeToSkip);
            if (reachableNodes == edges.length)
                return edgeToSkip;
        }
        return new int[0];
    }
    
    private int dfs(Map<Integer, Set<Integer>> graph, int[] edgeToSkip) {
        Set<Integer> visited = new HashSet<>();
        Deque<Integer> deque = new ArrayDeque<>();
        deque.addFirst(edgeToSkip[0]);
        
        while (!deque.isEmpty()) {
            Integer current = deque.poll();
            if (!visited.add(current))
                continue;
            
            for (Integer neighbour : graph.getOrDefault(current, Collections.emptySet())) {
                if (edgeToSkip[0] == current && edgeToSkip[1] == neighbour || edgeToSkip[1] == current && edgeToSkip[0] == neighbour)
                    continue;
                deque.addFirst(neighbour);
            }
        }
        return visited.size();
    }
}
__________________________________________________________________________________________________
