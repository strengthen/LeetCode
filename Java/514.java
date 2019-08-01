__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public int findRotateSteps(String ring, String key) {
        if (ring == null) return 0;
        List<Integer>[] r = new List[26];
        for (int i = 0; i < 26; i++) {
            r[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < ring.length(); i++) {
            r[ring.charAt(i) - 'a'].add(i);
        }
        int[][] cache = new int[ring.length()][key.length()];
        return search(r, ring.length(), 0, key, 0, cache);
    }
    
    private int search(List<Integer>[] ring, int len, int p, String key, int index, int[][] cache) {
        if (index == key.length()) return 0;
        if (cache[p][index] > 0) return cache[p][index];
        char c = key.charAt(index);
        List<Integer> indices = ring[c - 'a'];
        int min = Integer.MAX_VALUE;
        for (int i: indices) {
            int oneDir = Math.abs(p - i);
            int otherDir = len - oneDir;
            min = Math.min(min, 1 + Math.min(oneDir, otherDir) + search(ring, len, i, key, index + 1, cache));
        }
        cache[p][index] = min;
        return min; 
    }
}
__________________________________________________________________________________________________
sample 36976 kb submission

class Solution {
    public int findRotateSteps(String ring, String key) {
        char[] ringArr = ring.toCharArray();
        char[] keyArr = key.toCharArray();
        
        return dfs(ringArr, keyArr, 0, 0, new int[ringArr.length][keyArr.length]);
    }
    
    
    private  int dfs(char[] ring, char[] target, int targetIndex, int ringIndex, int[][] memo){
        if(targetIndex == target.length)    return 0;
        
        if(memo[ringIndex][targetIndex] != 0)   return memo[ringIndex][targetIndex];
        
        int min = Integer.MAX_VALUE;
        for(int i = 0;i < ring.length;i++){
            if(ring[i] != target[targetIndex])  continue;
            
            int dif = Math.abs(i - ringIndex);
            dif = Math.min(dif, ring.length - dif);
            int distance =  1 + dif + dfs(ring, target, targetIndex + 1, i, memo);
            min = Math.min(min, distance);            
        }
        
        memo[ringIndex][targetIndex] = min;
        return min;
    }
}
__________________________________________________________________________________________________
