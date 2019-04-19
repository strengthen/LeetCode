__________________________________________________________________________________________________
0ms
class Solution {
    public int strStr(String haystack, String needle) {
        return haystack.indexOf(needle);
    }
}
__________________________________________________________________________________________________
0ms
public class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.length()==0) {
            return 0;
        }
        for (int i = 0; i <haystack.length()-needle.length()+1; i++) {
            if (haystack.substring(i,i+needle.length()).equals(needle)) {
                return i;
            }
        }
        return -1;
    }
}
__________________________________________________________________________________________________
1ms
class Solution {
    public int strStr(String haystack, String needle) {
        if (needle == null || needle.length() == 0) return 0;
        int n = needle.length();
        for (int i = 0; i <= haystack.length() - n; i++) {
            int m = 0;
            for (int j = i; m < n; m++,j++) {
                if (haystack.charAt(j) != needle.charAt(m)) break;
            }
            if (m == n) return i;
        }
        return -1;
    }
}
__________________________________________________________________________________________________
34284 kb
class Solution {
    public int strStr(final String haystack, final String needle) {
        if (haystack == null || needle == null || haystack.length() < needle.length()) {
            return -1;
        }
        if (needle.isEmpty()) {
            return 0;
        }
        final int lenH = haystack.length();
        final int lenN = needle.length();
        if (lenN < 256) {
            final int[] lps = pmt(needle);
            for (int i = 0; i != lenH;) {
                final int cur = i;
                if (lenH < lenN + cur) {
                    return -1;
                }
                for (int j = 0;;) {
                    if (j == lenN) {
                        return cur;
                    }
                    if (haystack.charAt(i) == needle.charAt(j)) {
                        ++i; ++j;
                    } else if (j != 0) {
                        final int skip = j - lps[j-1];
                        i = cur + skip;
                        break;
                    } else {
                        ++i;
                        break;
                    }
                }
            }
        } else {
            LOOP:
            for (int i = 0; i != lenH; ++i) {
                for (int j = 0; j != lenN; ++j) {
                    if (i + j == lenH) {
                        return -1;
                    }
                    if (haystack.charAt(i+j) != needle.charAt(j)) {
                        continue LOOP;
                    }
                }
                return i;
            }
        }

        return -1;
    }

    private int[] pmt(final String pattern) {
        final int len = pattern.length();
        int[] pmt = new int[len]; // defaults all element is 0
        final char[] p = pattern.toCharArray();

        for (int i = 1; i != len; ++i) {
            for (int j= 0; j != i; ++j) {
                if (arrayEquals(p, 0, j+1, i-j, i+1, i)) {
                    pmt[i] = j+1;
                }
            }
        }

        return pmt;
    }
    
    private boolean arrayEquals(final char[] charArray, final int leftFrom,
                                       final int leftTo, final int rightFrom, 
                                       final int rightTo, final int totalLen) {
        final int len = leftTo- leftFrom;
        if (len < 5 || len <= totalLen / 4) {
            for (int i = 0; i != len; ++i) {
                if (charArray[leftFrom + i] != charArray[rightFrom + i]) {
                    return false;
                }
            }
            return true;
        }
        final int mid = len / 2;

        return arrayEquals(charArray, leftFrom, leftFrom + mid, rightFrom, rightFrom + mid, totalLen) &&
               arrayEquals(charArray, leftFrom + mid, leftTo, rightFrom + mid, rightTo, totalLen);
    }
}
__________________________________________________________________________________________________
34524
class Solution {
    public int strStr(String haystack, String needle) {
		int result = -1;
		if(null == needle || needle.trim().isEmpty()){
			return 0;
		}

		char ch = needle.charAt(0);
		int needleLength = needle.length();
		int haystackLength = haystack.length();
		for(int index=0; index<haystackLength; index++){
			char currCh = haystack.charAt(index);
			if(currCh == ch){
				if(haystackLength - index < needleLength){
					result = -1;
					break;
				} else {
					String temp = haystack.substring(index, index+needleLength);
					if(temp.equals(needle)){
						result = index;
                        break;
					}
				}
			}

		}

		return result;
	}
}
__________________________________________________________________________________________________
