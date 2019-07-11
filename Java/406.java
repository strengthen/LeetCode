__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int[][] reconstructQueue(int[][] people) {
        sort(people, 0, people.length - 1);
        ArrayList<int[]> result = new ArrayList();
        for (int[] p : people) {
            result.add(p[1], p);
        }
        return result.toArray(new int[people.length][]);
    }
    
    private void sort(int[][] p, int l, int h) {
        if (l >= h)
            return;
        int i = l, j = h;
        int[] mid = p[l + (h - l) / 2];
        while (i < j) {
            
            while (mid[0] < p[i][0] || (mid[0] == p[i][0] && mid[1] > p[i][1]))
                i ++;
            while (mid[0] > p[j][0] || (mid[0] == p[j][0] && mid[1] < p[j][1]))                     j --;
            if (i <= j) {
                swap(p, i ++, j --);
            }
        }
        sort(p, l, j);
        sort(p, i, h);
    }
    
    private void swap(int[][] p, int i, int j) {
        int[] temp = p[i];
        p[i] = p[j];
        p[j] = temp;
    }
}
__________________________________________________________________________________________________
sample 36612 kb submission
class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (a, b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0];
            } else {
                return b[1] - a[1];
            }
        });

        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < people.length; i++) {
            list.add(i);
        }
        
        int[][] res = new int[people.length][2];
        for (int i = 0; i < people.length; i++) {
            int index = list.get(people[i][1]);
            res[index][0] = people[i][0];
            res[index][1] = people[i][1];
            list.remove(people[i][1]);
        }
        
        return res;
    }
}
__________________________________________________________________________________________________
