__________________________________________________________________________________________________
sample 22 ms submission
class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        Node root = new Node();
        for (int i = 0; i < words.length; ++i) {
            insert(root, i, words[i].toCharArray());
        }

        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < words.length; ++i) {
            search(root, i, words[i].toCharArray(), result);
        }

        return result;
    }
    
    static class Node {
        Node[] next = new Node[26];
        List<Integer> palindromTail = new ArrayList<>();
        int leaf = -1;
    }

    private void addToResult(List<List<Integer>> result, int i, int j) {
        List<Integer> pair = new ArrayList<>();
        pair.add(i);
        pair.add(j);
        result.add(pair);
    }
    
    private void search(Node root, int num, char[] chars, List<List<Integer>> result) {
        for (int i = 0; i < chars.length; ++i) {
            if (root.leaf != -1 && isPalindrome(chars, i, chars.length - 1) && root.leaf != num) {
                addToResult(result, num, root.leaf);
            }

            if (root.next[chars[i] - 'a'] == null) {
                return;
            }

            root = root.next[chars[i] - 'a'];
        }

        if (root.leaf != -1 && root.leaf != num) {
            addToResult(result, num, root.leaf);
        }

        for (int i : root.palindromTail) {
            if (i != num) {
                addToResult(result, num, i);
            }
        }
    }

    private void insert(Node root, int num, char[] chars) {
        for (int i = chars.length - 1; i>=0; --i) {
            if (isPalindrome(chars, 0, i)) {
                root.palindromTail.add(num);
            }

            Node child = root.next[chars[i] - 'a'];

            if (child == null) {
                child = new Node();
                root.next[chars[i] - 'a'] = child;
            }

            root = child;
        }

        //root.palindromTail.add(num);
        root.leaf = num;
    }

    private boolean isPalindrome(char[] chars, int i, int j) {
        while (i < j) {
            if (chars[i] != chars[j]) {
                return false;
            }

            ++i;
            --j;
        }

        return true;
    }
}
__________________________________________________________________________________________________
sample 39780 kb submission
class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        
        for (int i = 0; i < words.length - 1; i++) {
            for (int j = i + 1; j < words.length; j++) {
                
                if (canFormPalindrome(words, i, j)) {
                    List<Integer> pair = new ArrayList<Integer>();
                    pair.add(i);
                    pair.add(j);
                    
                    res.add(pair);
                    
                }
                
                if (canFormPalindrome(words, j, i)) {
                    List<Integer> pair = new ArrayList<Integer>();
                    pair.add(j);
                    pair.add(i);
                    res.add(pair);
                }
                
                
            }          
        }
        
        return res;
    }
    
    private boolean canFormPalindrome(String[] words, int i, int j) {
        int shorterLength = (words[i].length() <= words[j].length()) ? words[i].length() : words[j].length();
        
        for (int k = 0; k < shorterLength; k++) {
            if (words[i].charAt(k) != words[j].charAt(words[j].length() - 1 - k)) {
                return false;
            }
        }
        
        if (words[i].length() <= words[j].length()) {
            return isPalindrome(words[j].substring(0, words[j].length() - shorterLength));
        } else {
            return isPalindrome(words[i].substring(shorterLength));
        }
        
    }
    
    private boolean isPalindrome(String word) {
        int i = 0;
        int j = word.length() - 1;
        
        while (i < j) {
            if (word.charAt(i) != word.charAt(j)) {
                return false;
            }
            
            i += 1;
            j -= 1;
        }
        
        return true;
        
    }
}
__________________________________________________________________________________________________
