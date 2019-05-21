__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> row = new ArrayList<>();
        if (numRows == 0) {
            return res;
        }
        row.add(1);
        res.add(new ArrayList<>(row));
        if (numRows == 1) {
            return res;
        }
        for (int i = 2; i <= numRows; i++) {
            List<Integer> newRow = new ArrayList<>();
            newRow.add(1);
            row = res.get(i - 2);
            for (int j = 0; j < row.size() - 1; j++) {
                newRow.add(row.get(j) + row.get(j + 1));
            }
            newRow.add(1);
            res.add(new ArrayList<>(newRow));
        }
        
        return res;
    }
}
__________________________________________________________________________________________________
sample 32400 kb submission
class Solution {
    // 研究小标的关系，基本上都是上面一行的i和i-1的结合
    public List<List<Integer>> generate(int n) {
        List<List<Integer>> lists = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
            list.add(1);
            for (int i = 1; i <= n; i++) {
            lists.add(list);
            List<Integer> newList = new ArrayList<>();
            newList.add(1);
            for (int j = 1; j < list.size(); j++) {
                newList.add(list.get(j - 1) + list.get(j));
            }
            newList.add(1);
            list = newList;
        }

        return lists;
    }
}
__________________________________________________________________________________________________
