__________________________________________________________________________________________________
sample 7 ms submission
class Solution {
    public int longestStrChain(String[] words) {
        List<List<String>> list = new ArrayList<>();
        while(list.size()<16){
            list.add(new ArrayList<>());
        }
        for(int i = 0; i < words.length; i++){
            list.get(words[i].length()-1).add(words[i]);
        }
        int res = 0;
        for(int i = 0; i < 16; i++){
            if(res>15-i)break;
            List<String> curr = list.get(i);
            for(String s:curr){
                res = Math.max(res,test(s,i,list));
            }           
        }
        return res;
    }
    
    public static int test(String s, int index, List<List<String>> list){
        if(index == 15)return 1;
        List<String> next = list.get(index+1);
        int res = 1;
        for(int i = 0; i < next.size(); i++){
            if(match(s,next.get(i))){
                res = Math.max(res,1+test(next.get(i),index+1,list));
            }
        }
        return res;
    }
    
    public static boolean match(String s, String y){
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i)!=y.charAt(i)){
                return s.substring(i).equals(y.substring(i+1));
            }
        }
        return true;
    }    
}
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
    public int longestStrChain(String[] words) {
        Arrays.sort(words, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                return s1.length() - s2.length();
            }
        });
        int n = words.length;
        int m = words[n-1].length();
        int[] start = new int[m];
        for (int i = 0; i < m; i++) {
            start[i] = -1;
        }
        for (int i = 0; i < words.length; i++) {
            int len = words[i].length();
            if (start[len-1] == -1) {
                start[len-1] = i;
            }
        }
        //for (int i = 0; i < m; i++) System.out.println(start[i]);
        int[] dp = new int[n];
        int sol = 1;
        for (int i = 0; i < n; i++) {
            sol = Math.max(sol, dfs(words, start, dp, i));
            //System.out.println(dp[i]);
        }
        return sol;
    }
    
    public int dfs(String[] words, int[] start, int[] dp, int cur) {
        if (dp[cur] != 0) return dp[cur];
        int len = words[cur].length();
        if (len == start.length || start[len] == -1) {
            dp[cur] = 1;
            return 1;
        }
        int max = 0;
        for (int i = start[len]; i < (len == start.length - 1 ? words.length : start[len+1]); i++) {
            if (isChain(words[cur], words[i])) {
                max = Math.max(max, dfs(words, start, dp, i));
            }
        }
        dp[cur] = max + 1;
        return dp[cur];
    }
    
    public boolean isChain(String s1, String s2) {
        int dif = 0;
        for (int i = 0, j = 0; i < s1.length(); i++, j++) {
            if (s1.charAt(i) != s2.charAt(j)) {
                if (dif++ > 0) return false;
                i--;
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 9 ms submission
class Solution {
    class Pojo{
        String word;
        int len;
        
        Pojo(String word, int len) {
            this.word = word;
            this.len = len;
        }
    }
    
    public int longestStrChain(String[] words) {
        int max = 1;
        List<Pojo>[] lists = new List[17];
        for(int i = 0 ; i < lists.length ;i++) lists[i] = new ArrayList<>();
        for(String word : words) {
            lists[word.length()].add(new Pojo(word,1));
        }
        for(int i = 1;i<=16;i++) {
            for(Pojo pre : lists[i-1]) {
                for(Pojo cur : lists[i]) {
                    if(isPre(pre.word,cur.word)) {
                        cur.len = Math.max(cur.len, pre.len+1);
                        max = Math.max(cur.len,max);
                    }
                }
            }
        }
        return max;
    }
    
    boolean isPre(String str1, String str2) {
            int index = 0;
            while(index < str1.length() && str1.charAt(index) == str2.charAt(index)) index++;
            while(index < str1.length() && str1.charAt(index) == str2.charAt(index+1)) index++;
            return index == str1.length();
    }
}