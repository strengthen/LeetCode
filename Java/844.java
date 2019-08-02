__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean backspaceCompare(String S, String T) {
        int iS = S.length()-1, iT = T.length()-1;
        char[] s = S.toCharArray(), t = T.toCharArray();
        
        while ( iS >= 0 || iT >= 0 ) {
            iS = next(s, iS);
            iT = next(t, iT);
            if (iS < 0 || iT < 0) break;
            
            if ( s[iS] != t[iT] ) return false;
            iS--;
            iT--;
        }
        
        if (iS >= 0 || iT >= 0) return false;
        return true;
    }
    
    int next(char[] s, int cur) {
        int nBS = 0;
        while (cur >= 0) {
            if (s[cur] == '#') nBS++;
            else if (nBS > 0) nBS--;
            else return cur;
            cur--;
        }
        return -1;
    }
}

/*
is == 0, it < 0
*/
__________________________________________________________________________________________________
sample 35500 kb submission
class Solution {
    public boolean backspaceCompare(String S, String T) {
    int i = S.length() - 1;
        int j = T.length() - 1;
        int cnts = 0;
        int cntt = 0;
        while(i >= 0 || j >= 0) {
            while(i >= 0) {
                //发现#记下来几个，然后ship cnt个char
                if(S.charAt(i) == '#') {
                    cnts++;
                    i--;
                } else if (cnts > 0) {
                    cnts--;
                    i--;
                } else break;
            }
            while(j >= 0) {
                if(T.charAt(j) == '#') {
                    cntt++;
                    j--;
                } else if(cntt > 0) {
                    j--;
                    cntt--;
                } else break;
            }
            if(i >= 0 && j >= 0 && S.charAt(i) != T.charAt(j)) return false;
            if(i < 0 && j < 0) return true;
            if (i < 0 || j < 0) return false;
            j--; i--;
        }
        return true;
    }
}
__________________________________________________________________________________________________
