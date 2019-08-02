__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int ret = 0, maxIdx = 0;
        for(int idx : difficulty) 
            maxIdx = Math.max(maxIdx, idx);

        int[] profits = new int[maxIdx+1];
        
        for(int i=0;i<difficulty.length;i++){
            profits[difficulty[i]] = Math.max(profit[i], profits[difficulty[i]]);                                    
        }
        
        int tmpMax = 0;
        for(int i=1;i< profits.length;i++){
            tmpMax = Math.max(tmpMax, profits[i]);
            profits[i] = tmpMax;
        }
        
        for(int idx : worker){
            if(idx > maxIdx) ret+=profits[maxIdx];
            else ret+=profits[idx];
        }
        
        return ret;
    }
}
__________________________________________________________________________________________________
sample 38688 kb submission
class Solution {
    static class Task {
        int diff;
        int profit;
        int id;
        
        public Task(int id, int d, int p) {
            this.id = id;
            this.diff = d;
            this.profit = p;
        }
    }
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        if(difficulty.length == 0 || worker.length == 0) return 0;
        
        List<Task> list = new ArrayList<>();
        for(int i = 0; i < difficulty.length; i ++) {
            Task t = new Task(i, difficulty[i], profit[i]);
            list.add(t);
        }
        
        Collections.sort(list, (a, b) -> {
            if(a.profit == b.profit) return a.diff - b.diff;
            return b.profit - a.profit;
        });
        Arrays.sort(worker);
        int j = 0, res = 0;
        for(int i = worker.length - 1; i >= 0; i --) {
            while(j < list.size() && list.get(j).diff > worker[i]) j ++;
            if(j == list.size()) break;
            res += list.get(j).profit;
        }
        return res;
    }
}
__________________________________________________________________________________________________
