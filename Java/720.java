__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    private class TrieNode {
        TrieNode[] children;
        String word;
        
        TrieNode(){
            children = new TrieNode[26];
        }
    }
    public String longestWord(String[] words) {
        TrieNode root = new TrieNode();
        root.word = "";
        for (String word : words){
            addWord(word, root);
        }
        
        return findLongestWord(root);
    }
    
    private String findLongestWord(TrieNode node){
        String maxFound = node.word;
        for (int i = 0; i < 26; i++){
            if (node.children[i] != null && node.children[i].word != null){
                String found = findLongestWord(node.children[i]);
                if (found != null && found.length() > maxFound.length()){
                    maxFound = found;
                }
            }
        }
        
        return maxFound;
    }
    
    private void addWord(String word, TrieNode node){
        for (int i = 0; i < word.length(); i++){
            int index = (int) (word.charAt(i) - 'a');
            if (node.children[index] == null){
                node.children[index] = new TrieNode();
            }
            node = node.children[index];
        }
        
        node.word = word;
    }  
}
__________________________________________________________________________________________________
sample 35896 kb submission
class Solution {
    public String longestWord(String[] words) {
        Arrays.sort(words, Comparator.comparingInt(String::length));
        HashSet<String> set = new HashSet();
        for(String w:words)
            set.add(w);
        String ans ="";
        for (int i=words.length-1;i>=0;i--){
         
    if(words[i].length()<ans.length()) return ans;
            if(validWord(words[i],set)){
                if((words[i].length()>ans.length())||(words[i].length()==ans.length()&&words[i].compareTo(ans)<0)){
                    ans=words[i];
                }
            }
        }
 
                   return ans;
                   }
    
    public boolean validWord(String w,HashSet set){
        
       
             
     if (w.length()==1) return true;
        for (int k = w.length()-1; k >=1 ; k--) {
               if (!set.contains(w.substring(0, k))) {
                        return false;
                    }
        }
        return true;   
    }
}
__________________________________________________________________________________________________
