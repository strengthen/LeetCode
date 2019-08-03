__________________________________________________________________________________________________
sample 14 ms submission
class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        Map<String, String> map0 = new HashMap<>();
        for (String word : wordlist) {
            map0.putIfAbsent(word, word);
        }
        Map<String, String> map1 = new HashMap<>();
        for (String word : wordlist) {
            map1.putIfAbsent(word.toLowerCase(), word);
        }
        
        Map<String, String> map2 = new HashMap<>();
        for (String word : wordlist) {
            map2.putIfAbsent(convertKey(word.toLowerCase()), word);
        }
        
        String[] res = new String[queries.length];
        for (int i = 0; i < res.length; i++) {
            res[i] = search(queries[i], map0, map1, map2);
        }
        
        return res;
    }
    
    private String convertKey(String word) {
        char[] chars = word.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (isVowel(chars[i])) {
                chars[i] = 'a';
            }
        }
        
        return String.valueOf(chars);
    }
    
    private boolean isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }
    
    private String search(String word, Map<String, String> map0, Map<String, String> map1, Map<String, String> map2) {
        if (map0.containsKey(word)) {
            return map0.get(word);
        }
        
        String lowerWord = word.toLowerCase();
        
        if (map1.containsKey(lowerWord)) {
            return map1.get(lowerWord);
        }
        
        if (map2.containsKey(convertKey(lowerWord))) {
            return map2.get(convertKey(lowerWord));
        }
        
        return "";
    }
}
__________________________________________________________________________________________________
sample 42004 kb submission
class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {

        Set<String> set = new HashSet<>();

        Map<String, List<String>> cap = new HashMap<>();
        Map<String, List<String>> err = new HashMap<>();


        Set<Character> c = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u'));
        for (String w : wordlist) {

            set.add(w);

            String str = w.toLowerCase();

            cap.computeIfAbsent(str, key -> new ArrayList<>()).add(w);
            StringBuilder sb = new StringBuilder(str);
            for (int i = 0; i < str.length(); i++) {
                if (c.contains(str.charAt(i)))
                    sb.setCharAt(i, '*');
            }

            err.computeIfAbsent(sb.toString(), key -> new ArrayList<>()).add(w);
        }

        String[] res = new String[queries.length];

        for (int i = 0; i < queries.length; i++) {
            String q = queries[i];

            if (set.contains(q)) {
                res[i] = q;
                continue;
            } 

            q = q.toLowerCase();

            if (cap.containsKey(q)) {
                res[i] = cap.get(q).get(0);
                continue;
            }

            StringBuilder sb = new StringBuilder(q);

            for (int j = 0; j < q.length(); j++) {
                if (c.contains(q.charAt(j)))
                    sb.setCharAt(j, '*');
            }

            if (err.containsKey(sb.toString())) {
                res[i] = err.get(sb.toString()).get(0);
                continue;
            }

            res[i] = "";
        }


        return res;
    }
}
__________________________________________________________________________________________________
