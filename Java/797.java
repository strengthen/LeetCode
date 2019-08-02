__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        
        path.add(0);
        dfs(graph, res, path, 0);
        
        return res;
    }
    
    private void dfs(int[][] graph, List<List<Integer>> res, List<Integer> path, int node) {
        if (node == graph.length - 1) {
            res.add(new ArrayList<Integer>(path));
            return;
        }
        
        // acyclic, don't need to add visited
        for (int next: graph[node]) {
            path.add(next);
            dfs(graph, res, path, next);
            path.remove(path.size() - 1);
        }
    }
}
__________________________________________________________________________________________________
sample 39220 kb submission
class Solution {

    private List<List<Integer>> allPath = new ArrayList<>();

    private void dfs(int [][] graph, int curr, List<Integer> currPath)
    {

        if (curr == graph.length - 1)
        {
            List<Integer> path =  currPath.stream()
                    .collect(Collectors.toList());
            path.add(curr);
            allPath.add(path);
            return;
        }
        
        currPath.add(curr);
        for (int neighbour:  graph[curr]) 
        {
            dfs(graph, neighbour, currPath);
        }
        currPath.remove(new Integer(curr));
    }
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        
        dfs(graph, 0, new ArrayList<>());
        return allPath;
    }
}
__________________________________________________________________________________________________
