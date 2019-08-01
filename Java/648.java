__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    // only replace with the shortest root.
    public String replaceWords(List<String> dict, String sentence) {
        Trie trie = new Trie();
        for (String root : dict)
            trie.add(root);
        
        int start = 0;
        while (start < sentence.length()) {
            int end = sentence.indexOf(' ', start);
            if (end < 0)
                end = sentence.length();
            
            int len = trie.findPrefixLength(sentence, start, end);
            if (len > 0) {
                sentence = sentence.substring(0, start + len) + sentence.substring(end, sentence.length());
                end = start + len;
            }
            
            start = end + 1;
        }
        
        return sentence;
    }
    
    private class Trie {
        private Node root = new Node();
        
        public void add(String word) {
            Node node = root;
            for (char c : word.toCharArray()) {
                int index = c - 'a';
                if (node.children[index] == null)
                    node.children[index] = new Node();
                node = node.children[index];
            }
            node.isData = true;
        }
        
        public int findPrefixLength(String sentence, int start, int end /* exclusive */) {
            Node node = root;
            int len = 1;
            for (int i = start; i < end; i++, len++) {
                int index = sentence.charAt(i) - 'a';
                if (node.children[index] == null)
                    break;
                node = node.children[index];
                if (node.isData)
                    return len;
            }
            
            return -1;
        }
        
        private class Node {
            public boolean isData;
            public Node[] children = new Node[26];
        }
    }
}
__________________________________________________________________________________________________
sample 44580 kb submission
class Solution {
    public String replaceWords(List<String> dict, String sentence) {
        dict.sort((p1, p2) -> p1.length() - p2.length());
        StringBuilder sb = new StringBuilder();
        String[] words = sentence.split(" ");
        for (String word: words) {
            if (sb.length() > 0) {
                sb.append(" ");
            }
            boolean found = false;
            for (String item: dict) {
                if (word.startsWith(item)) {
                    sb.append(item);
                    found = true;
                    break;
                }
            }
            if (!found) {
                sb.append(word);
            }
        }
        return sb.toString();
    }
}
__________________________________________________________________________________________________
