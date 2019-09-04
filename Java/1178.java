__________________________________________________________________________________________________
sample 45 ms submission
class Solution {
    
    private class Node {
        int wnum;
        Node[] next;
        public Node() {
            this.wnum = 0;
            this.next = new Node[26];
        }
    }
    
    private char[] puzz;
    private int pidx;
    private int[] res;
    
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        Node root = new Node();
        res = new int[puzzles.length];
        for (String word : words) {
            build(root, changeWord(word), 0);
        }
        for (pidx = 0; pidx < puzzles.length; pidx++) {
            puzz = puzzles[pidx].toCharArray();
            Arrays.sort(puzz, 0, 7);
            int firstChIdx = 0;
            char first = puzzles[pidx].charAt(0);
            for (int i = 0; i < 7; i++) {
                if (puzz[i] == first) {
                    firstChIdx = i;
                    break;
                }
            }
            countValid(root, 0, firstChIdx);
        }
        List<Integer> ans = new ArrayList<>();
        for (int r : res) {
            ans.add(r);
        }
        return ans;
    }
    
    private void countValid(Node node, int idx, int firstChIdx) {
        if (node == null) {
            return;
        }
        if (idx > firstChIdx) {
            res[pidx] += node.wnum;
        }
        if (idx >= 7) {
            return;
        }
        if (idx <= firstChIdx) {
            for (int i = idx; i <= firstChIdx; i++) {
                countValid(node.next[puzz[i]-'a'], i+1, firstChIdx);
            }
        } else {
            for (int i = idx; i < 7; i++) {
                countValid(node.next[puzz[i]-'a'], i+1, firstChIdx);
            }
        }
    }
    
    private int[] changeWord(String word) {
        boolean[] table = new boolean[26];
        int uniqueCount = 0;
        for (int i = 0; i < word.length(); i++) {
            int idx = word.charAt(i)-'a';
            if (!table[idx]) {
                uniqueCount++;
                table[idx] = true;
            }
        }
        int[] nWord = new int[uniqueCount];
        int nIdx = 0;
        for (int i = 0; i < table.length; i++) {
            if (table[i]) {
                nWord[nIdx++] = i;
            }
        }
        return nWord;
    }
    
    private void build(Node node, int[] word, int idx) {
        if (node.next[word[idx]] == null) {
            node.next[word[idx]] = new Node();
        }
        if (idx == word.length-1) {
            node.next[word[idx]].wnum++;
        } else {
            build(node.next[word[idx]], word, idx+1);
        }  
    }
}
__________________________________________________________________________________________________
sample 47 ms submission
class Solution {
    private Trie t;
    private class Trie {
        private Node root;
        private class Node {
            private int count = 0;
            private Node[] next = new Node[26];
        }
        public Trie() {
            root = new Node();
        }
        public void put(char[] arr) {
            Arrays.sort(arr);
            Node nd = root;
            for (int i = 0; i < arr.length; i++) {
                if (i > 0 && arr[i] == arr[i - 1]) continue;
                int j = arr[i] - 'a';
                if (nd.next[j] == null) nd.next[j] = new Node();
                nd = nd.next[j];
            }
            nd.count++;
        }
        private int search(char[] arr) {
            char c = arr[0];
            Arrays.sort(arr);
            return dfs(arr, 0, c, root, false);
        }
        private int dfs(char[] arr, int k, char first, Node nd, boolean covered) {
            if (k == arr.length) {
                return covered ? nd.count : 0;
            }
            
            int n = 0;
            if (arr[k] != first) {
                n += dfs(arr, k + 1, first, nd, covered);
            }
            else {
                covered = true;
            }
            if (nd.next[arr[k] - 'a'] != null) {
                n += dfs(arr, k + 1, first, nd.next[arr[k] - 'a'], covered);
            }
            return n;
        }
    }
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        Trie t = new Trie();
        for (String s : words) {
            t.put(s.toCharArray());
        }
        // puzzle s = new String[]{"gaswxyz"};
        List<Integer> res = new ArrayList<>();
        for (String s : puzzles) {
            res.add(t.search(s.toCharArray()));
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 54 ms submission
class Solution {
  class TrieNode {
    TrieNode[] children;
    boolean isWord;
    int count;
    TrieNode() {
      this.children = new TrieNode[26];
      this.isWord = false;
      this.count = 0;
    }
  }
  public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
    TrieNode root = new TrieNode();
    buildTrie(root, words);
    int len = puzzles.length;
    List<Integer> res = new ArrayList<>();
    for (int i = 0; i < len; i++) {
      char[] pz = puzzles[i].toCharArray();
      char key = pz[0];
      Arrays.sort(pz);
      res.add(match(root, pz, key, 0, false));
    }
    return res;
  }

  private void buildTrie(TrieNode root, String[] wordlist) {
    for (String word : wordlist) {
      TrieNode cur = root;
      word = simplify(word);
      for (char c : word.toCharArray()) {
        if (cur.children[c - 'a'] == null) {
          cur.children[c - 'a'] = new TrieNode();
        }
        cur = cur.children[c - 'a'];
      }
      cur.isWord = true;
      cur.count += 1;
    }
  }

  private int match(TrieNode cur, char[] pz, char key, int index, boolean hasKey) {
    if (index == pz.length) {
      if (!hasKey || !cur.isWord) {
        return 0;
      }
      return cur.count;
    }
    int res = 0;
    char curChar = pz[index];
    if (curChar == key) {
      if (cur.children[curChar - 'a'] == null) {
        return 0;
      } else {
        hasKey = true;
        res += match(cur.children[curChar - 'a'], pz, key, index + 1, hasKey);
        return res;
      }
    } else {
      if (cur.children[curChar - 'a'] != null){
        res += match(cur.children[curChar - 'a'], pz, key, index + 1, hasKey);
      }
      res += match(cur, pz, key, index + 1, hasKey);
      return res;
    }
  }

  private String simplify(String word) {
    char[] sc = word.toCharArray();
    Arrays.sort(sc);
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < sc.length; i++) {
      if (i > 0 && sc[i] == sc[i - 1]) {
        continue;
      }
      sb.append(sc[i]);
    }
    return sb.toString();
  }
}
__________________________________________________________________________________________________
sample 61 ms submission
class Solution {
    class TrieNode {
        TrieNode[] children;
        boolean isWord;
        int count;
        TrieNode() {
          this.children = new TrieNode[26];
          this.isWord = false;
          this.count = 0;
        }
    }
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        TrieNode root = new TrieNode();
        buildTrie(root, words);
        int len = puzzles.length;
        List<Integer> res = new ArrayList<>();
        // search puzzle
        for (int i = 0; i < len; i++) {
          char[] pz = puzzles[i].toCharArray();
          char key = pz[0];
          Arrays.sort(pz);
          //System.out.println(Arrays.toString(pz));
          res.add(match(root, pz, key, 0, false));
        }
        return res;
    }
    
    // Build trie from given wordlist
      private void buildTrie(TrieNode root, String[] wordlist) {
        for (String word : wordlist) {
          TrieNode cur = root;
          word = simplify(word);
          //System.out.println(word);
          for (char c : word.toCharArray()) {
            if (cur.children[c - 'a'] == null) {
              cur.children[c - 'a'] = new TrieNode();
            }
            cur = cur.children[c - 'a'];
          }
          cur.isWord = true;
          cur.count += 1;
        }
    }
    
    private int match(TrieNode cur, char[] pz, char key, int index, boolean hasKey) {
        if (index == pz.length) {
          if (!hasKey || !cur.isWord) {
            return 0;
          }
          return cur.count;
        }
        int res = 0;
        char curChar = pz[index];
        if (curChar == key) {
          if (cur.children[curChar - 'a'] == null) {
            return 0;
          } else {
            hasKey = true;
            res += match(cur.children[curChar - 'a'], pz, key, index + 1, hasKey);
            return res;
          }
        } else {
          if (cur.children[curChar - 'a'] != null){
            // match this index
            res += match(cur.children[curChar - 'a'], pz, key, index + 1, hasKey);
          }
          // skip this index
          res += match(cur, pz, key, index + 1, hasKey);
          return res;
        }
    }
    
    // pre-processing to sort every char in the word of wordList and remove duplicate chars
      private String simplify(String word) {
        char[] sc = word.toCharArray();
        Arrays.sort(sc);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < sc.length; i++) {
          if (i > 0 && sc[i] == sc[i - 1]) {
            continue;
          }
          sb.append(sc[i]);
        }
        return sb.toString();
      }
}