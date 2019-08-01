__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        int k=nums.size();
        if(k == 1) {
            return new int[] {nums.get(0).get(0), nums.get(0).get(0)};
        }
        int[] res = new int[2]; 
        int[] dp = new int[k];
        
        int minK = 0;
        int minI = 0;
        int minVal = nums.get(0).get(0);
        
        int maxK = 0;
        int maxI = 0;
        int maxVal = nums.get(0).get(0);;
        
        for(int i =0;i<k;i++) {
            int val = nums.get(i).get(0);
            dp[i]=0;
            if(val< minVal) {
                minVal=val;
                minK = i;
                minI = 0;
            }
            if(val>maxVal) {
                maxVal = val;
                maxK=i;
                maxI = 0;
            }
        }
        res = new int[]{minVal, maxVal};
        
        boolean done = false;
        while(!done) {
            List<Integer> nextNums = nums.get(minK);
            dp[minK]++;
            if(dp[minK]==nextNums.size()) {
                done=true;
                continue;
            }
            int next = nextNums.get(dp[minK]);
            minVal=next;
            for(int i = 0;i<k ;i++) {
                nextNums = nums.get(i);
                int currIdx = dp[i];
                int currSize = nextNums.size();
                while(currIdx<currSize && nextNums.get(currIdx)<=next) {
                    dp[i]=currIdx;
                    currIdx++;
                } 
                int val = nextNums.get(dp[i]);
                if(val< minVal) {
                    minVal=val;
                    minK = i;
                    minI = 0;
                }
                if(val>maxVal) {
                    maxVal = val;
                    maxK=i;
                    maxI = 0;
                }
            }
                if((maxVal-minVal)<(res[1]-res[0]))
                    res = new int[]{minVal, maxVal};
        }
        
        return res;
    }
}
__________________________________________________________________________________________________
sample 42076 kb submission
class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b)->nums.get(a[0]).get(a[1]) - nums.get(b[0]).get(b[1]));
        int size = nums.size();
        int range = Integer.MAX_VALUE, max = 0;
        for(int i = 0; i < nums.size(); i++){
            
            max = Math.max(nums.get(i).get(0), max);            
            pq.offer(new int[]{i, 0, nums.get(i).get(0)});
        }
        int start = 0, end = max;
        while(pq.size() == size){
            int[] cur = pq.poll();
            int i = cur[0], j = cur[1], v = cur[2];
            if(max-v < range){
                start = v;
                end = max;
                range = end-start;
            }
            if(j < nums.get(i).size()-1){                
                max = Math.max(max, nums.get(i).get(j+1));
                cur[1]++;
                cur[2] = nums.get(i).get(j+1);
                pq.offer(cur);
            }
        }
        return new int[]{start, end};
    }
}
__________________________________________________________________________________________________
