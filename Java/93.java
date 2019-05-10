__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList();
        if (s.length() > 3 && s.length() < 13)
            help(s, new char[s.length()+3], 0, ans, 0, 0);
        return ans;
    }
    
    void help(String s, char[] cs, int count, List<String> ans, int start, int i){
        int digit = 0;
        for (int l = start; l < 3+start && l < s.length(); l++){
            digit = 10*digit + (s.charAt(l)-'0');
            if (digit > 255) return;
            cs[i++] = s.charAt(l);
            if (count == 3){
                if (l+1==s.length()) ans.add(new String(cs));
            }else{
                cs[i] = '.';
                help(s, cs, count+1, ans, l+1, i+1);
            }
            if (digit == 0) return;
        }
    }
}
__________________________________________________________________________________________________
sample 34636 kb submission
public class Solution{
public List<String> restoreIpAddresses(String s) {
    List<String> result = new ArrayList<>();
    int[] path =new int[4];
    helper(result,s,0,path,0);
    return result;
}

void helper(List<String> acc, String s, int idx, int[] path,  int segment){  
    if(segment==4&idx==s.length()){
        acc.add(path[0]+"."+path[1]+"."+path[2]+"."+path[3]);
        return;
    }
    if(segment==4 || idx==s.length()){
        return;
    }
    for(int len=1;len<=3&&idx+len<=s.length();len++){
        int val=Integer.parseInt(s.substring(idx,idx+len));
        if(val>255||len >= 2  && s.charAt(idx) == '0'){
            break;
        }
        path[segment]=val;
        helper(acc,s,idx+len,path,segment+1);
        path[segment]=-1;
    }
 }
}
__________________________________________________________________________________________________
