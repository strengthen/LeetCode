__________________________________________________________________________________________________
sample 2 ms submission
class Solution {

    public int findMaximizedCapital(int k, int W, int[] Profits, int[] Capital) {
        if (Profits.length <= k) {     // no need to pick k projects
            for (int p : Profits) W += p;
            return W;
        }

        for (int i = 0; i < k; i++) {
            int maxIndex = -1, maxProfit = 0;
            for (int j = 0; j < Capital.length; j++) {
                if (W >= Capital[j] && Profits[j] > maxProfit) {
                    maxIndex = j;
                    maxProfit = Profits[j];
                }
            }
            if (maxIndex == -1) break;
            Profits[maxIndex] = -Profits[maxIndex];
            W += maxProfit;
        }

        return W;
    }
}
__________________________________________________________________________________________________
sample 42276 kb submission
class Solution {
    public int findMaximizedCapital(int k, int W, int[] Profits, int[] Capital) {
        PriorityQueue<int[]> pq=new PriorityQueue<>((a,b)->(b[0]-a[0]));
        for(int i=0;i<Capital.length;i++)
        {
            int cap=Capital[i];
            int pro=Profits[i];
            pq.add(new int[]{pro,cap});
        }
        while(k-->0)
        {
            int size=pq.size();
            HashSet<int[]> set=new HashSet<>();
            while(!pq.isEmpty()&&pq.peek()[1]>W)
                set.add(pq.poll());
            if(size==set.size()) break;
            int[] temp=pq.poll();
            pq.addAll(set);
            W+=temp[0];
        }
        return W;
    }
}
__________________________________________________________________________________________________
