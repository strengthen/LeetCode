__________________________________________________________________________________________________
sample 1 ms submission
// 686
public class Solution {

	public int repeatedStringMatch(final String A, final String B) {

		final int aL = A.length();
		final int bL = B.length();

		if (aL >= bL) {
			if (A.indexOf(B) != -1) {
				return 1;
			} else {
				return (A + A).indexOf(B) == -1 ? -1 : 2;
			}
		}

		if (B.indexOf(A) == -1) {
			return (A + A).indexOf(B) == -1 ? -1 : 2;
		}

		int res = 0;
		int idx = B.indexOf(A);
		if (idx > 0) {
			if (A.indexOf(B.substring(0, idx)) == -1) {
				return -1;
			} else {
				res = 1;
			}
		}

		final int lastExpectedIdx = ((B.length() - idx) / aL) * aL;
		for (int i = idx; i < lastExpectedIdx; i += aL) {
			idx = B.indexOf(A, i);
			if (idx != i) {
				return -1;
			}
			res++;
		}

		if (idx + aL == bL) {
			return res;
		}

		if (A.indexOf(B.substring(idx + aL, bL)) != 0) {
			return -1;
		}

		return res + 1;
	}

	public static void main(String[] args) {
		System.out.println(new Solution().repeatedStringMatch("abcd", "bcdab"));
		System.out.println(new Solution().repeatedStringMatch("abcd", "abcdb"));
		System.out.println(new Solution().repeatedStringMatch("ab", "aba"));
		System.out.println(new Solution().repeatedStringMatch("a", "ab"));
		System.out.println(new Solution().repeatedStringMatch("a", "aa"));
		System.out.println(new Solution().repeatedStringMatch("ab", "babababa"));
		System.out.println(new Solution().repeatedStringMatch("ab", "bababab"));
		System.out.println(new Solution().repeatedStringMatch("bb", "bbbbbbb"));
		System.out.println(new Solution().repeatedStringMatch("ba", "bab"));
		System.out.println(new Solution().repeatedStringMatch("abaa", "ba"));
	}
}
__________________________________________________________________________________________________
sample 36684 kb submission
class Solution {
    public int repeatedStringMatch(String A, String B) {
        int limit = Math.max(A.length(), B.length());
        StringBuilder repeating = new StringBuilder(A);
        // check
        Set<Character> setA = new HashSet();
        for(char letter : A.toCharArray()) setA.add(letter);
        
        Set<Character> setB = new HashSet();
        for(char letter : B.toCharArray()) setB.add(letter);
        
        if (setB.size() > setA.size()) return (-1);
            
        // count
        for (int i = 0; i <= limit; i++) {
            if (repeating.indexOf(B) != -1) {
                return (i + 1);
            } else {
                repeating.append(A);
            }
        }
        return (-1);
    }
}
__________________________________________________________________________________________________
