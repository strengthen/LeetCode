__________________________________________________________________________________________________
sample 17 ms submission
class Solution {
    public int numMatchingSubseq(String S, String[] words) {
        int r = 0;
        HashSet<String> ps = new HashSet();
        HashSet<String> po = new HashSet();
        for (String word: words){
            if (ps.contains(word)){
                r++;
                continue;
            }
            if (po.contains(word)){
                continue;
            }
            if (isSubsequence(S, word)){
                r++;
                ps.add(word);
            } else{
                po.add(word);
            }
        }
        return r;
    }
    
    private boolean isSubsequence(String s, String sub){
        int l1 = s.length();
        int l2 = sub.length();
        int p1 = 0,p2 = 0;
        // while(p2 < l2){
        //     if (l1 - p1 < l2 - p2){
        //         return false;
        //     }
        //     if (s.charAt(p1) != sub.charAt(p2)){
        //         p1++;
        //         continue;
        //     }
        //     p1++;
        //     p2++;
        // }
        while(p1 < l1 && p2 < l2){
            if (s.charAt(p1) == sub.charAt(p2)){
                p1++;
                p2++;
            } else{
                p1++;
            }
        }
        return l2 == p2;
    }
}
__________________________________________________________________________________________________
sample 38664 kb submission
class Solution {
    
    static class WordNode {
        final String word;
        int index = 0;
        WordNode next;
        WordNode(String word) {
            this.word = word;
        }
    }
    
    public int numMatchingSubseq(String S, String[] words) {
        WordNode[] nodes = new WordNode[26];
        for(String word : words) {
            int charIndex = word.charAt(0) - 'a';
            WordNode node = new WordNode(word);
            node.next = nodes[charIndex];
            nodes[charIndex] = node;
        }
        
        int numMatch = 0;
        for(char c : S.toCharArray()) {
            int charIndex = c - 'a';
            WordNode node = nodes[charIndex];
            nodes[charIndex] = null;
            for(WordNode next; node != null; node = next) {
                next = node.next;
                String word = node.word;
                int matchIndex = ++node.index;
                if(matchIndex == word.length()) {
                    numMatch++;
                } else {
                    int nextCharIndex = word.charAt(matchIndex) - 'a';
                    node.next = nodes[nextCharIndex];
                    nodes[nextCharIndex] = node;
                }
            }
        }
        return numMatch;
    }
}
__________________________________________________________________________________________________
