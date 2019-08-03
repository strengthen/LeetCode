__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int minFlipsMonoIncr(String S) {
        char[] cs = S.toCharArray();
        int zc = 0; // 0s count
        int oc = 0; // 1s count
        for (char c : cs) {
            if (c == '0') {
                zc++;
            } else {
                oc++;
            }
        }
        
        int min = Math.min(zc, oc);
        int flips_2 = zc;
        int flips_1 = 0;
        for (int i = 0; i < cs.length; i++) {
            if (cs[i] == '1') {
                min = Math.min(min, flips_1 + flips_2);
                flips_1++;
            } else {
                flips_2--;
            }
        }
        return min;
    }
}
__________________________________________________________________________________________________
sample 37356 kb submission
class Solution {
    public int minFlipsMonoIncr(String S) {

		int len = S.length();

		int[] left2Right = new int[len];
		left2Right[0] = S.charAt(0) - '0';

		for (int i = 1; i < len; i++) {
			left2Right[i] = left2Right[i - 1] + S.charAt(i) - '0';
		}

		int[] right2Left = new int[len];
		right2Left[len - 1] = S.charAt(len - 1) == '1' ? 0 : 1;

		for (int i = len - 2; i >= 0; i--) {
			right2Left[i] = right2Left[i + 1] + (S.charAt(i) == '1' ? 0 : 1);
		}

		int res = Integer.MAX_VALUE;
		for (int i = 0; i < len; i++) {
			res = Math.min(res, left2Right[i] + right2Left[i] - 1);
		}

		return res;
	
    }
}
__________________________________________________________________________________________________
