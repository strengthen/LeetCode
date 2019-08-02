__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public String maskPII(String S) {
        if (Character.isLetter(S.charAt(0))) {
            return mail(S);
        } else {
            return phone(S);
        }
    }
    
    private String mail(String s) {
        StringBuilder sb = new StringBuilder();
        s = s.toLowerCase();
        int idx = s.indexOf('@');
        sb.append(s.charAt(0));
        sb.append("*****");
        sb.append(s.substring(idx - 1));
        return sb.toString();
    }
    
    private String phone(String s) {
        StringBuilder sb = new StringBuilder();
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (Character.isDigit(s.charAt(i))) {
                cnt++;
            }
        }
        if (cnt > 10) {
            sb.append('+');
            for (int i = 10; i < cnt; i++) {
                sb.append('*');
            }
            sb.append('-');
        }
        sb.append("***-***-");
        for (int i = 0, c = 0; i < s.length(); i++) {
            if (Character.isDigit(s.charAt(i))) {
                if (++c > cnt - 4) {
                    sb.append(s.charAt(i));
                }
            }
        }
        return sb.toString();
    }    
}
__________________________________________________________________________________________________
sample 35500 kb submission
class Solution {
    public String maskPII(String S) {
        return getMasker(S).mask(S);
    }
    
    private IMasker getMasker(String s) {
        if(s.contains("@")) {
            return new EmailMasker();
        } else {
            return new PhoneMasker();
        }
    }
    
    interface IMasker {
        String mask(String s);
    }
    
    class EmailMasker implements IMasker {
        @Override
        public String mask(String s) {
            s = s.toLowerCase();
            int atIndex = s.indexOf("@");
            StringBuilder sb = new StringBuilder();
            sb.append(s.charAt(0));
            sb.append("*****");
            sb.append(s.charAt(atIndex - 1));
            sb.append(s.substring(atIndex));
            return sb.toString();
        }
    }
    
    class PhoneMasker implements IMasker {
        @Override
        public String mask(String s) {
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < s.length(); i++) {
                if(s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                    sb.append(s.charAt(i));
                }
            }
            
            StringBuilder result = new StringBuilder();
            int localStartIndex = sb.length() - 10;
            if(sb.length() > 10) {
                result.append("+" + printRepeatChar('*', localStartIndex) + "-");
            }
            result.append(printRepeatChar('*', 3));
            result.append('-');
            result.append(printRepeatChar('*', 3));
            result.append('-');
            result.append(sb.substring(localStartIndex + 6));
            
            return result.toString();
        }
    }
    
    private String printRepeatChar(char c, int times) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < times; i++) {
            sb.append(c);
        }
        return sb.toString();
    }
}
__________________________________________________________________________________________________
