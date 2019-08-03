__________________________________________________________________________________________________
sample 24 ms submission
class Solution {
    public int minAreaRect(int[][] points) {
        
        int result = -1;
        for (int[] p1 : points) {
            for (int[] p2 : points) {
                if (p1[0] == p2[0] || p1[1] == p2[1]) continue;
                int area = Math.abs(p1[0] - p2[0]) * Math.abs(p1[1] - p2[1]);
                if (result != -1 && area > result) continue;
                
                boolean foundP3 = false;
                boolean foundP4 = false;
                for (int[] p3 : points) {
                    if (p3[0] == p1[0] && p3[1] == p2[1]) {
                        foundP3 = true;
                        break;
                    }
                }
                
                for (int[] p4 : points) {
                    if (p4[0] == p2[0] && p4[1] == p1[1]) {
                        foundP4 = true;
                        break;
                    }
                }
                
                if (foundP3 && foundP4) result = (result == -1) ? area : Math.min(result, area);
            }
        }
        return (result == -1) ? 0 : result;
    }
}
__________________________________________________________________________________________________
sample 39060 kb submission
class Solution {
     Map<Integer, TreeSet<Integer>> map = new LinkedHashMap<>();
    public int minAreaRect(int[][] points) {
       
        int result = Integer.MAX_VALUE;
        Arrays.sort(points, (a, b) -> a[0] - b[0]);
        List<Integer> xList = new ArrayList<>();
        for(int[] point : points){
            map.computeIfAbsent(point[0], k-> new TreeSet<Integer>()).add(point[1]);
        }
        
        map.forEach((k,v) ->{
            if(v.size() >= 2) xList.add(k);
        });
      
        
        for(int i=0; i< xList.size(); i++){
            for(int j= i+1; j< xList.size();j++){
                result = Math.min(result, helper(xList.get(i), xList.get(j)));
            }
        }
        return result == Integer.MAX_VALUE?0: result;
    }
    
    public int helper(int i, int j){
        int res = Integer.MAX_VALUE;
        Integer first =null, second = null;
        for(Integer a : map.get(i)){
            if(map.get(j).contains(a)){
                second = first;
                first = a;
                if(second != null) res = Math.min(res, (first - second) *(j-i));
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
