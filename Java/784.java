__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
     public List<String> letterCasePermutation(String S) {
        List<String> list = new ArrayList<>();
        helper(S.toCharArray(),0,list);
        return list;

    }
    private void helper(char[] a, int pos, List<String> res){
        if(pos==a.length){
            res.add(new String(a));
            return;
        }

        if(Character.isLetter(a[pos])) {
            a[pos] = Character.toLowerCase(a[pos]);
            helper(a, pos+1, res);
            a[pos] = Character.toUpperCase(a[pos]);
        }
        helper(a, pos+1, res);
    }
}
__________________________________________________________________________________________________
sample 35924 kb submission
import static java.util.stream.Collectors.toList;
class Solution {
    public List<String> letterCasePermutation(String s) {        
        
        List<StringBuilder> result = new ArrayList<>();
        result.add(new StringBuilder());
        
        for (char c: s.toCharArray()){
            
            char lower = Character.toLowerCase(c);
            char upper = Character.toUpperCase(c);
                
            if (lower == upper){
                 for (StringBuilder sb: result){
                     sb.append(lower);
                 }
            } else {
                 List<StringBuilder> withUpper = new ArrayList<>();
                 for (StringBuilder sb: result){
                     withUpper.add(new StringBuilder(sb).append(upper));
                     sb.append(lower);
                 }
                result.addAll(withUpper);
            }  
        }
        
        return result.stream().map(sb -> sb.toString()).collect(toList());
        
        
    }
}
__________________________________________________________________________________________________
