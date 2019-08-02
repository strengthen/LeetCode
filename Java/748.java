__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String shortestCompletingWord( String licensePlate, String[] words ){
        
        int ALPHABET_LENGTH = 26;
        int[] record = new int[ALPHABET_LENGTH];
        int nLettersInPlate = 0;
        
        for( int i = 0; i < licensePlate.length(); i++ ){
            if( licensePlate.charAt(i) >= 'a' && licensePlate.charAt(i) <= 'z' ){
                record[ licensePlate.charAt(i) - 'a' ]++;
                nLettersInPlate++;
            }
            else if( licensePlate.charAt(i) >= 'A' && licensePlate.charAt(i) <= 'Z'){
                record[ licensePlate.charAt(i) - 'A']++;
                nLettersInPlate++;
            }
        }
        
        int idx = -1;
        for( int i = 0; i < words.length; i++ ){
            if( contains( words[i], record ) ){
                if( idx != -1 ){
                    idx = ( words[i].length() < words[idx].length() ) ? i : idx;
                    if( words[idx].length() == nLettersInPlate ){
                        return words[idx];
                    }
                }
                else{
                    idx = i;
                }
            }
        }
        return words[idx];
    }
    
    
    public boolean contains( String s, int[] record ){
        int[] kopi = Arrays.copyOf( record, record.length );
        
        for( int i = 0; i < s.length(); i++ ){
            kopi[ s.charAt(i) - 'a' ]--;
        }
        
        for( int i = 0; i < kopi.length; i++){
            if( kopi[i] > 0){
                return false;
            }
        }
        return true;        
    }
}
__________________________________________________________________________________________________
sample 37272 kb submission
class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        int[] ref = new int[26];
        for(char c : licensePlate.toLowerCase().toCharArray()) {
            if(c >= 'a' && c <= 'z') {
                ref[c - 'a']++;
            }
        }
        int[] sCount = new int[26];
        String ret = null;
        int length = Integer.MAX_VALUE;
        for(String w : words) {
            for(int i = 0; i < sCount.length; i++) {
                sCount[i] = 0;
            }
            for( char c : w.toLowerCase().toCharArray()) {
                if(c >= 'a' && c <= 'z') {
                    sCount[c-'a']++;
                }
            }
            boolean match = true;
            for(int i = 0; i < ref.length; i++) {
                if(ref[i] > sCount[i]) {
                    match = false;
                    break;
                }
            }
            if(match) {
                if(length > w.length()) {
                    ret = w;
                    length = w.length();
                }
            }
        }
        return ret;
    }
}
__________________________________________________________________________________________________
