__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public boolean canReorderDoubled(int[] A) {
        int[] countNum = new int[20001];
        for (int a : A) {
            countNum[a + 10000] += 1;
        }

        for (int i = 1; i <= 10000; i++) {
            if (countNum[10000 + i] > 0){
                if (countNum[10000 + i * 2] >= countNum[10000 + i]) {
                    countNum[10000 + i * 2] -= countNum[10000 + i];
                } else {
                    return false;
                }
            }

            if (countNum[10000 - i] > 0) {
                if (countNum[10000 - i * 2] >= countNum[10000 - i]) {
                    countNum[10000 - i * 2] -= countNum[10000 - i];
                } else {
                    return false;
                }
            }
        }

        return true;
    }
}
__________________________________________________________________________________________________
sample 40604 kb submission
class Solution {
    public boolean canReorderDoubled(int[] A) {
        // count[x] = the number of occurrences of x in A
        Map<Integer, Integer> count = new HashMap();
        for (int x: A)
            count.put(x, count.getOrDefault(x, 0) + 1);

        // B = A as Integer[], sorted by absolute value
        Integer[] B = new Integer[A.length];
        for (int i = 0; i < A.length; ++i)
            B[i] = A[i];
        Arrays.sort(B, Comparator.comparingInt(Math::abs));

        for (int x: B) {
            // If this can't be consumed, skip
            if (count.get(x) == 0) continue;
            // If this doesn't have a doubled partner, the answer is false
            if (count.getOrDefault(2*x, 0) <= 0) return false;

            // Write x, 2*x
            count.put(x, count.get(x) - 1);
            count.put(2*x, count.get(2*x) - 1);
        }

        // If we have written everything, the answer is true
        return true;
    }
}
__________________________________________________________________________________________________
