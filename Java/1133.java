__________________________________________________________________________________________________
class Solution {
    public int largestUniqueNumber(int[] A) {
        Set<Integer> one = new HashSet<>();
        Set<Integer> twice = new HashSet<>();
        for(int v : A){
            if(!one.add(v)){
                twice.add(v);
            }
        }
        int max = -1;
        for(int v : A){
            if(!twice.contains(v)){
                max = Math.max(max, v);
            }
        }
        return max;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
