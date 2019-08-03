__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
   int[] mapping = new int[26];
    public boolean isAlienSorted(String[] words, String order) {
        for (int i = 0; i < order.length(); i++)
            mapping[order.charAt(i) - 'a'] = i;
        for (int i = 1; i < words.length; i++)
            if (compare(words[i - 1], words[i]) > 0)
                return false;
        return true;
    }

    int compare(String s1, String s2) {
        int n = s1.length(), m = s2.length(), cmp = 0;
        for (int i = 0, j = 0; i < n && j < m && cmp == 0; i++, j++) {
            cmp = mapping[s1.charAt(i) - 'a'] - mapping[s2.charAt(j) - 'a'];
        }
        return cmp == 0 ? n - m : cmp;
    }
}
__________________________________________________________________________________________________
sample 37168 kb submission
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] alienOrder = compute(order);
        for (int i=0; i<words.length-1; i++){
            if (!smaller(words[i], words[i+1], alienOrder)) return false;
        }
        return true;
    }
    
    private int[] compute(String order){
        int[] alienOrder = new int[26];
        for (int i=0;i<order.length();i++){
            int digit = order.charAt(i)-'a';
            alienOrder[digit] = i;
        }
        return alienOrder;
    }
    
    private boolean smaller(String word1, String word2, int[] alienOrder){
        int index = 0;
        while (index < word1.length() && index < word2.length()){
            int rank1 = alienOrder[word1.charAt(index)-'a'];
            int rank2 = alienOrder[word2.charAt(index)-'a'];
            if (rank1 > rank2) return false;
            else if (rank1 < rank2) return true;
            else index++;
        }
        return index == word1.length();
    }
}
__________________________________________________________________________________________________
