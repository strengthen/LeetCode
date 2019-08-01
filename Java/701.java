__________________________________________________________________________________________________
sample 87 ms submission
class Solution {
    Random random; 
    HashMap<Integer, Integer> mp;
    ArrayList<Integer> arr; 
    int n ; int pointer;
    public Solution(int N, int[] blacklist) {
        random = new Random(123456734567L); 
        arr = new ArrayList<Integer>();
        mp = new HashMap<>();
        for(int i = 0 ; i < blacklist.length; i++)
            mp.putIfAbsent(blacklist[i], 0 );
        n = N;
        pointer = 0;
    }
    
    public int pick() {
       if(pointer == n)pointer = 0 ;
       if(mp.size() > n - mp.size()){
            if(arr.size() == 0){
                for(int i = 0 ; i < n ; i++)if(!mp.containsKey(i)){arr.add(i);}
            }
            for(int i = pointer ; i < arr.size() ; i++){
                    pointer = i+1;
                    return arr.get(i);
            }
            for(int i = 0 ; i < pointer; i++){
                pointer = i+1;
                return arr.get(i);
            }
       }
       if(pointer == n)pointer = 0 ;
       for(int i = pointer ; i < n; i++){
           if(!mp.containsKey(i)){
               pointer = i+1;
               return i;
           }
       }
       for(int i = 0 ; i < pointer; i++){
            if(!mp.containsKey(i)){
               pointer = i+1;
               return i;
           }
       }
        return -1;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
__________________________________________________________________________________________________
sample 53204 kb submission
class Solution {
    
    // N: [0, N)
    // B: blacklist
    // B1: < N
    // B2: >= N
    // M: N - B1
    int M;
    Random r;
    Map<Integer, Integer> map;

    public Solution(int N, int[] blacklist) {
        map = new HashMap();
        for (int b : blacklist) // O(B)
            map.put(b, -1);
        M = N - map.size();
        
        for (int b : blacklist) { // O(B)
            if (b < M) { // re-mapping
                while (map.containsKey(N - 1))
                    N--;
                //Important to note this remapping using values
                //Suppose N=10, blacklist=[3, 5, 8, 9], re-map 3 and 5 to 7 and 6
                map.put(b, N - 1);
                N--;
            }
        }
        
        r = new Random();
    }
    
    public int pick() {
        int p = r.nextInt(M);
        if (map.containsKey(p))
            return map.get(p);
        return p;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
__________________________________________________________________________________________________
