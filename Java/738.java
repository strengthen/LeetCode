__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int monotoneIncreasingDigits(int N) {
        int cur = 0, prev = -1, x = 1, ans = 0, mark = 1;
        while (N > 0) {
            cur = N % 10;
            N /= 10;
            if (prev >= 0 && cur > prev) {
                cur--;
                mark = x;
            }
            ans += cur * x;
            prev = cur;
            x *= 10;
        }
        ans = ans / mark;
        while (mark > 1) {
            ans = ans * 10 + 9;
            mark /= 10;
        }
        return ans;
    }
}
__________________________________________________________________________________________________
sample 32020 kb submission
class Solution {
    public int monotoneIncreasingDigits(int N) {
        if(N <= 9)  return N; 
        char[] arr = String.valueOf(N).toCharArray();
        int index = arr.length - 1;
        for(int i = arr.length - 1 ; i >= 1 ; i--){
            if(arr[i - 1] > arr[i]){
                index = i - 1;
                arr[i - 1]--;
            }
        }
        for(int i = index + 1 ; i <= arr.length - 1 ; i++)    arr[i] = '9';
        return Integer.parseInt(String.valueOf(arr));
    }
}
__________________________________________________________________________________________________
