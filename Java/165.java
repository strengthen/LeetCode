__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int compareVersion(String version1, String version2) {
        
        int i = 0, j = 0;
        int temp1, temp2;
        while (i < version1.length() || j < version2.length()) {
            temp1 = 0;
            temp2 = 0;
            
            while (i < version1.length() && version1.charAt(i) != '.') {
                temp1 = temp1 * 10 + Character.getNumericValue(version1.charAt(i++));
            }
            
            while (j < version2.length() && version2.charAt(j) != '.') {
                temp2 = temp2 * 10 + Character.getNumericValue(version2.charAt(j++));
            }
            
            if (temp1 == temp2) {
                i++;
                j++;
                continue;
            } else if (temp1 < temp2) return -1;
            else return 1;
        }
        
        return 0;
    }
}
__________________________________________________________________________________________________
sample 32728 kb submission
class Solution {
    public int compareVersion(String version1, String version2) {
        int len1 = version1.length(),len2 = version2.length();
        int i = 0,j = 0;
        while(i<len1 || j<len2) {
            int temp1 = 0;
            int temp2 = 0;
            while(i<len1 && version1.charAt(i) != '.') {
                temp1 = temp1*10 + version1.charAt(i++)-'0';
            
            }
            while(j<len2 && version2.charAt(j) != '.') {
                temp2 = temp2*10 + version2.charAt(j++)-'0';
            
            }
            if(temp1>temp2) {
                return 1;
            } else if(temp1<temp2) {
                return -1;
            } else {
                i++;
                j++;
            }
        }          
        return 0;
    }    
}
__________________________________________________________________________________________________
