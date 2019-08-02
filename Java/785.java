__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean isBipartite(int[][] graph) {
        int[] colors = new int[graph.length];
        for (int i = 0; i < graph.length; i ++) {
            if (colors[i] == 0 && !isValid(graph, colors, i, 1)) {
                return false;
            }
        }
        return true;
    }
    
    private boolean isValid(int[][] graph, int[] colors, int cur, int color) {
        if (colors[cur] != 0) {
            return colors[cur] == color;
        }
        colors[cur] = color;
        for (int next: graph[cur]) {
            if (!isValid(graph, colors, next, -color)) {
                return false;
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 39224 kb submission
class Solution {
    public boolean isBipartite(int[][] graph) {
        if(graph.length < 1)
            return false;
        int[] color = new int[graph.length];
        Arrays.fill(color, -1);
        for(int i=0 ; i<graph.length; i++){
            if(color[i] == -1){
                Stack<Integer> stack = new Stack<>();
                stack.push(i);
                color[i] = 0;
                while(!stack.isEmpty()){
                    Integer node = stack.pop();
                    for(int adj : graph[node]){
                        if(color[adj] == -1){
                            stack.push(adj);
                            color[adj] = color[node] ^ 1;
                        } else if(color[adj] == color[node]){
                            return false;
                        }
                    }
                }

            }
        }        
        return true;
    }    
}
__________________________________________________________________________________________________
