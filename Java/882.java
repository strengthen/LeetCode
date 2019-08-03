__________________________________________________________________________________________________
sample 18 ms submission
class Solution {
    public int reachableNodes(int[][] edges, int M, int N) {
        int res = 0;
		List<int[]> g[] = new ArrayList[N];
		for (int[] e : edges) {
			if (g[e[0]] == null) {
				g[e[0]] = new ArrayList<>();
			}
			g[e[0]].add(new int[] {e[1], e[2]});
			if (g[e[1]] == null) {
				g[e[1]] = new ArrayList<>();
			}
			g[e[1]].add(new int[] {e[0], e[2]});		
		}
		
		Queue<Integer> q = new LinkedList<>();
		boolean [] visited = new boolean[N];
		int [] pc = new int[N]; //path count
		Arrays.fill(pc, Integer.MIN_VALUE);
		pc[0] = M;
		q.add(0);
		visited[0] = true;
		
		while (!q.isEmpty()) {
			Integer curr = q.poll();
			visited[curr] = false;
			List<int[]> next = g[curr];
			if (next != null) {
				for (int[] n : next) {
					int v = n[0];
					int v_pc = pc[curr] - n[1] - 1;
					if (v_pc < 0 || v_pc <= pc[v]) continue;
					pc[v] = v_pc;
                    if (visited[v]) continue;
					q.add(v);
					visited[v] = true;
				}
			}
		}
		
	    for (int i = 0; i < N; ++i) {
            res += (pc[i] >= 0) ? 1 : 0;
        }
		for (int[] e : edges) {
            int uv = pc[e[0]] == Integer.MIN_VALUE ? 0 : pc[e[0]];
            int vu = pc[e[1]] == Integer.MIN_VALUE ? 0 : pc[e[1]];
			res += Math.min(e[2], uv + vu);
		}		
		return res;
    }
}
__________________________________________________________________________________________________
sample 51628 kb submission
class Solution {
    public int reachableNodes(int[][] edges, int M, int N) {
        Node[] graph = new Node[N];
        for(int i=0;i<N;i++)
            graph[i]=new Node(i);
        
        for(int[] edge: edges){
            graph[edge[0]].addEdge(new Edge(edge[1],edge[2]));
            graph[edge[1]].addEdge(new Edge(edge[0],edge[2]));
        }
        Queue<Node> q = new LinkedList<>();
        graph[0].cost=0;
        q.add(graph[0]);
        
        while(!q.isEmpty()){
            Node node = q.remove();
            
            for(Edge edge:node.adj){
                int newCost = node.cost+edge.cost+1;
                if(newCost<graph[edge.dest].cost && newCost <= M){
                    graph[edge.dest].cost = newCost;
                    q.add(graph[edge.dest]);
                }
            }
        }
        int result = 1;
        for(int i=0;i<N;i++){
           System.out.println(graph[i].cost);
            if(graph[i].cost>0 && graph[i].cost<=M)
                result++;
        }
        for(int[] edge: edges){
            result+= Math.min(edge[2],Math.max(0, M-graph[edge[0]].cost)+Math.max(0, M -graph[edge[1]].cost));
        }
        
        return result;
    }
    
    public class Node{
        int node;
        int cost;
        List<Edge> adj;
        public Node(int n){
            node = n;
            adj = new ArrayList<Edge>();
            cost = Integer.MAX_VALUE;
        }
        public void addEdge(Edge e){
            adj.add(e);
        }
    }
    public class Edge{
        int dest;
        int cost;
        public Edge(int d, int c){
            dest = d;
            cost = c;
        }
    }
}
__________________________________________________________________________________________________
