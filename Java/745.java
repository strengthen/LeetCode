__________________________________________________________________________________________________
sample 167 ms submission
class WordFilter {
    class Trie {
        Trie[] children;
        List<String> words;

        public Trie() {
            children = new Trie[26];
            words = new ArrayList<>();
        }

        public void insert(String word) {
            Trie cur = this;
            for (int i = 0; i < word.length(); i++) {
                cur.words.add(word);
                char ch = word.charAt(i);
                if (cur.children[ch - 'a'] == null) {
                    cur.children[ch - 'a'] = new Trie();
                }
                cur = cur.children[ch - 'a'];
            }
            cur.words.add(word);
        }
    }

    Trie root;
    Map<String, Integer> map;
    public WordFilter(String[] words) {
        root = new Trie();
        map = new HashMap<>();
        for (int i = words.length - 1; i >= 0; i--) {
            if (!map.containsKey(words[i])) map.put(words[i], i);
            root.insert(words[i]);
        }
    }

    public int f(String prefix, String suffix) {
        List<String> words = find(prefix);
        if (words == null) return -1;
        for (String word : words) {
            if (word.endsWith(suffix)) return map.get(word);
        }
        return -1;
    }

    private List<String> find(String prefix) {
        if (prefix == null || prefix.length() == 0) return root.words;
        Trie cur = root;
        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix.charAt(i);
            if (cur.children[ch - 'a'] == null) return null;
            cur = cur.children[ch - 'a'];
        }
        return cur.words;
    }
}
__________________________________________________________________________________________________
sample 69264 kb submission
class WordFilter {
    private PrefixTrie pRoot;
    private SuffixTrie sRoot;

    public WordFilter(String[] words) {
        pRoot = new PrefixTrie();
        sRoot = new SuffixTrie();
        
        for (int weight = 0; weight < words.length; weight++) {
            pRoot = pRoot.insert(pRoot, words[weight], 0, weight);
            sRoot = sRoot.insert(sRoot, words[weight], words[weight].length() - 1, weight);
        }
    }
    
    public int f(String prefix, String suffix) {
        Set<Integer> prefixSet = pRoot.find(pRoot, prefix, 0);
        if (prefixSet == null) {
            return -1;
        }
        Set<Integer> suffixSet = sRoot.find(sRoot, suffix, suffix.length() - 1);
        if (suffixSet == null) {
            return -1;
        }
        Iterator<Integer> iterator = prefixSet.iterator();
        while(iterator.hasNext()) {
            int weight = iterator.next();
            if (suffixSet.contains(weight)) {
                return weight;
            }
        }
        return -1;
    }
    
    private class PrefixTrie {
        PrefixTrie[] children;
        Set<Integer> weightSet;
        
        PrefixTrie() {
            children = new PrefixTrie[26];
            weightSet = new TreeSet<>(Collections.reverseOrder());
        }
        
        PrefixTrie insert(PrefixTrie trie, String s, int index, int weight) {
            trie.weightSet.add(weight);
            if (index == s.length()) {
                return trie;
            }
            if (trie.children[s.charAt(index) - 'a']  == null) {
                trie.children[s.charAt(index) - 'a'] = new PrefixTrie();
            }
            PrefixTrie child = trie.children[s.charAt(index) - 'a'];
            insert(child, s, index + 1, weight);
            return trie;
        }
        
        Set<Integer> find(PrefixTrie trie, String prefix, int index) {
            if (trie == null) {
                return null;
            }
            if (index == prefix.length()) {
                return trie.weightSet;
            }
            return find(trie.children[prefix.charAt(index) - 'a'], prefix, index + 1);
        }
    }
    
    private class SuffixTrie {
        SuffixTrie[] children;
        Set<Integer> weightSet;
        
        SuffixTrie() {
            children = new SuffixTrie[26];
            weightSet = new HashSet<>();
        }
        
        SuffixTrie insert(SuffixTrie trie, String s, int index, int weight) {
            trie.weightSet.add(weight);
            if (index == -1) {
                return trie;
            }
            if (trie.children[s.charAt(index) - 'a']  == null) {
                trie.children[s.charAt(index) - 'a'] = new SuffixTrie();
            }
            SuffixTrie child = trie.children[s.charAt(index) - 'a'];
            insert(child, s, index - 1, weight);
            return trie;
        }
        
        Set<Integer> find(SuffixTrie trie, String suffix, int index) {
            if (trie == null) {
                return null;
            }
            if (index == -1) {
                return trie.weightSet;
            }
            return find(trie.children[suffix.charAt(index) - 'a'], suffix, index - 1);
        }
    }
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
__________________________________________________________________________________________________
