__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public List<String> ambiguousCoordinates(String S) {
        List<String> res = new ArrayList();
        int n = S.length();
        for(int i = 1; i < n - 2; i++) {
            List<String> left = partition(S.substring(1, i + 1));
            List<String> right = partition(S.substring(i + 1, n - 1));
            for(String l : left) {
                for(String r : right) {
                    res.add('(' + l + ", " + r + ')');
                }
            }
        }
        return res;
    }
    
    private List<String> partition(String s)
    {
        List<String> parts = new ArrayList();
        int n = s.length();
        if(n == 0 || n > 1 && s.charAt(0) == '0' && s.charAt(n - 1) == '0') {
            return parts;
        }
        if(n > 1 && s.charAt(0) == '0') {
            parts.add("0." + s.substring(1));
            return parts;
        }
        parts.add(s);
        if(n == 1 || s.charAt(n - 1) == '0') {
            return parts;
        }
        for(int i = 1; i < n; i++) {
            parts.add(s.substring(0, i) + '.' + s.substring(i));
        }
        return parts;
    }
}
__________________________________________________________________________________________________
sample 38032 kb submission
class Solution {
    public List<String> ambiguousCoordinates(String S) {
        List<String> res = new ArrayList<>();
        for(int i = 1; i < S.length() - 2; i++){
            List<String> str1 = helper(S.substring(1, i + 1));
            List<String> str2 = helper(S.substring(i + 1, S.length() - 1));
            for(String s1 : str1){
                for(String s2 : str2){
                    res.add("(" + s1 + ", " + s2 + ")");
                }
            }
        }
        return res;
    }
    private List<String> helper(String s){
        List<String> res = new ArrayList<>();
        int n = s.length();
        if(n == 1){
            res.add(s);
            return res;
        }
        
        if(s.charAt(0) == '0'){
            if(s.charAt(n-1) != '0')  ////
                res.add("0." + s.substring(1));
            return res;
        }
        
        if(s.charAt(n-1) == '0'){
            res.add(s);
            return res;
        }
        res.add(s);
        for(int i = 1; i < n; i++){
            res.add(s.substring(0, i) + "." + s.substring(i));
        }
        return res;
    }
}
__________________________________________________________________________________________________
