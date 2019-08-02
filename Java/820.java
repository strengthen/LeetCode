__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public class Trie{
        Trie[] children;
        int count;
        public Trie(){
            children = new Trie[26];
            count = 0;
        }
    }
    Trie root;
    int res = 0;
    public int minimumLengthEncoding(String[] words) {
        root = new Trie();
        for(String word:words){
            add(word);
        }
        return res;
    }
    public void add(String word){
        Trie cur = root;
        boolean flag = false;
        for(int i = word.length()-1; i >= 0; i--){
            char c = word.charAt(i);
            if(cur.children[c-'a'] == null){
                cur.children[c-'a'] = new Trie();
                flag = true;
            }
            cur = cur.children[c-'a'];
            if(cur.count > 0 && i != 0){
                res -= cur.count+1;
                cur.count = 0;
            }
        }
        if(flag == false) return;
        cur.count = word.length();
        res += word.length()+1;
    }
}
__________________________________________________________________________________________________
sample 38328 kb submission
class Solution {
    public int minimumLengthEncoding(String[] words) {
        Node root = new Node();
        int result = 0;
        Arrays.sort(words, (o1, o2) -> Integer.compare(o2.length(), o1.length()));
        for (String word : words) {
            Node cur = root;
            boolean first = false;
            for (int i = word.length() - 1; i >= 0; --i) {
                char c = word.charAt(i);
                if (cur.child[c - 'a'] == null) {
                    cur.child[c - 'a'] = new Node();
                    first = true;
                }
                cur = cur.child[c - 'a']; 
            }
            if (first == true) {
                result += word.length() + 1;
            }
            
        }
        
        return result;   
    }
    
    class Node {
        Node[] child = new Node[26];
    }
}
__________________________________________________________________________________________________
