__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
   
        
       public String reverseWords(String s) {
    
        StringBuilder sb = new StringBuilder();
            int i = s.length() - 1;
            while(i >= 0){
                if(s.charAt(i) == ' '){
                    i--;
                    continue;
                }
                int start = s.lastIndexOf(' ', i);
                sb.append(' ');
                sb.append(s.substring(start + 1, i + 1));
                i = start - 1;
            }
            if(sb.length() > 0){
                sb.deleteCharAt(0);    
            }

            return sb.toString();
    }
}
__________________________________________________________________________________________________
sample 34996 kb submission
public class Solution {
    public String reverseWords(String s) {
        String strs[] = s.trim().split("\\s+");
        StringBuilder sb = new StringBuilder();
        for(int i=strs.length-1;i>=0;i--){
            sb.append(strs[i]).append(" ");
        }
        
        if(sb.length()>0)
          sb.setLength(sb.length()-1);
        return sb.toString();
        
    }
}
__________________________________________________________________________________________________
