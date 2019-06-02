__________________________________________________________________________________________________
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (str1.equals(str2)) return str1;
        StringBuilder commonStr = new StringBuilder();
        int n = Math.min(str1.length(), str2.length());
        for (int i=0; i<n; i++){
            if (str1.charAt(i) == str2.charAt(i)){
                commonStr.append(str1.charAt(i));
            } else {
                break;
            }
        }
        if (commonStr.length() != n){
            return "";
        } else {
            StringBuilder remainder = (str1.length() < str2.length()) ?
                    new StringBuilder(str2.substring(n)): new StringBuilder(str1.substring(n));
            return gcdOfStrings(commonStr.toString(), remainder.toString());
        }
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
