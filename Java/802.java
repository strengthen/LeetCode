__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
    	List<Integer> res = new ArrayList<>();
        if (graph == null || graph.length == 0)
        	return res;
        int[] visited = new int[graph.length];
        for (int i = 0; i < graph.length; i++) {
        	if (helper(graph, visited, i))
        		res.add(i);
        }
        return res;
    }
    public boolean helper(int[][] graph, int[] visited, int i) {
    	if (visited[i] != 0)
    		return visited[i] == 1;
    	visited[i] = 2;
    	for (int num : graph[i])
    		if (!helper(graph, visited, num))
    			return false;
    	visited[i] = 1;
    	return true;
    }
}
__________________________________________________________________________________________________
sample 63468 kb submission
class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
          List<Integer> ans = new ArrayList<>();
          boolean[] visited = new boolean[graph.length];
          boolean[] cycles = new boolean[graph.length];
        
          for(int i=0; i<graph.length; i++){
              if(!visited[i])
                  dfs(i, graph, visited, new boolean[graph.length], cycles);
          }
        
        for(int i=0; i<graph.length; i++){
            if(!cycles[i])
                ans.add(i);
        }
        
        return ans;
        
    }
    
    void dfs(int node, int[][] graph, boolean[] visited, boolean[] visiting, boolean[] cycles){
        if(cycles[node] || visiting[node]){
            cycles[node] = true;
            return;
        } else if(visited[node])
            return;
        
        visiting[node] = true;
        
        for(int child:  graph[node]){
            dfs(child, graph, visited, visiting, cycles);
            if(cycles[child])
                cycles[node] = true;
        }
       
        visiting[node] = false;
        visited[node] = true;
    }    
}
__________________________________________________________________________________________________
