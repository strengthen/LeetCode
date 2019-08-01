__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int fib(int N) {
        if (N == 0) {
            return 0;
        }
        if (N == 1) {
            return 1;
        }
        int a = -1, b = 0, c = 1;
        while (N-- >= 2) {
            a = b + c;
            b = c;
            c = a;
        }
        return c;
    }
}
__________________________________________________________________________________________________
0ms
class Solution {
    public int fib(int N) {
        int[] fibSeq = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040};
        return fibSeq[N];
    }
}
__________________________________________________________________________________________________
sample 31492 kb submission
class Solution {
    Map<Integer, Integer> cache = new HashMap<>();
    public int fib(int N) {
        if (cache.containsKey(N))
            return cache.get(N);
        int n;
        if (N<2)
            n=N;
        else
            n = fib(N-1)+fib(N-2);
        cache.put(N,n);
        return n;
    }
}