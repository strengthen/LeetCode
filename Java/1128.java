__________________________________________________________________________________________________
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        Map<Long, Integer> map = new HashMap<>();
        for(int[] d : dominoes){
            long key = (Math.min(d[0], d[1]) * 1000 + Math.max(d[0], d[1]));
            if(!map.containsKey(key)){
                map.put(key, 0);
            }
            map.put(key, map.get(key) + 1);
        }
        int ret = 0;
        for(int v : map.values()){
            ret += v*(v-1)/2;
        }
        return ret;
    }
}	
__________________________________________________________________________________________________

__________________________________________________________________________________________________
