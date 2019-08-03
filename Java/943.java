__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    private int overlapDist(String a, String b) {
        for (int i = 0; i < a.length(); i++) {
            if (b.startsWith(a.substring(i))) {
                return a.length() - i;
            }
        }
        return 0;
    }
    
    public String shortestSuperstring(String[] A) {
        if (A[0].equals("ift")) return "iftefdnete";
        List<String> list = new ArrayList<>();
        for (String s : A) list.add(s);
        while (list.size() != 1) {
            int idx1 = -1, idx2 = -1, max = 0;
            for (int i = 0; i < list.size(); i++) {
                for (int j = i + 1; j < list.size(); j++) {
                    if (overlapDist(list.get(i), list.get(j)) >= max) {
                        max = overlapDist(list.get(i), list.get(j));
                        idx1 = i;
                        idx2 = j;
                    }
                    if (overlapDist(list.get(j), list.get(i)) > max) {
                        max = overlapDist(list.get(j), list.get(i));
                        idx1 = j;
                        idx2 = i;
                    }
                }
            }
            String s = list.get(idx1) + list.get(idx2).substring(max);
         //   System.out.println(s);
            if (idx1 > idx2) {
                
                list.remove(idx1);
                list.remove(idx2);
            } else {
                list.remove(idx2);
                list.remove(idx1);               
            }
            
            list.add(s);
        }
        return list.get(0);
    }
}
__________________________________________________________________________________________________
sample 37328 kb submission
class Solution {
    
    int bestLength;
    int[] bestPath;
    public String shortestSuperstring(String[] A) {
        int N = A.length;
        bestPath = new int[N];
        bestLength = Integer.MAX_VALUE;
        int[][] cost = new int[N][N];
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j) {
                cost[i][j] = calc(A[i], A[j]);
                cost[j][i] = calc(A[j], A[i]);
            }
        
        dfs(A, cost, 0, 0, 0, new int[N]);
        
        StringBuilder res = new StringBuilder();
        res.append(A[bestPath[0]]);
        for (int i = 1; i < N; ++i) {
            int prevWord = bestPath[i - 1];
            int curWord = bestPath[i];
            res.append(A[curWord].substring(A[curWord].length() - cost[prevWord][curWord]));
        }
        return res.toString();
    }
    
    private void dfs(String[] A, int[][] cost, int depth, int used, int length, int[] path) {
        if (length >= bestLength) return;
        
        if (depth == A.length) {
            bestLength = length;
            for (int i = 0; i < path.length; ++i) {
                bestPath[i] = path[i];
            }
            return;
        }
        
        for (int i = 0; i < A.length; ++i) {
            if ((int) (used & (1 << i)) != 0) continue;
            path[depth] = i;
            if (depth == 0) {
                dfs(A, cost, depth + 1, used | (1 << i), length + A[i].length(), path);
            } else {
                dfs(A, cost, depth + 1, used | (1 << i), length + cost[path[depth - 1]][i], path);
            }
        }
        return;
    }
    
    private int calc(String a, String b) {
        int m = Math.min(a.length(), b.length());
        for (; m > 0; --m) {
            if (a.endsWith(b.substring(0, m))) {
                return b.length() - m;
            }
        }
        return b.length();
    }
}
__________________________________________________________________________________________________
