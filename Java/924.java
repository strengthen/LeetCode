__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    
    public int minMalwareSpread(int[][] graph, int[] initial) {
        int n = graph.length;
        
        int colors[] = new int[n];
        int c = 1;
        for (int i : initial) {
            colors[i] = c++;
        }
        
        int res = n, count = 0;
        for (int i : initial) {
            int cnt = dfs(graph, colors, i, colors[i]);
            if (cnt > count) {
                res = i;
                count = cnt;
            } else if (cnt == count) {
                res = Math.min(res,i);
            }
        }
        
        return res;
    }
    
    int dfs(int[][] graph, int colors[], int s, int c) {
        int cnt = 1;
        colors[s] = c;
        for (int i = 0; i < graph.length; i++) {
            if (graph[s][i] == 1) {
                if (colors[i] == 0) {
                    int ret_cnt = dfs(graph, colors, i, c);
                    if (ret_cnt == 0) {
                        return 0;
                    } else {
                        cnt += ret_cnt;
                    }
                } else if (colors[i] != c){
                    return 0;
                }
            }
        }
        return cnt;
    }
    
    
    
    public int minMalwareSpread1(int[][] graph, int[] initial) {
        int n = graph.length;
        int parents[] = new int[n];
        int counts[] = new int[n];
        int infects[] = new int[n];
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1) {
                    union(parents, i, j);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            counts[find(parents, i)]++;
        }
        
        for (int i : initial) {
            infects[find(parents, i)]++;
        }
        int res = initial[0];
        boolean found = false;
        for (int i : initial) {
            if (infects[find(parents, i)] == 1) {
                if (!found) {
                    res = i;
                } else if (counts[find(parents, i)] >= counts[find(parents, res)]) {
                    res = Math.min(res, i);
                }
                found = true;
            }
            if (!found) {
                res = Math.min(res, i);
            }
            
        }
        return res;
    }
    
    int find(int parents[], int n) {
        if (parents[n] != n) {
            parents[n] = find(parents, parents[n]);
        }
        return parents[n];
    }
    
    void union(int parents[], int i, int j) {
        int pi = find(parents, i);
        int pj = find(parents, j);
        parents[pi] = pj;
    }
}
__________________________________________________________________________________________________
sample 60856 kb submission
class Solution {
    public int minMalwareSpread(int[][] graph, int[] initial) {
        Set<Integer> set = count(graph, initial, -1);
        Arrays.sort(initial);
        int minIdx = initial[0];
        int min = set.size();
        for(int i : initial){
                set = count(graph, initial, i);
                if(set.size() < min){
                    minIdx = i;
                    min = set.size();
                }
        }
        return minIdx;
    }
    
    private Set<Integer> count(int[][] graph, int[] initial, int skip){
        Set<Integer> visited = new HashSet<>();
        Set<Integer> res = new HashSet<>();
        for(int i : initial){
            if(i != skip){
                visited = new HashSet<>();
                visited.add(i);
                Queue<Integer> queue = new LinkedList<>();
                queue.add(i);
                while(!queue.isEmpty()){
                    int current = queue.poll();
                    int[] tmp = graph[current];
                    for(int j = 0; j<tmp.length; j++){
                        if(tmp[j] ==1 && !visited.contains(j)){
                            queue.add(j);
                            visited.add(j);
                            res.add(j);
                        }
                    }
                }
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
