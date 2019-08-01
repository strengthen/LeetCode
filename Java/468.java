__________________________________________________________________________________________________
sample 0 ms submission
public class Solution {
    //100% 
    public String validIPAddress(String IP) {
        String ans = null;
        if (isValidIPv4(IP))
            ans = "IPv4";
        else if (isValidIPv6(IP))
            ans = "IPv6";
        return ans == null ? "Neither" : ans;
    }

    public boolean isValidIPv4(String s) {
        int dotCount = 0, nDigit = 0;
        int i, j, sum;
        i = j = sum = 0;
        while (j < s.length()) {
            char c = s.charAt(j);
            if (c != '.') {
                if (!((c - '0') >= 0 && (c - '0') <= 9)) return false;
                if (j - i > 0 && s.charAt(i) == '0') return false;
                if (++nDigit > 3) return false;
                sum = sum * 10 + (c - '0');
                if (sum > 255) return false;
                j++;
            } else {
                if (nDigit == 0) return false;
                nDigit = 0;
                dotCount++;
                sum = 0;
                j++;
                i = j;
            }
        }
        if (dotCount != 3 || nDigit == 0) return false;
        return true;
    }

    public boolean isValidIPv6(String s) {
        int nDigit, dotCount;
        int i, j;
        i = j = nDigit = dotCount = 0;
        while (j < s.length()) {
            char c = s.charAt(j);
            if (c != ':') {
                if (!(((c - '0') >= 0 && (c - '0') <= 9) ||
                        ((c - 'a') >= 0 && (c - 'a') <= 5) ||
                        ((c - 'A') >= 0 && (c - 'A') <= 5))) return false;
                if (++nDigit > 4) return false;
                j++;
            } else {
                if (nDigit == 0) return false;
                nDigit = 0;
                dotCount++;
                j++;
                i = j;
            }
        }
        if (dotCount != 7 || nDigit == 0) return false;
        return true;
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String validIPAddress(String IP) {
        if(isIPv4(IP)) return "IPv4";
        else if(isIPv6(IP)) return "IPv6";
        else return "Neither";
    }
    
    public boolean isIPv6(String IP){
        // split(,-1) won't omit empty string
        String[] groups = IP.split(":", -1);
        if(groups.length != 8) return false;
        for(String group : groups){
            // allow ...:0:...
            if(group.length() == 1 && group.charAt(0) == '0') continue;
            // leading zero is allowed
            if(group.length() > 4 || group.length() == 0) return false;
            for(char c : group.toCharArray()){
                boolean isDigit = c >= 48 && c <= 57;
                boolean isUpperCaseAF = c >= 65 && c <= 70;
                boolean isLowerCaseAF = c >= 97 && c <= 102;
                if(!(isDigit || isUpperCaseAF || isLowerCaseAF)) return false;
            }
            
        }
        return true;
    }
    
    public boolean isIPv4(String IP){
        String[] groups = IP.split("\\.", -1);
        if(groups.length != 4) return false;
        for(String group : groups){
            if(group.length() == 0) return false;
            int sum = 0;
            char[] digits = group.toCharArray();
            for(int i = 0; i < digits.length; i++){
                // prevent leading zero
                if((digits[0] == '0' && i > 0) 
                   || !Character.isDigit(digits[i])) return false;
                sum = 10*sum + (digits[i] - '0');
            }
            
            if(sum < 0 || sum > 255) return false;
        }
        
        return true;
    }
}
__________________________________________________________________________________________________
sample 36508 kb submission
class Solution {
 public String validIPAddress(String IP) {
	if(isValidIPv4(IP)) return "IPv4";
	else if(isValidIPv6(IP)) return "IPv6";
	else return "Neither";
}

public boolean isValidIPv4(String ip) {
	if(ip.length()<7) return false;
	if(ip.charAt(0)=='.') return false;
	if(ip.charAt(ip.length()-1)=='.') return false;
	String[] tokens = ip.split("\\.");
	if(tokens.length!=4) return false;
	for(String token:tokens) {
		if(!isValidIPv4Token(token)) return false;
	}
	return true;
}
public boolean isValidIPv4Token(String token) {
	if(token.startsWith("0") && token.length()>1) return false;
	try {
		int parsedInt = Integer.parseInt(token);
		if(parsedInt<0 || parsedInt>255) return false;
		if(parsedInt==0 && token.charAt(0)!='0') return false;
	} catch(NumberFormatException nfe) {
		return false;
	}
	return true;
}
	
public boolean isValidIPv6(String ip) {
	if(ip.length()<15) return false;
	if(ip.charAt(0)==':') return false;
	if(ip.charAt(ip.length()-1)==':') return false;
	String[] tokens = ip.split(":");
	if(tokens.length!=8) return false;
	for(String token: tokens) {
		if(!isValidIPv6Token(token)) return false;
	}
	return true;
}
public boolean isValidIPv6Token(String token) {
	if(token.length()>4 || token.length()==0) return false;
	char[] chars = token.toCharArray();
	for(char c:chars) {
		boolean isDigit = c>=48 && c<=57;
		boolean isUppercaseAF = c>=65 && c<=70;
		boolean isLowerCaseAF = c>=97 && c<=102;
		if(!(isDigit || isUppercaseAF || isLowerCaseAF)) 
			return false;
	}
	return true;
 }   
}