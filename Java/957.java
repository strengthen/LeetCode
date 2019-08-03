__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[] prisonAfterNDays(int[] cells, int N) {
        if(N == 0) {
            return cells;
        }
        N = N % 14;
        N = N == 0 ? 14 : N;
        for(int d = 0; d < N; d++) {
            int left = cells[0];
            for(int i = 1; i < 7; i++) {
                int t = cells[i];
                cells[i] = (left ^ cells[i + 1]) ^ 1;
                left = t;
            }
            cells[0] = 0;
            cells[7] = 0;
        }
        return cells;
    }
}
__________________________________________________________________________________________________
sample 35548 kb submission
class Solution {
    public int[] prisonAfterNDays(int[] cells, int N) {
        List<Integer> result = Arrays.stream(cells).boxed().collect(Collectors.toList());
        Map<List<Integer>, Integer> history = new HashMap<>();
        boolean repeating = false;
        for (int i = 0; i < N; i++) {
            List<Integer> newcells = new ArrayList<>();
            newcells.add(0);
            for (int j = 1; j < cells.length-1; j++) {
                if (result.get(j-1).equals(result.get(j+1))) {
                    newcells.add(1);
                } else {
                    newcells.add(0);
                }
            }
            newcells.add(0);
            if (!repeating) {
                Integer lastSeen = history.get(newcells);
                if (lastSeen != null) {
                    int[] retty = new int[4];
                    int cycle = i - lastSeen;
                    int togo = N - i - 1;
                    retty[0] = lastSeen;
                    retty[1] = cycle;
                    retty[2] = i;
                    retty[3] = togo;
                    i += togo/cycle * cycle;
                    repeating = true;
                    //return retty;
                } else {
                    history.put(newcells, i);
                }

            }
            result = newcells;
        }
        int[] resy = new int[cells.length];
        for (int i = 0; i < result.size(); i++) {
            resy[i] = result.get(i);
        }
        return resy;
    }
}
__________________________________________________________________________________________________
