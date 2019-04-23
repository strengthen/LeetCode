__________________________________________________________________________________________________
0ms
class Solution { 
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        if (n < 1) return result;
        
        char[] str = new char[n * 2];
        generateParenthesis(str, result, 0, n, 0, 0);
        
        return result;

    }
    
    private void generateParenthesis(char[] str, List<String> result, int pos, int n, int open, int close) {
        if (close == n) {
            result.add(String.valueOf(str));
            return;
        }
        
        if (open < n) {
            str[pos] = '(';
            generateParenthesis(str, result, pos + 1, n, open + 1, close);
        }
        
        if (close < open) {
            str[pos] = ')';
            generateParenthesis(str, result, pos + 1, n, open, close + 1);
        }
        
    }
}
__________________________________________________________________________________________________
1ms
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        recursiveGen(res,"",n,n);
        return res;
    }
    
    private void recursiveGen(List<String> res, String subString, int left, int right) {
        if (left == 0 & right == 0) {
            res.add(subString);
            return;
        }
        if (left > 0) {
            recursiveGen(res, subString + "(", left - 1, right);
        }
        if (right > left) {
            recursiveGen(res, subString + ")", left, right - 1);
        }
    }
    
}
__________________________________________________________________________________________________
2ms
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList();
        if (n == 0) 
        {
            ans.add("");
        } 
        else {
            for (int c = 0; c < n; ++c)
                for (String left: generateParenthesis(c))
                    for (String right: generateParenthesis(n-1-c))
                        ans.add("(" + left + ")" + right);
        }
        return ans;
    }
}
__________________________________________________________________________________________________
37036 kb
class Solution {
    public List<String> generateParenthesis(int n) {
        return generateParenthesis("", n, n);
    }
    
    public List<String> generateParenthesis(String s, int toOpen, int toClose) {
        if (toOpen == 0) {
            StringBuilder sb = new StringBuilder(s);
            for (int i = 0; i < toClose; i++) {
                sb.append(')');
            }
            return Collections.singletonList(sb.toString());
        }
        
        List<String> list = new ArrayList<>();
        list.addAll(generateParenthesis(s + "(", toOpen - 1, toClose));
        
        if (toClose > toOpen) {
            list.addAll(generateParenthesis(s + ")", toOpen, toClose - 1));
        }
        
        return list;
    }
}
__________________________________________________________________________________________________
37084 kb
class Solution {
    LinkedList<String> res = new LinkedList<>();
    public List<String> generateParenthesis(int n) {
        if (n == 0) {
            return res;
        }
        LinkedList<String> cur = new LinkedList<>();
        cur.add("");
        DFS(n, 0, 0, cur);
        return res;
    }
    public void DFS(int n, int numLeft, int numRight, LinkedList<String> cur) {
        if (numLeft == n && numRight == n) { // finish
            res.addAll(cur);
            return;
        }
        LinkedList<String> newCur = new LinkedList<>();
        if (numLeft < n) { // can add left parantheses
            for (String curString : cur) {
                newCur.offer(curString + '(');
            }
            DFS(n, numLeft + 1, numRight, newCur);
        }
        newCur.clear();
        if (numLeft > numRight) { // can add right parantheses
            for (String curString : cur) {
                newCur.offer(curString + ')');
            }
            DFS(n, numLeft, numRight + 1, newCur);
        }
    }
}
__________________________________________________________________________________________________
