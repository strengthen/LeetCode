__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean isAnagram(String s, String t) {
        int[] frequency = new int[256];
        for(char c: s.toCharArray()){
            frequency[c]++;
        }
        for(char c: t.toCharArray()){
            frequency[c]--;
        }
        for(int i = 0; i < 256; i++){
            if(frequency[i] != 0){
                return false;
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 34180 kb submission
class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()){
            return false;
        }
        int[] alphas = new int[26];
        for(int ch : s.toCharArray()){
            alphas[ch - 'a']++;
        }
        for(int ch : t.toCharArray()){
            alphas[ch - 'a']--;
        }
        
        for(int i : alphas){
            if (i != 0){
                return false;
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
