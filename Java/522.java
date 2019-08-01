__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int findLUSlength(String[] strs) {
        Set<String> blacklist=new HashSet<>();
        for (int i=10;i>0;i--) {
            Set<String> set=new HashSet<>();
            for (String str:strs) {
                if (str.length()==i) {
                    if(set.contains(str)) {
                        blacklist.add(str);
                    } else {
                        set.add(str);
                    }   
                }
            }
            for (String str:set) {
                if(check(blacklist,str)) {
                    return i;
                }
            }
        }
        return -1;
    }
    boolean check(Set<String> blacklist,String str) {
        if (blacklist.contains(str)) {
            return false;
        }
        for (String s:blacklist) {
            if (s.length()==str.length()) {
                continue;
            }
            int i=0;
            int j=0;
            while(i<str.length()&&j<s.length()) {
                if(str.charAt(i)==s.charAt(j)) {
                    i++;
                }
                j++;
            }
            if(i==str.length()) {
                blacklist.add(str);
                return false;
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 33140 kb submission
class Solution {
   public int findLUSlength(String[] strs) {
        
       Arrays.sort(strs,(a, b)->(b.length() - a.length()));
        
        Set<String> duplicates = getDuplicates(strs);
        for(int i = 0; i < strs.length; i++) {
            if(!duplicates.contains(strs[i])) {
                if(i == 0) return strs[0].length();
                for(int j = 0; j < i; j++) {
                    if(isSubsequence(strs[j], strs[i])) break;
                    if(j == i-1) return strs[i].length();
                }
            }
        }
        return -1;
    }
    
    public boolean isSubsequence(String a, String b) {
        int i = 0, j = 0;
        while(i < a.length() && j < b.length()) {
            if(a.charAt(i) == b.charAt(j)) j++;
            i++;
        }
        return j == b.length();
    }
    
    private Set<String> getDuplicates(String[] strs) {
        Set<String> set = new HashSet<String>();
        Set<String> duplicates = new HashSet<String>();
        for(String s : strs) {
            if(set.contains(s)) duplicates.add(s);
            set.add(s);
        }
        return duplicates;
    }
}
__________________________________________________________________________________________________
