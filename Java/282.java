__________________________________________________________________________________________________
sample 6 ms submission
class Solution {
    public List<String> addOperators(String num, int target) {
        List<String> res = new ArrayList();
        if(target <= Integer.MIN_VALUE) return res;
		char[] sc = num.toCharArray();
		char[] path = new char[sc.length * 2];
		int n = 0;
		for (int i = 0; i < sc.length; i++) {
			n = n * 10 + (sc[i] - '0');
			path[i] = sc[i];
			helper(res, sc, i + 1, path, i + 1, 0, n, target);
			if (n == 0)
			    break;
		}
		return res;
    }
    
    public void helper(List<String> res, char[] sc, int si, char[] path, int pi, int total, int cur, int target) {
        if(si == sc.length) {
            if(cur + total == target) {
                res.add(new String(path, 0, pi));
            }
            return;
        }
        int signIndex = pi;
        pi++;
        int n = 0;
        for(int i = si; i < sc.length; i++) {
            n = n * 10 + (sc[i] - '0');
            path[pi] = sc[i];
            pi++;
            path[signIndex] = '+';
            helper(res, sc, i+1, path, pi, total + cur, n, target);
            path[signIndex] = '-';
            helper(res, sc, i+1, path, pi, total + cur, -n, target);
            path[signIndex] = '*';
            helper(res, sc, i+1, path, pi, total, n * cur, target);
            if(n == 0)
                break;
        }
    }  
}
__________________________________________________________________________________________________
sample 34776 kb submission
class Solution {
    // check out [227. Basic Calculator II] first before this one
    //   for how to evaluate +-*/ using just the result and the tail variables.
    // this problem needs to evaluate the expression during backtracking.
    // --------------------------------
    // essentially, there are n digits, and n-1 slots to insert operators.
    // all the digits except the first can choose among:
    // 1) insert nothing. 2) insert one of + - *
    // so a 4^n search space.
    // --------------------------------
    // during the backtracking, all the possible numbers starting at the current
    //   position is tried, and one of + - * will be inserted before the number.
    //   e.g., 123 with i = 0, 1, 12, 123 is tried as the current number.
    // note that the insert nothing choice is actually covered in parent level.
    // regarding the evaluation, since the current number and operator is known,
    //   result and tail can be updated before going to the next level.
    //   thus at i == n, the evaluation result can be checked directly with target.
    // since there are several branches at each position,
    //   using char array with index may be better than StringBuilder,
    //   since StringBuilder is stateful, need to use setLength() to reset.
    // --------------------------------
    // !!! tricky cases: empty num; leading 0 of a number; overflow.
    //
    public List<String> addOperators(String num, int target) { // handles empty num.
        List<String> result = new ArrayList<>();
        char[] nums = num.toCharArray();
        int n = nums.length;
        char[] chars = new char[n + n]; // at most n-1 operators to insert.
        // try every possible number starting from 0.
        // since no operator is allowed for this number,
        //   or only a virtual + is allowed,
        // code it separately here.
        long value = 0; // avoid overflow.
        for(int j = 0, i = 0; i < n; ++i) {
            value = value * 10 + nums[i] - '0';
            chars[j++] = nums[i];
            helper(result, nums, n, i + 1, target, chars, j, 0, value); // virtual +.
            if (value == 0) { // if this is a leading 0, cannot follow any digit.
                break;
            }
        }
        return result;
    }
    
    // result and tail are for evaluating +-*/ on the fly.
    static void helper(List<String> results, char[] nums, int n, int i, long target,
                       char[] chars, int j, long result, long tail) {
        if (i == n) {
            if (result + tail == target) {
                results.add(String.valueOf(chars, 0, j));
            }
        } else {
            long value = 0;
            for(int op = j++, k = i; k < n; ++k) { // save the position for operator.
                value = value * 10 + nums[k] - '0';
                chars[j++] = nums[k]; // keep appending.
                chars[op] = '+';
                helper(results, nums, n, k + 1, target, chars, j, result + tail, value);
                chars[op] = '-';
                helper(results, nums, n, k + 1, target, chars, j, result + tail, -value);
                chars[op] = '*';
                helper(results, nums, n, k + 1, target, chars, j, result, tail * value);
                if (value == 0) { // leading 0
                    break;
                }
            }
        }
    }
}
__________________________________________________________________________________________________
