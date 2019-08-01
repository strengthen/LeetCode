__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int[] countS = new int[26];
        for(int i=0;i<s1.length();i++)  countS[s1.charAt(i)-'a']++;
        return help(s1, s2, 0, countS);
    }
    public boolean help(String s1, String s2, int index, int[] countS){
        int[] count = new int[26];
        int cou = 0;
        int slow = index;
        for(int i=index;i<s2.length();i++){
            if(countS[s2.charAt(i)-'a']==0) return help(s1, s2, i+1, countS);
            count[s2.charAt(i)-'a']++;
            if(count[s2.charAt(i)-'a']<=countS[s2.charAt(i)-'a'])   cou++;
            else{
                while(count[s2.charAt(i)-'a']>countS[s2.charAt(i)-'a']){
                    char cur = s2.charAt(slow++);
                    count[cur-'a']--;
                    if(count[cur-'a']<countS[cur-'a'])  cou--;
                }
            }
            if(cou==s1.length())    return true;
        }
        return false;
    }
}
__________________________________________________________________________________________________
sample 35992 kb submission
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        Map<Character, Integer> charFreq = getCharacterCount(s1);
        int i = 0, j = s1.length();
        while (i < (s2.length() - s1.length() + 1)) {
            Map<Character, Integer> candidateFreq = getCharacterCount(s2.substring(i, i + s1.length()));
            if (charFreq.equals(candidateFreq)) {
                return true;
            }
            i++;
        }
        return false;
    }

    private Map<Character, Integer> getCharacterCount(String s) {
        Map<Character, Integer> charFreq = new HashMap<>();
        for (char c : s.toCharArray()) {
            charFreq.merge(c, 1, Integer::sum);
        }
        return charFreq;
    }
}
__________________________________________________________________________________________________
