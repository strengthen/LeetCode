__________________________________________________________________________________________________
sample 104 ms submission
class Solution {
    public int numSimilarGroups(String[] A) {
        int N = A.length;
        int M = A[0].length();
        
        if (N > M * M) {
            return generationMethod(A);
        } else {
            return comparationMethod(A);
        }
    }
    
    // O(N * M * (M - 1) / 2 * M)
    // O(N ^ 2 * M ^ 3)
    private int generationMethod(String[] A) {
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < A.length; i++) {
            map.putIfAbsent(A[i], i);
        }
        
        UF uf = new UF();
        for (int i : map.values()) {
            uf.add(i);
        }
        
        // N words
        for (Map.Entry<String, Integer> e : map.entrySet()) {
            char[] s = e.getKey().toCharArray();
            int i = e.getValue();
            // M * (M - 1) / 2 swaps
            for (int j = 0; j < s.length; j++) {
                for (int k = j + 1; k < s.length; k++) {
                    swap(s, j, k);
                    // build string take O(M)
                    // iteration take O(N) in total
                    Integer t = map.get(new String(s));
                    if (t != null) {
                        uf.union(i, t);
                    }
                    swap(s, j, k);
                }
            }
        }
        
        return uf.count;
    }
    
    // O(N ^ 2 * M)
    private int comparationMethod(String[] A) {
        Set<String> set = new HashSet<>();
        for (String s : A) {
            set.add(s);
        }
        A = set.toArray(new String[0]);
        
        UF uf = new UF();
        
        for (int i = 0; i < A.length; i++) {
            uf.add(i);
        }
        
        for (int i = 0; i < A.length; i++) {
            for (int j = i + 1; j < A.length; j++) {
                if (isSimilar(A[i], A[j])) {
                    uf.union(i, j);
                }
            }
        }
        
        return uf.count;
    }
    
    private void swap(char[] arr, int i, int j) {
        char c = arr[i];
        arr[i] = arr[j];
        arr[j] = c;
    }
    
    private boolean isSimilar(String a, String b) {
        int diffCnt = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                diffCnt++;
            }
            if (diffCnt > 2) {
                return false;
            }
        }
        return diffCnt <= 2;
    }
    
    private class UF {
        private Map<Integer, UFNode> map;
        private int count;
        
        private UF() {
            map = new HashMap<>();
        }
        
        private void add(int val) {
            if (!map.containsKey(val)) {
                map.put(val, new UFNode());
                count++;
            }
        }
        
        private UFNode find(int val) {
            return find(map.get(val));
        }
        
        private UFNode find(UFNode n) {
            if (n.parent != n) {
                n.parent = find(n.parent);
            }
            return n.parent;
        }
        
        private void union(int a, int b) {
            UFNode rootA = find(a);
            UFNode rootB = find(b);
            if (rootA == rootB) {
                return;
            }
            if (rootA.rank < rootB.rank) {
                rootA.parent = rootB;
            } else {
                rootB.parent = rootA;
                if (rootA.rank == rootB.rank) {
                    rootA.rank++;
                }
            }
            count--;
        }
        
        private class UFNode {
            private UFNode parent = this;
            private int rank = 0;
        }

    }
}
__________________________________________________________________________________________________
sample 38288 kb submission
class Solution {
    public int numSimilarGroups(String[] a) {
        int n = a.length;
        int[] parent = new int[n];
        for (int i = 1; i < n; i++) parent[i] = i;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilarString(a[i], a[j])) {
                    int p1 = find(parent, i), p2 = find(parent, j);
                    if (p1 != p2) {
                        parent[p2] = p1;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) res++;
        }
        return res;
    }

    private boolean isSimilarString(String s1, String s2) {
        int diff = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) diff++;
        }
        return (diff == 2 || diff == 0);
    }

    private int find(int[] a, int x) {
        if (a[x] != x) {
            a[x] = find(a, a[x]);
        }
        return a[x];
    }
}
__________________________________________________________________________________________________
