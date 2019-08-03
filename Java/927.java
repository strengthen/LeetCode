__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int[] threeEqualParts(int[] A) {
        
        int ones = 0;
        int k = 3;
        
        for (int i = 0; i < A.length; i++) {
            ones += A[i];
        }
        
        if (ones == 0) return new int[] {0, 2};
        if (ones % k != 0) return new int[] {-1, -1};
        
        ones = ones / k;
        int[] index = new int[2 * k];
        
        int i = 0;
        for (int l = 0; l < k; l++) {            
            while (i < A.length && A[i] == 0) i++;
            index[2 * l] = i;
            
            int currOnes = 0;
            int c = 0;
            for ( ; i < A.length && currOnes < ones; i++, c++) {
                if (l > 0 && A[i] != A[index[2 * (l - 1)] + c]) 
                    return new int[] {-1, -1};
                
                currOnes += A[i];
            }
            
            index[2 * l + 1] = i - 1;
        }
        
        int zeroes = A.length - index[2 * k - 1];
        for (int l = 1; l < 2*k - 1; l += 2) {
            if (index[l + 1] - index[l] < zeroes) 
                return new int[] {-1, -1};
        }
        
        return new int[] {index[1] + zeroes - 1, index[3] + zeroes};
    }
}
__________________________________________________________________________________________________
sample 42760 kb submission
class Solution {
    public int[] threeEqualParts(int[] a) {
        final int[] IMPOSSIBLE = new int[] {-1,-1};

        int count = 0;
        for (int i = 0; i < a.length; i++) {
            if (a[i] == 1) {
                count++;
            }
        }
        if (count == 0) {
            return new int[] {0, a.length - 1};
        }
        
        if (count < 3 || count % 3 != 0) {
            return IMPOSSIBLE;
        }

        int index = 0;
        int index0 = -1;
        int index1 = -1;
        int index2 = -1;

        for (int i = 0; i < a.length; i++) {
            if (a[i] == 1) {
                index++;
            }
            if (index == 1 && index0 == -1) {
                index0 = i;
            } else if (count / 3 + 1 == index && index1 == -1) {
                index1 = i;
            } else if (count / 3 * 2 + 1 == index && index2 == -1) {
                index2 = i;
                break;
            }
        }

        for (int i = 0; i < a.length - index2; i++) {
            if (a[index0 + i] != a[index1 + i] || a[index0 + i] != a[index2 + i]) {
                return IMPOSSIBLE;
            }
        }

        return new int[] {index0 + a.length - index2 - 1, index1 + (a.length - index2)};
    }
}
__________________________________________________________________________________________________
