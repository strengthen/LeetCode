__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] translate = new String[]{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        HashSet<String> set = new HashSet<>();
        for (String word: words) {
            StringBuilder code = new StringBuilder();
            for (char c: word.toCharArray()) {
                String morse = translate[c - 'a'];
                code.append(morse);
            }
            set.add(code.toString());
        }
        return set.size();
        
    }
}
__________________________________________________________________________________________________
sample 35368 kb submission
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        if(words.length == 1){
            return 1;
        }
        if(words.length == 0){
            return 0;
        }
        String[] morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        String[] morses = new String[words.length];
        for(int i = 0; i < words.length; i++){
            String word = "";
            for(int j = 0; j < words[i].length(); j++){
                int letter = ((int)words[i].charAt(j)) - 97;
                word += morse[letter];
            }
            morses[i] = word;
        }
        int result = 0;
        for(int i = 0; i < morses.length; i++){
            if(morses[i] != null){
                result++;
            }
            if(morses[i] != null && i != morses.length - 1){
                for(int j = i + 1; j < morses.length; j++){
                    if(morses[i].equals(morses[j])){
                        morses[j] = null;
                    }
                }
            }
        }
        for(int i = 0; i < 5000; i++){
            System.out.println("useless");
        }
        return result;
    }
}
__________________________________________________________________________________________________
