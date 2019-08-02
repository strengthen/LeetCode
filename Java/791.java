__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public String customSortString(String S, String T) {
        
        int[] counts = new int[26];
        
        for(char c : T.toCharArray()){
            counts[c - 'a']++;
        }
        
        StringBuilder res = new StringBuilder();
        
        for(int i = 0; i<S.length(); i++){
            while(counts[S.charAt(i) -'a']-- > 0){
                res.append(S.charAt(i));
            }
        }
        
        for(int i = 0; i<counts.length; i++){
            while(counts[i]-- > 0){
                res.append((char)(i + 'a'));
            }
        }
        
        return res.toString();
    }
}
__________________________________________________________________________________________________
sample 34308 kb submission
class Solution {
    public String customSortString(String S, String T) {
        int[] order = new int[26];
        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            order[c-'a'] = i+1;
        }
        List<Character> li = new ArrayList<>();
        for (int i = 0; i < T.length(); i++) {
            li.add(T.charAt(i));
        }
        li.sort((a, b) -> (order[a-'a'] - order[b-'a']));
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < li.size(); i++) {
            sb.append(li.get(i));
        }
        return sb.toString();
    }
}
__________________________________________________________________________________________________
