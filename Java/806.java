__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[] numberOfLines(int[] widths, String S) {
        int len=S.length();
        int curr_width=0;
        int lines=1;
        for(int i=0;i<len;i++){
            if(curr_width + widths[(int)(S.charAt(i) - 'a')]>100){
                lines++;
                curr_width=widths[(int)(S.charAt(i) - 'a')];
            }else{
                curr_width+=widths[(int)(S.charAt(i) - 'a')];
            }
        }
        int[] res=new int[2];
        res[0]=lines;
        res[1]=curr_width;
        return res;
    }
}
__________________________________________________________________________________________________
sample 36868 kb submission
class Solution {
    public int[] numberOfLines(int[] widths, String S) {
        if(S == null || S.length() == 0) {
            return new int[2];
        }
        int count = 0;
        int line = 1;
        
        for(int i = 0; i < S.length(); i++) {
            count += widths[S.charAt(i) - 'a'];
            if(count > 100) {
                line++;
                count = widths[S.charAt(i) - 'a'];
            }
        }
        return new int[]{line, count};
    }
}
__________________________________________________________________________________________________
