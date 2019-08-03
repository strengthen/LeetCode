__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public int lenLongestFibSubseq(int[] A) {
        int len = A.length, ans = 0;
        for (int i = 0; i < len - 2; i++) {
            int pos = i + 2;
            for (int j = i + 1; j < len - 1; j++) {
                int sum = A[i] + A[j];
                while (pos < len && A[pos] < sum) pos++;
                if (pos == len) return ans;
                if (A[pos] != sum) continue;
                int b = sum, c = sum + A[j], curLen = 3, k = pos;
                while (true) {
                    while (k < len && A[k] < c) k++;
                    if (k == len) break;
                    if (A[k] != c) break;
                    curLen++;
                    c = c + b;
                    b = c - b;
                }
                ans = Math.max(ans, curLen);
            }
            if (pos == len) break;
        }
        return ans;
    }
}
__________________________________________________________________________________________________
sample 37548 kb submission
class Solution {
    public int lenLongestFibSubseq(int[] A) {
        Set<Integer> set = new HashSet<Integer>();
        Arrays.stream(A)
                .forEach(set::add);

        int length = 0;
        for (int i = 0; i < A.length - 1; ++i) {
            for (int j = i + 1; j < A.length; ++j) {
                int a = A[i];
                int b = A[j];
                int count = 2;
                while (set.contains(a + b)) {
                    ++count;
                    b = a + b;
                    a = b - a;
                }

                length = Math.max(length, count);
            }
        }

        return length > 2 ? length : 0;
    }
}
__________________________________________________________________________________________________
