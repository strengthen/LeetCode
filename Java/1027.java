__________________________________________________________________________________________________
sample 10 ms submission
class Solution {
    public int longestArithSeqLength(int[] A) {
        int N = A.length;
        int[][] dp = new int[N][N];
        int[] positions = new int[20000];
        Arrays.fill(positions, -1);
        int max = 0;
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                int prev = A[i] - (A[j] - A[i]);
                if(prev < 0 || positions[prev] == -1) continue;
                dp[i][j] = dp[positions[prev]][i] + 1;
                max = Math.max(max, dp[i][j]);
            }
            positions[A[i]] = i;
        }
        return max + 2;
    }
}
__________________________________________________________________________________________________
sample 35440 kb submission
class Solution {

    public int longestArithSeqLength(int[] input) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < input.length; i++) {
            List<Integer> subList = map.computeIfAbsent(input[i], z -> new ArrayList<>());
            subList.add(i);
        }
        
        int longest = 2;
        for (int i = 0; i < input.length - 1; i++) {
            for (int j = i + 1; j < input.length - 1; j++) {
                int diff = input[i] - input[j];
                longest = Math.max(longest, longestArithSeqLength(input, map, j, diff) + 2);
            }
        }

        return longest;
    }

    public int longestArithSeqLength(int[] input, Map<Integer, List<Integer>> map, int orig_idx, int diff) {
        int longest = 0;
        int expected = input[orig_idx] - diff;
        List<Integer> idxList = map.get(expected);
        // System.out.printf("Idx: %d, diff: %d, expected: %d, idxList: %s\n", orig_idx, diff, expected, idxList);

        if (idxList != null) {
            for (Integer idx : idxList) {
                if (idx <= orig_idx) {
                    continue;
                }
                longest = Math.max(longest, longestArithSeqLength(input, map, idx, diff) + 1);
            }
        }

        return longest;
    }
}
__________________________________________________________________________________________________
