__________________________________________________________________________________________________
class Solution {
    public int numKLenSubstrNoRepeats(String S, int K) {
           if (S.length() < K) return 0;
           int res = 0;
           Map<Character, Integer> map = new HashMap<>();
           int i = 0;
           int j = 0;
           for (; j < K - 1; j++) {
                   map.put(S.charAt(j), map.getOrDefault(S.charAt(j), 0) + 1);
           }
           for (; j < S.length(); j++,i++) {
                   map.put(S.charAt(j), map.getOrDefault(S.charAt(j), 0) + 1);
                   if (map.size() == K) res++;
                   map.put(S.charAt(i), map.getOrDefault(S.charAt(i), 0) - 1);
                   if (map.get(S.charAt(i)) == 0) map.remove(S.charAt(i));
           }
           return res;
       }
   }
   
__________________________________________________________________________________________________

__________________________________________________________________________________________________
