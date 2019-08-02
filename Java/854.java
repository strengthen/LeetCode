__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int kSimilarity(String A, String B) {
        if (A.equals(B)) {
            return 0;
        }
        char[] a = A.toCharArray();
        char[] b = B.toCharArray();
        int cnt = preProcess(a, b);
        cnt += dfs(a, b, 0);
        return cnt;
    }
    
    public int dfs(char[] a, char[] b, int start) {
        if (start == a.length) {
            return 0;
        }
        if (a[start] == b[start]) {
            return dfs(a, b, start + 1);
        }
        int min = Integer.MAX_VALUE;
        for (int i = start + 1; i < a.length; i++) {
            if (a[i] == b[start] && a[i] != b[i]) {
                swap(a, start, i);
                min = Math.min(min, 1 + dfs(a, b, start + 1));
                swap(a, start, i);
                // if (a[start] == b[i]) {
                //     return min;
                // }
            }
        }
        return min;
    }
    
    public int preProcess(char[] a, char[] b) {
        int cnt = 0;
        for (int i = 0; i < a.length; i++) {
            if (a[i] == b[i]) {
                continue;
            }
            for (int j = i + 1; j < a.length; j++) {
                if (a[i] == b[j] && a[j] == b[i]) {
                    swap(a, i, j);
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
    
    public void swap(char[] chars, int p1, int p2) {
        char temp = chars[p1];
        chars[p1] = chars[p2];
        chars[p2] = temp;
    }
}
__________________________________________________________________________________________________
sample 38136 kb submission
class Solution {
    public int kSimilarity(String A, String B) {
         if (A.equals(B)) return 0;
        Set<String> vis= new HashSet<>();
        Queue<String> q= new LinkedList<>();
        q.add(A);
        vis.add(A);
        int res=0;
        while(!q.isEmpty()){
            res++;
            for (int sz=q.size(); sz>0; sz--){
                String s= q.poll();
                int i=0;
                while (s.charAt(i)==B.charAt(i)) i++;
                for (int j=i+1; j<s.length(); j++){
                    if (s.charAt(j)==B.charAt(j) || s.charAt(j)!=B.charAt(i) ) continue;
                    String temp= swap(s, i, j);
                    if (temp.equals(B)) return res;
                    if (vis.add(temp)) q.add(temp);
                }
            }
        }
        return res;
    }
    public String swap(String s, int i, int j){
        char[] ca=s.toCharArray();
        char temp=ca[i];
        ca[i]=ca[j];
        ca[j]=temp;
        return new String(ca);
    }
    
}
__________________________________________________________________________________________________
