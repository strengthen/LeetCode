__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String nearestPalindromic(String n) {
        if (n == null) return null;
        // form the first palindrome number based on n
        char[] arr = n.toCharArray();
        for (int i = 0; i < arr.length / 2; i++) {
            arr[arr.length - 1 - i] = arr[i];
        }
        String start = new String(arr);
        if (n.equals(start)) {
            String smaller = findNextPalindrome(start, false);
            String larger = findNextPalindrome(start, true);
            String diffS = getDiff(n, smaller);
            String diffL = getDiff(larger, n);
            return isSmaller(diffL, diffS) ? larger : smaller;
        } else {
            if (isSmaller(start, n)) { // start < n
                String larger = findNextPalindrome(start, true);
                return isSmaller(getDiff(larger, n), getDiff(n, start)) ? larger : start;
            } else { // start > n
                String smaller = findNextPalindrome(start, false);
                return isSmaller(getDiff(start, n), getDiff(n, smaller)) ? start : smaller;
            }
        }
    }
    
    private String findNextPalindrome(String start, boolean smallerThan) {
        // since next palindrome number may shorter or longer than tgt, I use StringBuilder to form the number
        StringBuilder sb = new StringBuilder(start);
        int mid = (sb.length() - 1) / 2;
        char cur = sb.charAt(mid);
        if (smallerThan) { // find a larger palindrome num
            // be careful with 9s
            if (cur != '9') {
                sb.setCharAt(mid, (char)(cur + '1' - '0'));
                if (sb.length() % 2 == 0) sb.setCharAt(mid + 1, (char)(cur + '1' - '0'));
            } else {
                // count the number of 9s
                int i = mid;
                while (i >=0 && sb.charAt(i) == '9') {
                    if (i == 0) {
                        sb.setCharAt(i, '1');
                        sb.setCharAt(sb.length() - 1, '0');
                        sb.append('1');
                        return sb.toString();
                    } else {
                        sb.setCharAt(i, '0');
                        sb.setCharAt(sb.length()-1-i, '0');
                    }
                    i--;
                }
                sb.setCharAt(i, (char)(sb.charAt(i) + '1' - '0'));
                sb.setCharAt(sb.length()-1-i, sb.charAt(i));
            }
            return sb.toString();
        } else { // find a smaller palindrome num
            // be carefull with mid is the leftmost position and the digit is 1
            // be careful with 0s
            if (mid == 0 && cur == '1') return sb.length() == 1 ? "0" : "9";
            if (cur != '0') {
                sb.setCharAt(mid, (char)(cur - '1'+ '0'));
                if (sb.length() % 2 == 0) sb.setCharAt(mid + 1, (char)(cur - '1'+ '0'));
            } else {
                // count the number of 0s
                int i = mid;
                while (i >= 0 && sb.charAt(i) == '0') {
                    sb.setCharAt(i, '9');
                    sb.setCharAt(sb.length()-1-i, '9');
                    i--;
                }
                if (i == 0 && sb.charAt(0) == '1') {
                    sb.setCharAt(0, '9');
                    sb.deleteCharAt(sb.length() - 1);
                    return sb.toString();
                }
                sb.setCharAt(i, (char)(sb.charAt(i) - '1' + '0'));
                sb.setCharAt(sb.length()-1-i, sb.charAt(i));
            }
            return sb.toString();
        }
    }
    
    private String getDiff(String l, String s) {
        char[] res = new char[s.length()];
        int borrow = 0;
        int nonZ = res.length - 1;
        for(int i = res.length - 1; i >= 0; i--) {
            int tmp = borrow;
            if (l.length() != s.length()) {
                tmp += l.charAt(i+1) - s.charAt(i);
            } else {
                tmp += l.charAt(i) - s.charAt(i);
            }
            if (tmp < 0) {
                tmp += 10;
                borrow = -1;
            } else borrow = 0;
            res[i] = (char)(tmp + '0');
            if (tmp != 0) nonZ = i;
        }
        return new String(res, nonZ, res.length - nonZ);
    }
    
    private boolean isSmaller(String s, String l) {
        if (l.length() > s.length()) return true;
        if (l.length() < s.length()) return false;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < l.charAt(i)) return true;
            if (s.charAt(i) > l.charAt(i)) return false;
        }
        return false;
    }
}
__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public String nearestPalindromic(String n) {
        int len = n.length();
        int i = len % 2 == 0? len/2 - 1 : len / 2;
        long left = Long.parseLong(n.substring(0, i + 1));
        
        //find candidate
        List<Long> candidates = new ArrayList<>();
        candidates.add(getPalindrome(left, len % 2 == 0));
        candidates.add(getPalindrome(left + 1, len % 2 == 0));
        candidates.add(getPalindrome(left - 1, len % 2 == 0));
        candidates.add((long)Math.pow(10, len - 1) - 1);
        candidates.add((long)Math.pow(10, len) + 1);
        
        long diff = Long.MAX_VALUE;
        long res = 0;
        long nl = Long.parseLong(n);
        
        for (long ca: candidates) {
            if (ca == nl) continue;
            if (Math.abs(ca - nl) < diff) {
                diff = Math.abs(ca - nl);
                res = ca;
            } else if (Math.abs(ca - nl) == diff) {
                res = Math.min(res, ca);   
            }
        }
        return String.valueOf(res);
    }
    
    private long getPalindrome(long left, boolean even) {
        long res = left;
        if (!even) left = left / 10;
        while (left > 0) {
            res = res * 10 + left % 10;
            left /= 10;
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 36808 kb submission
class Solution {
    public String nearestPalindromic(String n) {
        
        long nVal = Long.parseLong(n);
        
        if (nVal <= 10 || ((nVal % 10 == 0) && (n.charAt(0) == '1') && Integer.valueOf(n.substring(1)) == 0))
            return String.valueOf(nVal - 1);
        
        if (nVal == 11 || ((nVal % 10 == 1) && (n.charAt(0) == '1') && (n.charAt(n.length() - 1) == '1') && Integer.valueOf(n.substring(1, n.length() - 1)) == 0))
            return String.valueOf(nVal - 2);
        
        
        boolean notAllNine = false;
        for (int i = 0; i < n.length(); i++)
            if (n.charAt(i) != '9')
                notAllNine = true;
        
        if (!notAllNine && nVal >= 99)
            return String.valueOf(nVal + 2);
        
        String palindromeRoot = n.substring(0, (n.length() + 1) / 2);
        int valPalindromeRoot = Integer.valueOf(palindromeRoot); 
        long tmpEqual = Long.parseLong(toPalindromeDigits(valPalindromeRoot, n.length() % 2 == 0));
        long tmpBigger = Long.parseLong(toPalindromeDigits(valPalindromeRoot + 1, n.length() % 2 == 0));   
        long tmpSmaller = Long.parseLong(toPalindromeDigits(valPalindromeRoot - 1, n.length() % 2 == 0));
        long distEqual = Math.abs(nVal - tmpEqual);
        long distBigger = Math.abs(nVal - tmpBigger);
        long distSmaller = Math.abs(nVal - tmpSmaller);
        
        long distMin = 0L;
        if (distEqual == 0)
            distMin = Math.min(distBigger, distSmaller);
        else
            distMin = Math.min(distEqual, Math.min(distBigger, distSmaller));     
        
        if (distMin == distSmaller)
            return String.valueOf(tmpSmaller);
        
        if (distMin == distEqual)
            return String.valueOf(tmpEqual);
        
        return String.valueOf(tmpBigger);
        
    }

    String toPalindromeDigits(int num, boolean isEvenDigits) {

        String numStr = String.valueOf(num);
        if (isEvenDigits)
            return numStr + (new StringBuilder(numStr).reverse()).toString();
        
        return numStr + (new StringBuilder(numStr).reverse().deleteCharAt(0)).toString();
    
    }
}