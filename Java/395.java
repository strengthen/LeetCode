__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int longestSubstring(String s, int k) {
        int[] count = new int[26];
        int n = s.length();
        for (int i = 0; i < n; i++) {
            count[s.charAt(i) - 'a']++;
        }
        int start = 0;
        int i = 0;
        int maxLen = 0;
        boolean isContinuous = true;
        while(i < n) {
            if (count[s.charAt(i)-'a'] < k) {
                isContinuous = false;
                // System.out.println(s + ", " + i);
                int subRes = longestSubstring(s.substring(start, i), k);
                maxLen = Math.max(subRes, maxLen);
                while (i < n && count[s.charAt(i) -'a'] < k) {
                    i++;
                }
                start = i;
            } else {
                i++;
            }
        }
        
        if (isContinuous) {
            maxLen = i - start;
        } else {
            maxLen = Math.max(maxLen, longestSubstring(s.substring(start, i), k));
        }
        
        return maxLen;
    }
}
__________________________________________________________________________________________________
sample 34480 kb submission
class Solution {
    public int longestSubstring(String s, int k) {
        if(s.length() == 0 || k == 0) return 0;
        int[] counter = new int[26];
        for(char c: s.toCharArray()) {
            counter[c-'a']++;
        }
        List<String> res = subStrings(counter, k, s);
        if(res.size() == 1) return s.length();
        return res.stream()
            .filter(st -> st.length() >= k)
            .map(st -> longestSubstring(st,k))
            .max(Comparator.naturalOrder())
            .orElse(0);
    }
    
    List<String> subStrings(int[] counter, int k, String s) {
        List<String> results = new ArrayList<>();
        int offset = 0;
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int occurence = counter[c-'a'];
            if(occurence < k && occurence > 0)  {
                results.add(s.substring(offset, i));
                offset = i+1;
            }
        }
        results.add(s.substring(offset, s.length()));
        return results;
    }
}
__________________________________________________________________________________________________
