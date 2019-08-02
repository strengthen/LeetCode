__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        List<List<Integer>> res = new ArrayList();
        int i = 0,N = S.length();
        for(int j = 0;j < N;j++){
            if(j == N-1 || S.charAt(j)!=S.charAt(j+1)){
               if(j - i + 1 >=3){
                   res.add(Arrays.asList(new Integer[]{i,j}));
               }
               i = j + 1;
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 37332 kb submission
class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
       
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i< S.length(); i++){
           
                List<Integer> list = new ArrayList<>();
               
                int j = i+1;
                while (j < S.length() && S.charAt(j) == S.charAt(i)){
                    j++;
                }
            if (j-1 - i>= 2){
                list.add(i);
                list.add(j-1);
                res.add(list);
            
                i = j -1;
            } else{
               continue; 
            }
            
        }
        return res;
    }
}
__________________________________________________________________________________________________
