__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
/*
The idea is pretty simple. If we look at the order we can find out we just keep adding digit from 0 to 9 to every digit and make it a tree.
Then we visit every node in pre-order. 
       1        2        3    ...
      /\        /\       /\
   10 ...19  20...29  30...39   ....
*/
    public List<Integer> lexicalOrder(int n) {

       List<Integer> res = new ArrayList<>();
        for(int i = 1; i < 10; i++){
          dfs(i, n, res); 
        }
        return res;
    }

    public void dfs(int cur, int n, List<Integer> res){
        if(cur > n)
            return;

        res.add(cur);
        for(int i = 0; i < 10; i++){
            if(10 * cur + i > n)
                return;
            dfs(10 * cur + i, n, res);
        }
    }
}
__________________________________________________________________________________________________
sample 36264 kb submission
class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> list = new ArrayList<>(n);
        int curr = 1;
        for (int i = 1; i <= n; i++) {
            list.add(curr);
            if (curr * 10 <= n) {
                curr *= 10;
            } else if (curr % 10 != 9 && curr + 1 <= n) {
                curr++;
            } else {
                while ((curr / 10) % 10 == 9) {
                    curr /= 10;
                }
                curr = curr / 10 + 1;
            }
        }
        return list;
    }
}
__________________________________________________________________________________________________
