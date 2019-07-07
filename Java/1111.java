__________________________________________________________________________________________________
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        char[] s = seq.toCharArray();
        int[] hs = new int[s.length+1];
        for(int i = 0;i < s.length;i++){
            hs[i+1] = hs[i] + (s[i] == '(' ? 1 : -1);
        }
        int max = -1;
        List<Integer> poss = new ArrayList<>();
        for(int i = 0;i < s.length;i++){
            if(hs[i] > max){
                max = hs[i];
                poss.clear();
                poss.add(i);
            }else if(hs[i] == max){
                poss.add(i);
            }
        }
        int[] ret = new int[s.length];
        for(int pos : poss){
            ret[pos] = ret[pos-1] = 1;
        }
        if(poss.size() * 2 == s.length){
            ret[poss.get(0)] = 0;
            ret[poss.get(0)-1] = 0;
        }
        return ret;
    }
}	
__________________________________________________________________________________________________

__________________________________________________________________________________________________
