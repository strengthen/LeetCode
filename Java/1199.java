__________________________________________________________________________________________________
class Solution {
	    public int minBuildTime(int[] a, int split) {
	        PriorityQueue<Integer> pq = new PriorityQueue<>();
	        for(int v : a)pq.add(v);
	        while(pq.size() >= 2){
	        	int x = pq.poll();
	        	int y = pq.poll();
	        	pq.add(y + split);
	        }
	        return pq.poll();
	    }
	}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
