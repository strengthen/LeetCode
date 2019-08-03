__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int minDeletionSize(String[] A) {
        int count = 0, len=A.length;
        boolean stop = true;
        boolean[] skip=new boolean[len];
        boolean[] prev =new boolean[len];
        for(int i=0;i<A[0].length();i++){
            System.arraycopy(skip, 0, prev, 0, len);
            
            stop = true;
            for(int j=1;j<len;j++){
                if((!skip[j])&&A[j].charAt(i)<A[j-1].charAt(i)){
                    count++;
                    stop=false;
                    System.arraycopy(prev, 0, skip, 0, len);
                    break;
                }
                if((!skip[j])&&A[j].charAt(i)==A[j-1].charAt(i)){
                    skip[j]=false;
                    stop=false;
                }else{
                    skip[j]=true;
                }
            }
            if(stop){
                return count;
            }
        }
        
        return count;
    }
}
__________________________________________________________________________________________________
sample 37452 kb submission
class Solution {
    public int minDeletionSize(String[] A) {
        int m = A.length;
        int n = A[0].length();
        
        int res = 0;
        Set<Integer> set = new HashSet<>();
        for (int i = 1; i < m && set.size() < n; i++) {
            String s1 = A[i-1];
            String s2 = A[i];
            for (int j = 0; j < n; j++) {
                if (set.contains(j)) {
                    continue;
                }
                char c1 = s1.charAt(j);
                char c2 = s2.charAt(j);
                if (c1 < c2) {
                    break;
                } 
                if (c1 > c2) {
                    set.add(j);
                    i = 0;
                    break;
                }
            }
        }
        
        return set.size();
    }
}
__________________________________________________________________________________________________
