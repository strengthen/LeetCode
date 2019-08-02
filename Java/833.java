__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets)     {
        int len = S.length();
        int[] arr = new int[len];
        Arrays.fill(arr,-1);
        
        for(int i = 0; i < indexes.length; i++)
        {
            int srcLen = sources[i].length();
            int indx = indexes[i];
            if(S.substring(indx,indx+srcLen).equals(sources[i]))
                arr[indx] = i;
        }
        
        StringBuilder sb = new StringBuilder();
        int j = 0; 
        while(j < len)
        {
            if(arr[j] >= 0)
            {
                sb.append(targets[arr[j]]);
                j += sources[arr[j]].length();
            }
            else
            {
                sb.append(S.charAt(j));
                j++;
            }
        }
        return sb.toString();
    }
}
__________________________________________________________________________________________________
sample 34784 kb submission
class Solution {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        List<int[]> sorted = new ArrayList<>();
        for (int i = 0; i < indexes.length; i++) sorted.add(new int[]{indexes[i], i});
        Collections.sort(sorted, Comparator.comparing(i -> i[0]));
        StringBuilder sb = new StringBuilder();
        char[] cS = S.toCharArray();
        int offset = 0;
        for (int i = 0; i < sorted.size(); i++) {
            int idx = sorted.get(i)[0];
            int pos = sorted.get(i)[1];
            if (idx >= cS.length) break;
            sb.append(new String(cS, offset, idx - offset));
            if (match(cS, idx, sources[pos])) {
                sb.append(targets[pos]);
                offset = idx + sources[pos].length();
            }
            else offset = idx;
        }
        if (offset < cS.length) {
            sb.append(new String(cS, offset, cS.length - offset));
        }
        return sb.toString();
    }
    
    private boolean match(char[] cs, int offset, String src) {
        int i = 0;
        for (char c: src.toCharArray()) {
            if (offset + i >= cs.length) return false;
            if (c != cs[offset + i]) return false;
            i++;
        }
        return true;
    }
}
__________________________________________________________________________________________________
