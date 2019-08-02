__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        int[] dist = new int[n];

        Arrays.fill(dist, 2000000000);

        dist[src] = 0;

        for (int i = 0; i <= K; i++) {

            countUpdate(dist, flights);

        }

        return dist[dst] == 2000000000 ? -1 : dist[dst];

    }

    private void countUpdate(int[] dist, int[][] flights) {
        int[] original_dist = Arrays.copyOf(dist, dist.length);

        for (int[] flight: flights) {

            int mid   =  flight[0];
            int dest  =  flight[1];
            int price =  flight[2];

            if (dist[dest] > original_dist[mid] + price) {
                dist[dest] = original_dist[mid] + price;
            }

        }

    }
}
__________________________________________________________________________________________________
sample 34552 kb submission
class Solution {
    
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        int[][] graph = new int[n][n];
        //HashMap<Integer, List<Integer>> map= 
        
        for (int[] flight: flights)
            graph[flight[0]][flight[1]] = flight[2];

        Map<Integer, Integer> best = new HashMap();

        PriorityQueue<int[]> heap = new PriorityQueue<int[]>((a, b) -> a[0] - b[0]);
        heap.add(new int[]{0, 0, src});//cost, k, src

        while (!heap.isEmpty()) {
            int[] u_vertex = heap.remove();
            int cost = u_vertex[0];
            int k = u_vertex[1];
            int u = u_vertex[2];
            
            if (k > K+1 || cost > best.getOrDefault( k*1000 + u, Integer.MAX_VALUE))   continue;
            if (u == dst)   return cost;

            for (int nei = 0; nei < n; nei++) {
                if (graph[u][nei] > 0) {
                
                    int newcost = cost + graph[u][nei];
                    if (newcost < best.getOrDefault( (k+1)*1000 + nei, Integer.MAX_VALUE)) {
                        best.put( (k+1)*1000 + nei, newcost);
                        heap.add(new int[]{newcost, k+1, nei});

                    }
                }
            }
        }

        return -1;
    }
}
__________________________________________________________________________________________________
