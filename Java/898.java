__________________________________________________________________________________________________
sample 146 ms submission
class Solution {
    public int subarrayBitwiseORs(int[] A) {
        int[] cur = new int[33], next = new int[33];
        int n1 = 0;
        HashSet<Integer> set = new HashSet<>();
        for (int a : A) {
            int n2 = 0;
            set.add(next[n2++] = a);
            for (int i = 0; i < n1; i++) {
                int a2 = a | cur[i];
                if (a2 != a) {
                    set.add(next[n2++] = a = a2);
                }
            }
            int[] temp = cur; cur = next; next = temp;
            n1 = n2;
        }
        return set.size();
    }
	
}
__________________________________________________________________________________________________
sample 69664 kb submission
class Solution {
    public int subarrayBitwiseORs(int[] A) {
        Set<Integer> res = new HashSet<>(), cur = new HashSet<>(), next;
        for (int i : A) {
            next = new HashSet<>();
            next.add(i);
            for (int j : cur) {
                next.add(j | i);
            }
            cur = next;
            res.addAll(cur);
        }
        return res.size();
    }
}
__________________________________________________________________________________________________
