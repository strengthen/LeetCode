__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean isIsomorphic2(String s, String t) {
        
        if (s == null || t == null) return false;
        
        HashMap<Character, Character> map = new HashMap<Character, Character>();
        for (int i = 0; i < s.length(); i++){
            char sc = s.charAt(i);
            char tc = t.charAt(i);
            
            if (map.containsKey(sc)){
                if (!map.get(sc).equals(tc)){
                    return false;
                }
            } else {
                if(!map.containsValue(tc)) 
                    map.put(sc,tc);
                else 
                    return false; 
            }                
             map.put(sc, tc);
        }
        
        return true;
    }
    
     public boolean isIsomorphic(String sString, String tString) {

        char[] s = sString.toCharArray();
        char[] t = tString.toCharArray();

        int length = s.length;
        if(length != t.length) return false;

        char[] sm = new char[256];
        char[] tm = new char[256];

        for(int i=0; i<length; i++){
            char sc = s[i];
            char tc = t[i];
            if(sm[sc] == 0 && tm[tc] == 0){
                sm[sc] = tc;
                tm[tc] = sc;
            }else{
                if(sm[sc] != tc || tm[tc] != sc){
                    return false;
                }
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 34228 kb submission
class Solution {
    public boolean isIsomorphic(String s, String t) {
        int[] s1 = new int[256],t1 = new int[256];
        int n = s.length();
        
        for(int i = 0 ; i < s1.length ; i ++){
            s1[i]=t1[i] = -1;
        }
        
        for(int i=0; i < n ;i++){
            if(s1[s.charAt(i)] != t1[t.charAt(i)])return false;
            s1[s.charAt(i)] = t1[t.charAt(i)] = i;
        }
        return true;
    }
}
__________________________________________________________________________________________________
