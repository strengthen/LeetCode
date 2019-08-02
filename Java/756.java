__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean search(char[] c,boolean[][][] f,int x,int n){
        if(n==1)
            return true;
        if(x==n-1)
            return search(c,f,0,n-1);
        for(int i=0;i<7;i++){
            char cc=c[x];
            if(f[c[x]-'A'][c[x+1]-'A'][i]){
                c[x]=(char)('A'+i);
                if(search(c,f,x+1,n))
                    return true;
                c[x]=cc;
            }
        }
        return false;
    }
    public boolean pyramidTransition(String bottom, List<String> allowed) {
        char[] c=bottom.toCharArray();
        boolean[][][] f=new boolean[7][7][7];
        for(String s:allowed)
            f[s.charAt(0)-'A'][s.charAt(1)-'A'][s.charAt(2)-'A']=true;
        return search(c,f,0,c.length);
    }
}
__________________________________________________________________________________________________
sample 34968 kb submission
class Solution {
    public boolean pyramidTransition(String bottom, List<String> allowed) {
        Map<String, List<String>> allowedMap = new HashMap<>();
        for (String s : allowed) {
            String base = s.substring(0, 2);
            String top = s.substring(2);
            allowedMap.computeIfAbsent(base, k -> new ArrayList<>()).add(top);
        }
        return dfs(Arrays.asList(bottom), allowedMap, new HashSet<>());
    }

    private boolean dfs(List<String> bottoms, Map<String, List<String>> allowedMap, Set<String> memo) {
        if (bottoms.isEmpty()) {
            return false;
        }
        if (bottoms.get(0).length() == 1) {
            return true;
        }
        for (String bottom : bottoms) {
            if (memo.contains(bottom)) {
                continue;
            }
            List<List<String>> allowedList = new ArrayList<>();
            boolean possible = true;
            for (int i = 0; i < bottom.length() - 1; i++) {
                String pair = bottom.substring(i, i + 2);
                if (allowedMap.containsKey(pair)) {
                    allowedList.add(allowedMap.get(pair));
                } else {
                    possible = false;
                    break;
                }
            }
            if (possible && !allowedList.isEmpty()) {
                if (dfs(permute(allowedList, 0, allowedMap), allowedMap, memo)) {
                    return true;
                }
            }
            memo.add(bottom);
        }
        return false;
    }

    private List<String> permute(List<List<String>> allowedList, int x, Map<String, List<String>> allowedMap) {
        if (x == allowedList.size() - 1) {
            return allowedList.get(x);
        }
        List<String> allowed = allowedList.get(x);
        List<String> permutations = new ArrayList<>();
        List<String> nested = permute(allowedList, x + 1, allowedMap);
        for (int i = 0; i < allowed.size(); i++) {
            for (int j = 0; j < nested.size(); j++) {
                String s = allowed.get(i) + nested.get(j);
                if (allowedMap.containsKey(s.substring(0, 2))) {
                    permutations.add(s);
                }
            }
        }
        return permutations;
    }
}
__________________________________________________________________________________________________
