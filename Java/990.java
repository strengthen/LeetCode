__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean equationsPossible(String[] equations) {
        DSU dsu = new DSU(26);
        for(String equation : equations) {
            if(equation.charAt(1) == '=') {
                dsu.union(equation.charAt(0) - 'a', equation.charAt(3) - 'a');
            }
        }
        
        for(String equation : equations) {
            if(equation.charAt(1) == '!') {
                if(dsu.find(equation.charAt(0) - 'a') == dsu.find(equation.charAt(3) - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
}

class DSU {
    private int[] parent;
    
    public DSU(int n) {
        this.parent = new int[n];
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    public int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    public void union(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        parent[rx] = ry;
    }
}
__________________________________________________________________________________________________
sample 34528 kb submission
class Solution {
 private int[] search = new int[26];

  public boolean equationsPossible(String[] equations) {
    Arrays.fill(search, -1);
    Arrays.sort(equations, (o1, o2) -> o2.charAt(1) - o1.charAt(1));
    for (String equation : equations) {
      int left = equation.charAt(0) - 'a';
      int right = equation.charAt(3) - 'a';
      if (equation.charAt(1) == '=') {
        if (left != right) {
          int temp1 = find(left);
          int temp2 = find(right);
          if (temp1 != temp2) {
            search[find(left)] = find(right);
          }
        }
      } else {
        if (left == right || find(left) == find(right)) {
          return false;
        }
      }
    }
    return true;
  }

  public int find(int index) {
    if (search[index] == -1) {
      return index;
    } else {
      int head = find(search[index]);
      search[index] = head;
      return head;
    }
  }
}
__________________________________________________________________________________________________
