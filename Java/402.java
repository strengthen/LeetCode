__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String removeKdigits(String num, int k) {
        int len = num.length(), N = len - k;
        if(len <= k)    return "0";
        char[] res = new char[len];
        int idx = 0;
        for(char c: num.toCharArray()) {
            while(idx > 0 && k > 0 && res[idx - 1] > c) {
                idx--;
                k--;
            }
            res[idx++] = c;
        }
        idx = 0;
        while(idx < res.length && res[idx] == '0')  idx++;
        return idx == N? "0": new String(res, idx, N - idx);
    }
}
__________________________________________________________________________________________________
sample 35572 kb submission
class Solution {
    public String removeKdigits(String num, int k) {
        // invalid input
		if (num == null || k <= 0 || k > num.length()) {
			return num;
		}
		// corner case
		if (num.length() == k) {
			return "0";
		}

		Deque<Character> deque = new LinkedList<>();
		for (int i = 0; i < num.length(); ++i) {
			// whenever meet a digit which is less than the previous digit, discard the
			// previous one
			while (k > 0 && !deque.isEmpty() && deque.peekLast() > num.charAt(i)) {
				deque.pollLast();
				--k;
			}
			deque.offer(num.charAt(i));
		}

		// the largest digits are at the tail of the queue, so remove them if k > 0
		while (k > 0) {
			deque.pollLast();
			--k;
		}

		while (!deque.isEmpty() && deque.peek() == '0') {
			deque.poll();
		}
		if (deque.isEmpty()) {
			return "0";
		} else {
			return String.valueOf(deque.stream().map(String::valueOf).collect(Collectors.joining()));
		}
    }
}
__________________________________________________________________________________________________
