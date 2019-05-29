__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    /**
    * 其实可以把这种 单向graph看成是tree，一个思路
    *   node1
    *   /      \
    *  node2   node3
    *   \     /
    *      node4
    */
    /** note: In your DFS solution, you are resetting the visited array every time you finish with a node. You're using it as a temporary visited array. This means if you visit a sub node of a visited node, you're doing excess work for no reason. I believe you need another permanent visited array to prevent this.

**/
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // generate graph
        ArrayList<Integer>[] arrLists = new ArrayList[numCourses];
        
        for (int i = 0; i < numCourses; i++) {
            arrLists[i] = new ArrayList<Integer>();
        }
        
        // get graph representation -> array of list
        for (int i = 0; i < prerequisites.length; i++) {
            arrLists[prerequisites[i][1]].add(prerequisites[i][0]);
        }
        
        boolean[] visited = new boolean[numCourses];
        boolean[] memo = new boolean[numCourses];
        
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(arrLists, visited, i, memo)) return false;
        }
        
        return true;
        
    }
    
    public boolean dfs(ArrayList<Integer>[] graph, boolean[] visited, int currIdx, boolean[] memo) {
        if (visited[currIdx]) {
            return false;
        }
        if (memo[currIdx]) {
            return true;
        }
        // the lowest level course
        if (graph[currIdx] == null) {
            return true;
        }
        // mark visit
        visited[currIdx] = true;
        for(int j = 0; j < graph[currIdx].size(); j++) {
            if (!dfs(graph, visited, graph[currIdx].get(j), memo)) {
                // return false means terminate searching, there is a loop, so just return false to upper level
                return false;
            }
        }
        // get back to previous status
        memo[currIdx] = true; // finish a branch
        visited[currIdx] = false; 
        return true;
        
    }
}
__________________________________________________________________________________________________
sample 35548 kb submission
class Solution {
    public boolean canFinish(int numCourses, int[][] pre) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        
        for (int i = 0; i < pre.length; i++) {
            if (!map.containsKey(pre[i][0])) {
                map.put(pre[i][0], new ArrayList<Integer>());
            }
            map.get(pre[i][0]).add(pre[i][1]);
        }
        
        int[] visited = new int[numCourses];
        
        for (int i = 0; i < numCourses; i++) {
            if (!explore(i, map, visited)) {
                return false;
            }
        }
        return true;
    }
    
    private boolean explore(int key, Map<Integer, List<Integer>> map, int[] visited) {
        if (!map.containsKey(key) || visited[key] == 1) {
            return true;
        }
        if (visited[key] == -1) {
            return false;
        }
        
        visited[key] = -1;
        for (int preKey : map.get(key)) {
            if(!explore(preKey, map, visited)) {
                return false;
            }
        }
        visited[key] = 1;
        return true;
    }
}
__________________________________________________________________________________________________
//BFS:
public class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList[] graph = new ArrayList[numCourses];
        int[] degree = new int[numCourses];
        Queue queue = new LinkedList();
        int count=0;
        
        for(int i=0;i<numCourses;i++)
            graph[i] = new ArrayList();
            
        for(int i=0; i<prerequisites.length;i++){
            degree[prerequisites[i][1]]++;
            graph[prerequisites[i][0]].add(prerequisites[i][1]);
        }
        for(int i=0; i<degree.length;i++){
            if(degree[i] == 0){
                queue.add(i);
                count++;
            }
        }
        
        while(queue.size() != 0){
            int course = (int)queue.poll();
            for(int i=0; i<graph[course].size();i++){
                int pointer = (int)graph[course].get(i);
                degree[pointer]--;
                if(degree[pointer] == 0){
                    queue.add(pointer);
                    count++;
                }
            }
        }
        if(count == numCourses)
            return true;
        else    
            return false;
    }
}