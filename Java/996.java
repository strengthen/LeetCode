__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int numSquarefulPerms(int[] a) {
        Arrays.sort(a);
        return perms(a, -1, new int[a.length], 0);
    }
    private int perms(int[] a, int i, int[] used, int visited){
        if(visited == a.length) return 1;
        int count = 0;
        for(int j=0; j < a.length; j++){
            if(used[j] == 1 || (j != 0 && a[j-1] == a[j] && used[j-1] == 0) || (i != -1 && !isPerfSqr(a, i, j)) ) continue;
            used[j] = 1;
            count += perms(a, j, used, visited+1);
            used[j] = 0;
        }
        return count;
    }
    private boolean isPerfSqr(int[] a, int i, int j){
        int sum = a[i]+a[j], sqrt = (int) Math.sqrt(sum);
        return sqrt*sqrt == sum;
    }
}
__________________________________________________________________________________________________
sample 34348 kb submission
class Solution {
    Map<Integer, Set<Integer>> pairs;
    
    public int numSquarefulPerms(int[] A) {
        pairs = new HashMap<>();
        BitSet free = new BitSet(A.length);
        for (int i = 0 ; i < A.length ; i++){
            free.set(i, true);
            for (int j = i ; j < A.length ; j++){
                int k = A[i] + A[j];
                int sqroot = (int) Math.sqrt(k);
                if (k == sqroot * sqroot){
                    pairs.computeIfAbsent(i, (key) -> new HashSet<>()).add(j);
                    pairs.computeIfAbsent(j, (key) -> new HashSet<>()).add(i);
                }
            }
        }
        //System.out.println(pairs.toString());
        
        int res = 0;
        Set<Integer> deduplicate = new HashSet<>();
        for (int i = 0; i < A.length; i++){
            if (deduplicate.add(A[i])){
                BitSet newSet = new BitSet(A.length);
                newSet.or(free);
                newSet.clear(i);
                res += permutation(A, newSet, i);
            }
        }
        return res;
    }
    
    private int permutation(int[] numbers, BitSet free, int last){
        //System.out.println(last);
        if (free.isEmpty()){
            return 1;
        }
        
        int permutation = 0;
        Set<Integer> deduplicate = new HashSet<>();
        for (int nextPossible : pairs.getOrDefault(last, Collections.emptySet())){
            if (free.get(nextPossible) && deduplicate.add(numbers[nextPossible])){
                BitSet copy = (BitSet) free.clone();
                copy.clear(nextPossible);
                permutation += permutation(numbers, copy, nextPossible);
            }
        }
        return permutation;
    }
}
__________________________________________________________________________________________________
