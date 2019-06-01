__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int maxProduct(String[] words) {
        int len = words.length;
        int[] masks = new int[len];
        for(int i = 0; i < len; ++i){
            String word = words[i];
            int mask = 0;
            for(int j = word.length() - 1; j >= 0; --j){
                mask |= 1 << (word.charAt(j) - 'a');
            }
            masks[i] = mask;
        }
        int maxProduct = 0;
        for(int i = len - 1; i > 0; --i){
            int mask = masks[i], wordLen = words[i].length();
            for(int j = i - 1; j >= 0; --j){
                if((mask & masks[j]) == 0){
                    int product = wordLen * words[j].length();
                    if(product > maxProduct){
                        maxProduct = product;
                    }
                }
            }
        }
        return maxProduct;
    }
}
__________________________________________________________________________________________________
sample 35376 kb submission
class Solution {
    public int maxProduct(String[] words) {
        if (words == null || words.length <= 1) return 0;
        int[] check = new int[words.length];
        
        Arrays.sort(words, (a,b) -> b.length() - a.length());
        
        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                check[i] |= 1 << (words[i].charAt(j) - 'a');
            }        
        }
        
        int max = 0;
        for (int i = 0; i < words.length -1; i++) {
            if (words[i].length() * words[i].length() < max) break;
            for (int j = i+1; j < words.length; j++) {
                if (words[i].length() * words[j].length() <= max) break;
                if ((check[i]&check[j]) == 0 ) max = Math.max(max, words[i].length() * words[j].length());
            }
        }
        return max;
    }
}
__________________________________________________________________________________________________
