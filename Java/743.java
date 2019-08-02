__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
public int networkDelayTime(int[][] times, int N, int K) {
        boolean[] visited = new boolean[N];//已访问节点数组
    	int[] dist = new int[N];//K节点到其他目标点的距离
    	Arrays.fill(dist, 100);
    	
    	
        //构建邻接矩阵 
        int[][] neighbors = new int[N][N];
        for(int i=0;i<N;i++)
        	for(int j=0;j<N;j++) {
        		neighbors[i][j] = i==j?0:10000;
        	}
        		
        for(int[] time:times){
            neighbors[time[0]-1][time[1]-1] = time[2];           
        }
        for(int i=0;i<N;i++) {
        	dist[i] = neighbors[K-1][i]; 
        	//System.out.println("distance "+dist[i]);
        	visited[i] = false;
        }
        visited[K-1] = true;
        dist[K-1]=0;
        		//System.out.println((i+1) +" " + (j+1) +" "+ neighbors[i][j]);
		//广度优先遍历  每次都是选择最小的距离的节点“先”加入
        for(int i=1;i<N;i++) {
        	int minDist = 10000;
        	int nearestNode = -1;
        	for(int j=0;j<N;j++) {
        		if(!visited[j] && dist[j] < minDist) {//遍历源点的所有节点，选择距离最小的邻接节点且未遍历过
        			minDist = dist[j];
        			nearestNode = j;
        			//System.out.println("minDist j "+minDist+" "+j);
        		}       			
        	}
        	if(nearestNode==-1)
        		return -1;
        	visited[nearestNode] = true;
            //从选出的节点出发到其余所有目标点的距离是否比从源点出发的距离小！！！！若是就替换
        	for(int j=0;j<N;j++){
        		//System.out.println("before "+dist[j]);
        		 if(neighbors[nearestNode][j] + minDist < dist[j]) {
        			 dist[j] = neighbors[nearestNode][j] + minDist;
        			 //System.out.println("after " +dist[j]);

        		 }
//        		if( times[j][2] + dist[times[j][0]] < dist[times[j][1]] )
//                    dist[times[j][1]] = times[j][2] + dist[times[j][0]];
        		 
        	}       	
        }
        int result = 0;
        for(int j = 0; j < N; j++) {
        	//System.out.println("last dist  "+ dist[j]);
        	result = Math.max(result, dist[j]);
        }
            
    return result;    
    }
}
__________________________________________________________________________________________________
sample 39692 kb submission
class Solution {
    Map<Integer, Integer> dist;
    public int networkDelayTime(int[][] times, int N, int K) {
        Map<Integer, List<int[]>> graph = new HashMap();
        for (int[] edge: times) {
            if (!graph.containsKey(edge[0]))
                graph.put(edge[0], new ArrayList<int[]>());
            graph.get(edge[0]).add(new int[]{edge[2], edge[1]});
        }
        for (int node: graph.keySet()) {
            Collections.sort(graph.get(node), (a, b) -> a[0] - b[0]);
        }
        dist = new HashMap();
        for (int node = 1; node <= N; ++node)
            dist.put(node, Integer.MAX_VALUE);

        dfs(graph, K, 0);
        int ans = 0;
        for (int cand: dist.values()) {
            if (cand == Integer.MAX_VALUE) return -1;
            ans = Math.max(ans, cand);
        }
        return ans;
    }

    public void dfs(Map<Integer, List<int[]>> graph, int node, int elapsed) {
        if (elapsed >= dist.get(node)) return;
        dist.put(node, elapsed);
        if (graph.containsKey(node))
            for (int[] info: graph.get(node))
                dfs(graph, info[1], elapsed + info[0]);
    }
}
__________________________________________________________________________________________________
