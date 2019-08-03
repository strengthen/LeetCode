__________________________________________________________________________________________________
sample 1 ms submission
class Solution 
{
    public int numPairsDivisibleBy60(int[] time) {
             int[] q = new int[501];
        for (int t: time)
            q[t]++;
        
         
        int s = 0;
        for (int i = 0; i < q.length; i++) {
            if (q[i] == 0)
                continue;
            
            int f = - i % 60;
            while((f+=60) <= i) {
                if (q[f] == 0)
                    continue;
                if (i != f)
                    s += q[f] * q[i];
                else {
                    s += q[i] * (q[i] - 1) / 2;
                }
            }
        }
        
        return s;
    }
}
__________________________________________________________________________________________________
sample 38884 kb submission
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        HashMap<Integer,Integer> pairs = new HashMap<>();
        int result = 0;
        for(int t : time){
            int mod = t % 60;
            int pairVal = (60 - mod) % 60;
            if(pairs.containsKey(pairVal)){
               result += pairs.get(pairVal);
            }
            //int val = pairs.containsKey(mod) ? pairs.get(mod) : 0;
            //pairs.put(mod,val+1);
            pairs.merge(mod,1,Integer::sum);
        }
        return result;
    }
}
__________________________________________________________________________________________________
