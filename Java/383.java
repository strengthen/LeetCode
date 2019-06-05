__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        if (magazine == null || magazine.isEmpty()) return ransomNote == null || ransomNote.isEmpty();
        int len = magazine.length();
        char[] chars = magazine.toCharArray();

        for (char ch : ransomNote.toCharArray()) {
            int oldLen = len;
            for (int i = 0; i < len; i++) {
                if (ch == chars[i]) {
                    chars[i] = chars[--len];
                    break;
                }
            }
            if (oldLen == len) return false;
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 35880 kb submission
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        if (magazine.length() < ransomNote.length()) {
            return false;
        }
        Map<Character, Integer> charFreqMap = new HashMap<>();
        for (char c : ransomNote.toCharArray()) {
            charFreqMap.merge(c, 1, Integer::sum);
        }
        // System.out.println(charFreqMap);
        for (char c : magazine.toCharArray()) {
            Integer val = charFreqMap.get(c);
            if (val != null) {
                if (val == 1) {
                    charFreqMap.remove(c);
                    if (charFreqMap.isEmpty()) {
                        return true;
                    }
                } else {
                    charFreqMap.put(c, val - 1);
                }
            }
        }
        return charFreqMap.isEmpty();
    }
}
__________________________________________________________________________________________________
