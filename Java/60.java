__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public String getPermutation(int n, int k) {
        StringBuilder sb = new StringBuilder();
        boolean[] visit = new boolean[n];
        k = k - 1; //k每次都是余数, 所以从开始就让k-1, 解释见下面
        int factor = 1;
        for(int i = 1; i < n; i++) { //求出第一次循环需要的的全排列
            factor *= i;
        }
        
        for(int i = 0; i < n; i++) {
            int index = k / factor; //index说明从头开始有几个数进行了全排列
            k = k % factor; //剩下的余数, 除了已经挑出来的数, 在剩下的组合中按数序要找第余数+1个数
            for(int j = 0; j < n; j++) {
                if(visit[j] == false) { //visit[i]已经为真的是已经挑出去的数了, 所以每次都要在visit[i]为假的地方判断index, 
                    //visit[i]为假的是有效位
                    if(index == 0) {
                        visit[j] = true;
                        sb.append((char)('0' + j + 1)); //j是目前有效位的坐标, +1就变成了值
                        break;
                    } else {
                        index--; //这个位做完了全排列, 找下一位
                    }
                }
            }
            
            if(i < n - 1) {
                factor = factor / (n - 1 - i); //每次让阶乘缩小到后几个数的全排列
            }
        }
        
        return sb.toString();
    }
}
__________________________________________________________________________________________________
sample 36976 kb submission
/*
The logic is as follows: for n numbers the permutations can be divided to (n-1)! groups, for n-1 numbers can be divided to (n-2)! groups, and so on. Thus k/(n-1)! indicates the index of current number, and k%(n-1)! denotes remaining index for the remaining n-1 numbers.
We keep doing this until n reaches 0, then we get n numbers permutations that is kth.

say n = 4, you have {1, 2, 3, 4, 5}

If you were to list out all the permutations you have

1 + (permutations of 2, 3, 4, 5) => 1 + (4! permuations), total 24 permuations <- k = 126, k = k % 120 = 6, (k-1)%24 = 5%24 = 5, 0-based

2 + (permutations of 1, 3, 4, 5) => 2 + (4! permuations)

3 + (permutations of 1, 2, 4, 5) => 3 + (4! permuations)

4 + (permutations of 1, 2, 3, 5) => 4 + (4! permuations) , total 96 permuations

5 + (permutations of 1, 2, 3, 4) => 5 + (4! permuations) , total 120 permuations <- k = 100

for example, consider the k = 100th permutation of 5 numbers, 5! = 120, so the 100th permutaion will be equal to the 5+ (4! permuations). And K = 140th, so the permuation will be equal to the 1+()and we could easily fit the correct number to a given position based on how many permutations are left.

*/
//time O(n), space O(n)
class Solution {
    public String getPermutation(int n, int k) {
        if(n <= 0 || k <= 0) return "";
        
        int[] factorial = new int[n + 1];
        factorial[0] = 1;
        List<Integer> nums = new LinkedList<Integer>();
        // create an array of factorial lookup,  factorial[] = {1, 1, 2, 6, 24, ... n!}
        // create a list of numbers to get indices, numbers = {1, 2, 3, 4}
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
            nums.add(i);
        }
        
        StringBuilder result = new StringBuilder(n);
        int times;
        int reminder;
        if (k > factorial[n]) {
            k %= factorial[n];
        }
        k--;// k = k-1 since 0 based
        
        for (int i = n; i >=1 ; i--) {
            times = k/factorial[i - 1];
            //result = result.append(nums.remove(times));
            result.append(nums.remove(times));
            k %= factorial[i - 1];
        }
        return result.toString();
    }
}
__________________________________________________________________________________________________
