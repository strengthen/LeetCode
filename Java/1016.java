__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean queryString(String S, int N) {
        String bin = "";
        for (int i = 1; i <= N; i++) {
            bin = Integer.toBinaryString(i);
            if (!S.contains(bin)) {
                return false;
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 35292 kb submission
class Solution {
    public boolean queryString(String S, int N) {
        
        for (int i=1; i<=N; i++)
        {
            if (!S.contains(Integer.toBinaryString(i))) return false;
        }
       return true; 
    }
}
__________________________________________________________________________________________________
