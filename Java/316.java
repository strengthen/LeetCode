__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String removeDuplicateLetters(String s) {
        if (s == null)
            return null;
        StringBuilder result = new StringBuilder();
        int[] count = new int[26];
        boolean[] actual = new boolean[26];
        char[] s_arr = s.toCharArray();
        for (int index = 0 ; index < actual.length ; index++)
            actual[index] = false;
        for (char c : s_arr)
            count[c - 'a']++;
        for( char c : s_arr) {
            int length = result.length();
            while (length > 0 && c < result.charAt(length-1) && count[result.charAt(length - 1) - 'a'] > 1 && !actual[c - 'a']) {
                count[result.charAt(length - 1) - 'a']--;
                actual[result.charAt(length - 1) - 'a'] = false;
                result.deleteCharAt(length - 1);
                length = result.length();
            }
            if (!actual[c - 'a']) {
                result.append(c);
                actual[c - 'a'] = true;
            }else
                count[c - 'a']--;
        }
        return result.toString();
    }
}
__________________________________________________________________________________________________
sample 34348 kb submission
class Solution {
  public String removeDuplicateLetters(String s) {
    char[] arr = s.toCharArray();
    int[] freq = new int[26];
    for (char ch : arr) ++freq[ch-'a'];
    
    char[] buf = new char[s.length()];
    int topIndex = -1;
    boolean[] visited = new boolean[26];
    for (char ch : arr) {
      --freq[ch-'a'];
      if (visited[ch-'a']) continue; // Skip if ch is already in the result string.
      visited[ch-'a'] = true;
      
      while (topIndex != -1 && buf[topIndex] > ch && freq[buf[topIndex]-'a'] > 0) {
        char pop = buf[topIndex--];
        visited[pop-'a'] = false;
      }
      buf[++topIndex] = ch;
    }
    
    return new String(buf, 0, topIndex + 1);
  }
}
__________________________________________________________________________________________________
