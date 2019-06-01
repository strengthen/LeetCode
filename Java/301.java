__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> res = new ArrayList<>();
        remove(s, 0, 0, res, new char[]{'(', ')'});
        return res;
    }
    public void remove(String s, int ind, int pre_rm, List<String> res, char[] par) {
        int cnt = 0;
        for(int i=ind; i<s.length(); i++) {
            if(s.charAt(i)==par[0]) cnt++;
            if(s.charAt(i)==par[1]) cnt--;
            if(cnt<0) {
                for(int j=pre_rm; j<=i; j++) {
                    if(s.charAt(j)==par[1] && (j==pre_rm||s.charAt(j-1)!=par[1])) {
                        String ns = s.substring(0, j)+s.substring(j+1);
                        remove(ns, i, j, res, par);
                    }
                }
                return;
            }
        }
        String reverse = new StringBuffer(s).reverse().toString();
        if(par[0]=='(') remove(reverse, 0, 0, res, new char[]{')','('});
        else res.add(reverse);
    }
}
__________________________________________________________________________________________________
sample 34592 kb submission
class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> ret = new ArrayList<>();
        if (s == null) return ret;
        _find(ret, new StringBuilder(s), '(', ')', 0, 0);
        return ret;
    }

    private void _find(List<String> ret, StringBuilder sb, char lb, char rb, int start, int deleteFrom) {
        int count = 0;
        for (int i = start; i < sb.length(); i++) {
            if (sb.charAt(i) == lb) count++;
            if (sb.charAt(i) == rb) {
                count--;
                if (count < 0) {
                    for (int j = deleteFrom; j <= i; j++) {
                        if (sb.charAt(j) == rb) {
                            if (j == deleteFrom || sb.charAt(j-1) != rb) {

                                sb.deleteCharAt(j);
                                //System.out.println(start + " :" +  j + "in loop 1" + sb);
                                _find(ret, sb, lb, rb, start, j);
                               // System.out.println(start + " :" +  j + "in loop 2" + sb);
                                sb.insert(j, rb);

                            }
                        }
                    }
                    return;
                }
            }
        }

        if (count == 0) {
            if (lb == '(') {
                ret.add(sb.toString());
            } else {
                ret.add(sb.reverse().toString());
                sb.reverse();
            }
        } else if (lb == '(') {
            _find(ret, sb.reverse(), ')', '(', 0, 0);
            sb.reverse();
        }
    }
}
__________________________________________________________________________________________________
