__________________________________________________________________________________________________
sample 3 ms submission
// should write the code again
class Solution {
     public int[] movesToStamp(String stamp, String target) {
        char[] S = stamp.toCharArray();
        char[] T = target.toCharArray();
        List<Integer> res = new ArrayList<>();
        boolean[] visited = new boolean[T.length];
        int stars = 0;
        
        while (stars < T.length) {
            boolean doneReplace = false;
            for (int i = 0; i <= T.length - S.length; i++) {
                if (!visited[i] && canReplace(T, i, S)) {
                    stars = doReplace(T, i, S.length, stars);
                    doneReplace = true;
                    visited[i] = true;
                    res.add(i);
                    if (stars == T.length) {
                        break;
                    }
                }
            }
            
            if (!doneReplace) {
                return new int[0];
            }
        }
        
        int[] resArray = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            resArray[i] = res.get(res.size() - i - 1);
        }
        return resArray;
    }
    
    private boolean canReplace(char[] T, int p, char[] S) {
        for (int i = 0; i < S.length; i++) {
            if (T[i + p] != '*' && T[i + p] != S[i]) {
                return false;
            }
        }
        return true;
    }
    
    private int doReplace(char[] T, int p, int len, int count) {
        for (int i = 0; i < len; i++) {
            if (T[i + p] != '*') {
                T[i + p] = '*';
                count++;
            }
        }
        return count;
    } 
}
__________________________________________________________________________________________________
sample 36480 kb submission
class Solution {
    public int[] movesToStamp(String stamp, String target) {
        List<Integer> indexes = new ArrayList<>();

        boolean changed = true;
        while (changed && !isQuestionsOnly(target)) {
            changed = false;
            for (int i = 0; i <= target.length() - stamp.length() && !changed; i++) {
                if (matched(stamp, target, i) && !isQuestionsOnly(target.substring(i, i + stamp.length()))) {
                    changed = true;
                    indexes.add(0, i);
                    target = replace(target, i, stamp.length());
                }
            }
            if (!changed) {
                return new int[]{};
            }
        }
        return indexes.stream().mapToInt(i -> i).toArray();
    }

    private String replace(String target, int index, int length) {
        char[] chars = target.toCharArray();
        for (int i = index; i < index + length; i++) {
            chars[i] = '?';
        }
        return new String(chars);
    }

    private boolean matched(String stamp, String target, int index) {
        for (int i = 0; i < stamp.length(); i++) {
            if (stamp.charAt(i) != target.charAt(index + i) && target.charAt(index + i) != '?') {
                return false;
            }
        }
        return true;
    }

    boolean isQuestionsOnly(String str) {
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) != '?') {
                return false;
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
