__________________________________________________________________________________________________
class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<String, Integer> map = new HashMap<>();
        
        for (int[] row : matrix) {
            StringBuilder sb1 = new StringBuilder();
            StringBuilder sb2 = new StringBuilder();
            
            for (int r : row) {
                sb1.append(r);
                sb2.append(1 - r);
            }
            String str1 = sb1.toString();
            String str2 = sb2.toString();
            
            map.put(str1, map.getOrDefault(str1,0) + 1);
            map.put(str2, map.getOrDefault(str2,0) + 1);
        }
        
        int res = 0;
        for(int v : map.values()) res = Math.max(res, v);
        
        return res;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
