__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public boolean possibleBipartition(int N, int[][] dislikes) {
        int[] parent = new int[N+1];
        for (int[] d : dislikes){
            if (parent[d[1]] == 0)
                parent[d[1]] = d[0]; 
            else {
                boolean c0 = false;
                int a = d[0];               //a = hater
                while(parent[a] != 0){      //if somebody already hates a
                    a = parent[a];          //set a to be the one who hates a
                    c0 = c0 ? false : true; //odd or even length of hate chain
                }
                boolean c1 = false;
                int b = d[1];               //same as above
                while(parent[b] != 0){
                    b = parent[b];
                    c1 = c1 ? false : true;
                }
                if (a == b && c0 == c1) return false; //same beginning of hate chain && same odd/even chain length leads to false
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 58084 kb submission
class Solution {
    private ArrayList<Integer>[] graph;
    private Map<Integer, Integer> color;
    public boolean possibleBipartition(int N, int[][] dislikes) {
        graph = new ArrayList[N+1];
        for (int i =0; i<=N;i++) {
            graph[i] = new ArrayList<>();
        }
        for(int[] dis: dislikes) {
            graph[dis[0]].add(dis[1]);
            graph[dis[1]].add(dis[0]);
        }
        color = new HashMap<>();
        for(int i =1;i<=N;i++) {
            if(!color.containsKey(i) && !dfs(i, 0)) {
                return false;
            }
        }
        return true;
    }
    private boolean dfs(int node, int code) {
        if (color.containsKey(node)) {
            return color.get(node)%2 == code%2;
        }
        color.put(node, code);
        for(int nei: graph[node]) {
            if (!dfs(nei, code + 1)) return false;
        }
        return true;
    }
}
__________________________________________________________________________________________________
