__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public String decodeAtIndex(String S, int K) {
        int strLen = S.length();
        int[] endingIndex = new int[strLen];
        int arrayLen = strLen;
        long count = 0;
        for (int i = 0; i < strLen; i++) {
            char c = S.charAt(i);
            if (Character.isLetter(c)) {
                count += 1;
                endingIndex[i] = (int)count;
            } else if (Character.isDigit(c)) {
                count *= Character.getNumericValue(c);
                endingIndex[i] = (int)count;
            } else {
            }
            if (K < count) {
                arrayLen = i;
                break;
            }
        }
        //System.out.println(Arrays.toString(endingIndex));
        int tmp = K;
        int j = arrayLen-1;
        while (j >= 0) {
            //System.out.println("endingIndex["+j+"]="+endingIndex[j]);
            //System.out.println("tmp="+tmp);            
            if ((tmp == endingIndex[j] && Character.isLetter(S.charAt(j))) ||
                (tmp == 0 && Character.isLetter(S.charAt(j)))) {
                //System.out.println("break branch");
                break;
            } else if (endingIndex[j] < tmp) {
                tmp %= endingIndex[j];
                //System.out.println("mod branch");
            } else {
                j--;
                //System.out.println("else branch");
            }
        }
        return Character.toString(S.charAt(j));
    }
}
__________________________________________________________________________________________________
sample 35288 kb submission
class Solution {
    public String decodeAtIndex(String S, int K) {
        int n = S.length();
        long size = 0;
        //S = "leet2code3", K = 10  out: "o"
        //"leetleetcodeleetleetcodeleetleetcode"
        for (int i = 0; i < n; i++)
            if (Character.isDigit(S.charAt(i))) size *= (S.charAt(i) - '0');
            else size++;
        for (int i = n - 1; i >= 0; i--) {
            if (Character.isDigit(S.charAt(i))) {
                size /= (S.charAt(i) - '0');
                continue;
            }
            if (K > size)
                K = (int) (K % size);
            if (K == size || K == 0)
                return String.valueOf(S.charAt(i));
            size--;
        }
        return null;
    }
}
__________________________________________________________________________________________________
