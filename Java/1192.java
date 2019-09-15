__________________________________________________________________________________________________
class Solution {
   public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        List<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (List<Integer>conn: connections) {
            int from = conn.get(0), to = conn.get(1);
            graph[from].add(to);
            graph[to].add(from);
        }

        Queue<Integer> q = new LinkedList<>();
        int[] degree = new int[n];
        for (int i = 0; i < n; i++) {
            degree[i] = graph[i].size();
            if (degree[i] == 1) {
                q.offer(i);
            }
        }
        // topsort
        List<List<Integer>> result = new ArrayList<>();
        while (!q.isEmpty()) {
            int from = q.poll();
            int to = graph[from].get(0);
            List<Integer> cur = new ArrayList<>();
            cur.add(from);
            cur.add(to);
            result.add(cur);
            graph[from].remove((Integer)to);
            graph[to].remove((Integer)from);
            if (graph[to].size() == 1) {
                q.offer(to);
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
