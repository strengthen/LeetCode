__________________________________________________________________________________________________
0ms
class Solution {
    public String longestCommonPrefix(String[] strs) {

        if (strs==null || strs.length==0 || strs[0].length()==0) {
            return "";
        }
        
        
        int index = 0;
        
        while(true) {
            if (!allSameAtIndex(strs, index)) {
                break;
            }
            index++;
        }

        
        return strs[0].substring(0, index);
        
    }
    
    public boolean allSameAtIndex(String[] strs, int index) {
        boolean result = true;
        if (strs==null || strs.length==0 || strs[0].length()==0 || index >=strs[0].length()) {
            return false;
        }
        
        char currentChar = strs[0].charAt(index);
        for (int i=0; i<strs.length; i++) {
            if (index >= strs[i].length()) {
                result = false;
                break;
            }
            
            if (strs[i].charAt(index) != currentChar) {
                result = false;
                break;
            }
        }
        
        return result;
    }
}
__________________________________________________________________________________________________
1ms
class Solution {
    public String longestCommonPrefix(String[] strs) {
        String ans = "";
        if (strs.length == 0) return ans;
        int len = strs[0].length();
        for (int i = 1 ; i < strs.length ; i++) {
            if (strs[i].length() < len) {
                len = strs[i].length();
            }
        }
        for (int l = 0 ; l < len ; l++) {
            boolean isGood = true;
            char c = strs[0].charAt(l);
            for (int i = 1 ; i < strs.length ; i++) {
                isGood = isGood & c == strs[i].charAt(l);
            }
            if (isGood) {
                ans = ans + c;
            } else {
                break;
            }
        }
        return ans;
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public String longestCommonPrefix(String[] strs) {
         String longest = "";
        int len = Integer.MAX_VALUE;
      
         if(strs.length ==0 || strs == null) return longest;
        
         String tmp = strs[0];

        for(String s : strs){
        	if(s.length() < len){
        		tmp = s;
        		longest =s;
        		len = s.length();
        	}
        }
        
		for(String s : strs){
			StringBuilder sb = new StringBuilder();
			for(int i=0; i< tmp.length();i++){
				if( s.charAt(i) == tmp.charAt(i)){
					sb.append(tmp.charAt(i));
				}else {
					break;
				}
			}
			if (sb.length() <= tmp.length()){
                tmp = sb.toString();
				longest = (sb.length() ==0) ? "" : sb.toString();
			}
		}
		return longest;
        
    }
}
__________________________________________________________________________________________________
34688 kb 
class Solution {
    // IDEA: find the string with the min len, 
    // then shring it until a prefix is found.
    
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) return "";
        
        String res = getMinString(strs);
        if (res.length() == 0) return "";
        
        for (String s : strs) {
            
            // Keep shrinking res until a prefix for s is found.
            while (s.indexOf(res) != 0)
                res = res.substring(0, res.length() - 1);
            
            // If res gets down to empty string, return ""
            if (res.length() == 0) return res;
        }
        
        return res;
    }
    
    public String getMinString(String[] strs) {
        String result = strs[0];
        for (String s : strs) {
            if (s.length() < result.length()) {
                result = s;
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________
34780 kb
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length < 1) return "";
        
        // find the *max word
        // find the *min word
        // max and min are in terms of alphabetical order NOT length
        // set default value to initial position
        String max = strs[0];
        String min = strs[0];
        
        // iterate and find max and min
        for (String str : strs)
        {
            if (str.compareTo(max) > 0) max = str;
            else if(str.compareTo(min) < 0) min = str; 
        }
        
        // iterate through substrings
        // while i is less than max.length and min.length;
        String longest = "";
        int i = 0;
        while(i < max.length() && i < min.length() && max.charAt(i) == min.charAt(i))
        {
            longest = max.substring(0, i + 1);  // b/c end is exclusive
            i++;
        }
        return longest;
    }
}
__________________________________________________________________________________________________
