__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
         if (s.length() < p.length()) return new ArrayList<>();
        List<Integer> answer = new ArrayList<>();
        int size = p.length();
        int[] target = new int[26];
        for(int i = 0; i < size; i++) {
            target[p.charAt(i)-'a']++;
        }
        char[] arr = s.toCharArray();
        int l = 0, r = 0;
        while (r < arr.length) {
            if (target[arr[r]-'a'] > 0) {
                target[arr[r]-'a']--;
                r++;
            }else {
                target[arr[l]-'a']++;
                l++;
            }
            
            if (r-l==size) {
                answer.add(l);
            }
        }
        return answer;
    }
}
__________________________________________________________________________________________________
sample 36816 kb submission
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        Map<Character, Integer> anagramChars = toCharMap(p);
        List<Integer> indexes = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            anagramChars.put(c, anagramChars.getOrDefault(c, 0) - 1);
            if (anagramChars.get(c) == 0) {
                anagramChars.remove(c);
            }
            if (i >= p.length()) {
                char toRemove = s.charAt(i - p.length());
                anagramChars.merge(toRemove, 1, Integer::sum);
                if (anagramChars.get(toRemove) == 0) {
                    anagramChars.remove(toRemove);
                }
            }
            if (anagramChars.size() == 0) {
                indexes.add(i - p.length() + 1);
            }
        }
        return indexes;
    }
    
    Map<Character, Integer> toCharMap(String s) {
        Map<Character, Integer> chars = new HashMap<>();
        for (char c : s.toCharArray()) {
            chars.merge(c, 1, Integer::sum);
        }
        return chars;
    }
}
__________________________________________________________________________________________________
