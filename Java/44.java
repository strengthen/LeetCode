__________________________________________________________________________________________________
2ms
class Solution {
    public boolean isMatch(String s, String p) {       
        int i=0;
        int j=0;
        int xindex =-1;
        int sxindex = -1;
        
        while(i<s.length()){
            if(j<p.length() && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '?')){
                i++;
                j++;
            } else if(j<p.length() && p.charAt(j) == '*'){
                xindex = j;
                sxindex = i;
                j++;
            } else if(xindex!=-1){
                j = xindex+1;
                i = ++sxindex;
            } else {
                return false;
            }
        }
        
        while(j<p.length() && p.charAt(j) == '*'){
                      j++;
        }
                
        return j==p.length();              
    }
}
__________________________________________________________________________________________________
5ms
class Solution {
    public boolean isMatch(String s, String p) {
        byte[][] results = new byte[s.length()+1][p.length()+1];
        StringBuilder sb = new StringBuilder();
        
        //do the easy pattern recognition at the end first
        
        int numStars = 0;
        for(int i=0;i<p.length();i++) {
            if(p.charAt(i) == '*') {
                numStars++;
            }
        }
        
        return isMatchSub(s,p,0,0,results,numStars);
    }
    
    private boolean isMatchSub(String s, String p, int sStartInit, int pStart, byte[][] results, int numStars) {
        
        //check if the min length of p is larger than s
        if(p.length()-pStart-numStars > s.length()-sStartInit) {
            results[sStartInit][pStart] = 2;
            return false;
        }
        //System.out.println("s="+s.substring(sStartInit)+" p="+p.substring(pStart));
        
        int sStart = sStartInit;
        for(int i=pStart;i<p.length();i++) {
            //System.out.println("s="+s.substring(sStart)+" p="+p.substring(i));
            if(results[sStart][i] != 0) {
                return results[sStartInit][i] == 1;
            }
            if(p.charAt(i) == '*') {
                //check the characters after the * to narrow down the recursion
                StringBuilder sb = new StringBuilder(10);
                boolean reachedEnd = true;
                int numQuestions = 0;
                int numAsterisk = 0;
                for(int j=1;j<p.length()-i;j++) {
                    //System.out.println("processing p="+p.charAt(i+j)+" sStart="+(sStart+j-1));
                    if(p.charAt(i+j) != '*') {
                        if(p.charAt(i+j) != '?') {
                            sb.append(p.charAt(i+j));
                        }
                        else {
                            if(sb.length() != 0) {
                                reachedEnd = false;
                                break;
                            }
                            else {
                                numQuestions++;
                            }
                        }
                    }
                    else {
                        if(sb.length() != 0) {
                            reachedEnd = false;
                            break;
                        }
                        else {
                            numAsterisk++;
                        }
                    }
                }
                String sub = sb.toString();
                
                //never need to exit since we recursively find the answer here
                //System.out.println("sub="+sub+" numQuestions="+numQuestions+" numAsterisk="+numAsterisk);
                int index = sStart-1+numQuestions;
                
                //check for early return
                while(results[s.length()][p.length()] == 0) {
                    index = s.indexOf(sub,index+1);
                    //System.out.println("sub="+sub+" index="+index);
                    if(index != -1) {
                        if(isMatchSub(s,p,index+sub.length(),i+1+sub.length()+numQuestions+numAsterisk,results,numStars-1-numAsterisk)) {
                            results[s.length()][p.length()] = 1;
                            return true;
                        }
                    }
                    else {
                        //the required string is not in s, so return false
                        results[s.length()][p.length()] = 2;
                        return false;
                    }
                }
                return results[s.length()][p.length()] == 1;
            }
            else if(sStart >= s.length()) {
                results[sStartInit][i] = 2;
                return false;
            }
            else if(p.charAt(i) == s.charAt(sStart) || p.charAt(i) == '?') {
                sStart++;
            }
            else {
                results[sStartInit][i] = 2;
                return false;
            }
        }
        return sStart == s.length();
    }
}
__________________________________________________________________________________________________
6ms
class Solution {
    
    public boolean isFirstPosMatch(String s, int spos, String p, int ppos) {
        return (spos < s.length() &&
            (s.charAt(spos) == p.charAt(ppos) ||
             p.charAt(ppos) == '?'));
    }
    
    public boolean isMatch(String s, String p) {
        int[] scnt = new int[26];
        int[] pcnt = new int[26];
        for (int i = 0; i < s.length(); i++) {
            scnt[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < p.length(); i++) {
            char ch = p.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                pcnt[ch - 'a']++;
            }
        }
        int[][] match = new int[s.length() + 2][p.length() + 2];
        return isMatchHelper(s, 0, p, 0, match, scnt, pcnt);
    }
    
    public boolean isMatchHelper(String s, int spos, String p, int ppos, int[][] match, int[] scnt, int[] pcnt) {
        if (match[spos][ppos] != 0) {
            return match[spos][ppos] == 1;
        }
        if (ppos == p.length()) {
            match[spos][ppos] = spos == s.length() ? 1 : -1;
            return match[spos][ppos] == 1;
        }
        if (p.charAt(ppos) != '*') {
            boolean ok = isFirstPosMatch(s, spos, p, ppos);
            if (ok) {
                scnt[s.charAt(spos) - 'a']--;
                if (p.charAt(ppos) != '?') {
                    pcnt[p.charAt(ppos) - 'a']--;
                }
                ok &= isMatchHelper(s, spos + 1, p, ppos + 1, match, scnt, pcnt);
                if (p.charAt(ppos) != '?') {
                    pcnt[p.charAt(ppos) - 'a']++;
                }
                scnt[s.charAt(spos) - 'a']++;
            }
            match[spos][ppos] = ok ? 1 : -1;
            return ok;
        }
        while (ppos < p.length() && p.charAt(ppos) == '*') {
            ppos++;
        }
        while (spos < s.length() && pcnt[s.charAt(spos) - 'a'] <= scnt[s.charAt(spos) - 'a']) {
            match[spos][ppos] = isMatchHelper(s, spos, p, ppos, match, scnt, pcnt) ? 1 : -1;
            if (match[spos][ppos] == 1) {
                return true;
            }
            scnt[s.charAt(spos) - 'a']--;   
            spos++;
        }
        match[spos][ppos] = isMatchHelper(s, spos, p, ppos, match, scnt, pcnt) ? 1 : -1;
        return match[spos][ppos] == 1;
    }
}
__________________________________________________________________________________________________
36316 kb
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] dp = new boolean[p.length()][s.length()];
        
        if (s.length() == 0 && p.length() == 0) {
            return true;
        } else if (p.length() == 0) {
            return false;
        } else if (s.length() == 0) {
            for (int i = 0; i < p.length(); i++) {
                if (p.charAt(i) != '*') {
                    return false;
                }
            }
            return true;
        }
        
        boolean used = false;
        for (int i = 0; i < p.length(); i++) {
            if (i == 0 || dp[i - 1][0]) {
                if (p.charAt(i) == '*') {
                    dp[i][0] = true;
                } else if (!used && (p.charAt(i) == s.charAt(0) || p.charAt(i) == '?')) {
                    used = true;
                    dp[i][0] = true;
                }
            }
        }
        
        used = false;
        for (int j = 0; j < s.length(); j++) {
            if (j == 0 || dp[0][j - 1]) {
                if (p.charAt(0) == '*') {
                    dp[0][j] = true;
                } else if (!used && (p.charAt(0) == s.charAt(j) || p.charAt(0) == '?')) {
                    used = true;
                    dp[0][j] = true;
                }
            }
        }
        
        for (int j = 1; j < s.length(); j++) {
            for (int i = 1; i < p.length(); i++) {
                if (p.charAt(i) == '*' && (dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 1][j])) {
                    dp[i][j] = true;
                } else if ((p.charAt(i) == '?' || p.charAt(i) == s.charAt(j)) && dp[i - 1][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }
        
        return dp[p.length() - 1][s.length() - 1];
    }
}
__________________________________________________________________________________________________

class Solution {
    public boolean isMatch(String s, String p) {
        if (s == null || p == null)
            return false;

        if (p.length() == 0){
            return s.length() == 0;
        }
        
        boolean[][] dp = new boolean[p.length()][s.length() + 1];


        char[] string = s.toCharArray();
        char[] pattern = p.toCharArray();

        switch (pattern[0]) {
            case '*':
                for (int j = 0; j <= string.length; j++) {
                    dp[0][j] = true;
                }
                break;
            case '?':
                if (s.length() > 0)
                    dp[0][1] = true;
                break;
            default:
                if (s.length() > 0 && pattern[0] == string[0])
                    dp[0][1] = true;
        }

        for (int i = 1; i < pattern.length; i++) {
            if (dp[i - 1][0] && pattern[i] == '*')
                dp[i][0] = true;
            for (int j = 1; j <= string.length; j++) {
                if (pattern[i] == '*' && (dp[i - 1][j] || dp[i][j - 1])) {
                    dp[i][j] = true;
                }
                if (pattern[i] == string[j - 1] || pattern[i] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }

        return dp[p.length() - 1][s.length()];
    }
}
__________________________________________________________________________________________________