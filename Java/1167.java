__________________________________________________________________________________________________
class Solution {
    public int connectSticks(int[] sticks) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int v : sticks){
            pq.add(v);
        }
        int ans = 0;
        while(pq.size() > 1){
            int x = pq.poll();
            int y = pq.poll();
            ans += x + y;
            pq.add(x+y);
        }
        return ans;
    }
}	
__________________________________________________________________________________________________

__________________________________________________________________________________________________
