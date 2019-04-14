class Solution {
    public int longestArithSeqLength(int[] A) {
        Map<Integer, Map<Integer, Integer>> dp = new HashMap<>(); // <difference, <Index of Element for this difference, count of sequence>>
        int max = 2;
        for (int i = 0; i < A.length; i++) {
            for (int j = i + 1; j < A.length; j++) {
                int a = A[i], b = A[j];
                Map<Integer, Integer> diffMap = dp.computeIfAbsent(b - a, c -> new HashMap<>());
                int currMax = Math.max(diffMap.getOrDefault(j, 0), diffMap.getOrDefault(i, 0) + 1); // if the element for the difference is i (variable a = A[i]), then we can add 1 to the count of sequence
                diffMap.put(j, currMax);
                max = Math.max(max, currMax + 1);
            }
        }
        return max;
    }
}