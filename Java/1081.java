__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
public String smallestSubsequence(String text) {
        int[] count = new int[128];
        boolean[] used = new boolean[128];

        int n = text.length();
        for (int i = 0; i < n; i++) {
            count[text.charAt(i)]++;
        }


        StringBuilder res = new StringBuilder();

        for (int i = 0; i < n; i++) {
            char ch = text.charAt(i);
            count[ch]--;
            if (used[ch]) continue;
            while (res.length() > 0) {
                char last = res.charAt(res.length() - 1);
                if (last < ch || count[last] == 0) break;
                res.deleteCharAt(res.length() - 1);
                used[last] = false;
            }
            res.append(ch);
            used[ch] = true;
        }
        return res.toString();
    }
}
__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public String smallestSubsequence(String text) {
        char[] cs = text.toCharArray();
        int[] last = new int[26];
        for (int i = cs.length - 1; i >= 0; i--) {
            int idx = cs[i] - 'a';
            if (last[idx] == 0) {
                last[idx] = i + 1;
            }
        }
        
        String res = "";
        boolean[] used = new boolean[26];
        int min = -1;
        for (int i = 0; i < cs.length; i++) {
            int idx = cs[i] - 'a';
            if (used[idx]) {
                continue;
            } else if (min < 0 || cs[i] < cs[min]) {
                min = i;
            }
            if (last[idx] == i + 1) {
                res += cs[min];
                used[cs[min] - 'a'] = true;
                i = min;
                min = -1;
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public String smallestSubsequence(String text) {
        if (text == null || text.length() == 0) {
            return "";
        }
        
        Stack<Character> stack = new Stack<Character>();
        int[] counts = new int[26];
        int[] visited = new int[26];
        
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            counts[c - 'a']++;
        }
        
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            
            if (visited[c - 'a'] == 1) {
                counts[c - 'a']--;
                continue;
            }
            
            while (!stack.isEmpty() && stack.peek() > c && counts[stack.peek() - 'a'] > 0) {
                char temp = stack.pop();
                visited[temp - 'a'] = 0;
            }
            
            stack.push(c);
            counts[c - 'a']--;
            visited[c - 'a'] = 1;
        }
        
        StringBuilder sb = new StringBuilder();
        
        while (!stack.isEmpty()) {
            sb.insert(0, stack.pop());
        }
        
        return sb.toString();
    }
}