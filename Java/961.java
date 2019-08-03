__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int repeatedNTimes(int[] A) {
        
        HashSet<Integer> table = new HashSet<Integer>();
        
        for (int i=0; i<A.length;i++)
        {
            if(!table.add(A[i]))
            {
                return A[i];
            }
        }
        
        return -1;        
    }
}
__________________________________________________________________________________________________
sample 37284 kb submission
class Solution {
    public int repeatedNTimes(int[] A) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (Integer i: A){
            if (map.containsKey(i)){
                int values = map.get(i);
                values++;
                map.put(i, values);
            }else{
                map.put(i, 1);
            }
        }
        int n = A.length / 2;
        return map.keySet()
                    .stream()
                    .filter(key-> n == map.get(key))
                    .findFirst().get();
    }
}
__________________________________________________________________________________________________
