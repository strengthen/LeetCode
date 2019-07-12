__________________________________________________________________________________________________
sample 27 ms submission

class Solution {
    int res = 0;
    Map<Integer, List<Integer>> idxs = new HashMap<>();

    public int numberOfArithmeticSlices(int[] A) {
        buildIdxMap(A);
        for (Map.Entry<Integer, List<Integer>> entry : idxs.entrySet()) {
            int d = entry.getValue().size();
            if ( d> 2)
                res += (1 << d) - 1 - d - d * (d - 1) / 2;
        }
        for (int j = 0; j < A.length-2; j++) {
            for (int i = j+1; i <A.length-1; i++) {
                long delta = (long)A[i] - (long)A[j];

                if (delta == 0)
                    continue;

                dfs(i,A[i]+delta,delta, 0);
            }
        }

        return res;
    }

    private void dfs(int i, long b, long delta, int c) {
        if(c>0)
            res++;

        if (b < Integer.MIN_VALUE || b > Integer.MAX_VALUE )
            return;

        List<Integer> l = idxs.get((int)b);
        if(l == null)
            return;

        int idx = Collections.binarySearch(l,i+1);
        if (idx < 0) idx = -idx - 1;

        for (int j = idx; j < l.size(); j++) {
            dfs(l.get(j),b+delta, delta, c+1);
        }
    }

    private void buildIdxMap(int[] A) {
        for (int i = 0; i < A.length; i++) {
            int a = A[i];
            List<Integer> l = idxs.get(a);
            if (l == null)
                idxs.put(a, l = new ArrayList<>());
            l.add(i);
        }
    }
}
__________________________________________________________________________________________________
sample 40376 kb submission
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        Map<Integer, List<Integer>> indexMap = new HashMap<>();
        for (int i = 0; i < A.length; i++) {
            if (!indexMap.containsKey(A[i])) {
                indexMap.put(A[i], new ArrayList<>());
            }
            indexMap.get(A[i]).add(i);
        }
        int result = 0;
        for (List<Integer> indexes : indexMap.values()) {
            int size = indexes.size();
            if (size >= 3) {
                result += (1 << size) - 1 - size - size * (size - 1) / 2;
            }
        }
        for (int i = 0; i < A.length - 2; i++) {
            for (int j = i + 1; j < A.length; j++) {
                long diff = (long)A[j] - A[i];
                if (diff == 0 || diff < Integer.MIN_VALUE || diff > Integer.MAX_VALUE) {
                    continue;
                }
                result += dfs(A, j, diff, indexMap);
            }
        }
        return result;
        /*
        Map<Integer, Integer>[] deltaMap = new Map[A.length];
        int result = 0;
        for (int i = 0; i < A.length; i++) {
            deltaMap[i] = new HashMap<>();
            for (int j = 0; j < i; j++) {
                long diff = (long)A[i] - A[j];
                if (diff < Integer.MIN_VALUE || diff > Integer.MAX_VALUE) {
                    continue;
                }
                int delta = (int)diff;
                int ci = deltaMap[i].getOrDefault(delta, 0);
                int cj = deltaMap[j].getOrDefault(delta, 0);
                result += cj;
                deltaMap[i].put(delta, ci + cj + 1);
            }
        }
        return result;
        */
    }
    
    private int dfs(int[] A, int index, long delta, Map<Integer, List<Integer>> indexMap) {
        long next = A[index] + delta;
        if (next < Integer.MIN_VALUE || next > Integer.MAX_VALUE || !indexMap.containsKey((int)next)) {
            return 0;
        }
        int result = 0;
        for (int i : indexMap.get((int)next)) {
            if (i <= index) continue;
            result += 1 + dfs(A, i, delta, indexMap);
        }
        return result;
    }
}
__________________________________________________________________________________________________
