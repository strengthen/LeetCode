__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        char[] c = s.toCharArray();
        int cursor = c.length-1;
        int length = 0;
        while (cursor > -1) {
            if (c[cursor] == ' ') return length;
            length++;
            cursor--;
        }
        return length;
    }
}
__________________________________________________________________________________________________
sample 34224 kb submission
class Solution {
    public int lengthOfLastWord(String s) {
        int lw_index;
        if (s.indexOf(' ') != -1) {
            //When there are multiple words
            
            lw_index = s.lastIndexOf(' ') + 1; 
        } else if (s.length() > 0) {
            //When there is just one word
            
            lw_index = 0;
        } else {
            //When it is blank
            
            return 0;
        }        
        
        String last_word = s.substring(lw_index);
        
        if (last_word.length() < 1 && s.length() < 1) {
            //When the string is blank
            return 0;  
        } else if (last_word.length() < 1 && s.length() > 1) {
            //When there are words, but with pure spaces at the end
            System.out.println(lw_index);
            lw_index = s.lastIndexOf(' ', lw_index - 1);
            System.out.println(lw_index);
            while (s.lastIndexOf(' ', lw_index - 1) == lw_index - 1) {
                lw_index = s.lastIndexOf(' ', lw_index - 1);
                System.out.println(lw_index);
            }
            
            int lw_end = lw_index;
            lw_index = s.lastIndexOf(' ', lw_index - 1) + 1;
            System.out.println(lw_index);
            
            
            if (lw_index == -1) lw_index = 0;
            if (lw_end == -1) return 0;
            last_word = s.substring(lw_index, lw_end);
            
            System.out.println(last_word);
        }
        
        System.out.println(last_word);
        
        return last_word.length();
    }
}
__________________________________________________________________________________________________
