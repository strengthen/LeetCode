__________________________________________________________________________________________________
sample 2 ms submission
/*
 * @lc app=leetcode id=726 lang=java
 *  stack + reverse scan 100%(2ms)
 *  dfs 99% (3ms)
 * 
 * [726] Number of Atoms
 */
class Solution {
    //*
    public String countOfAtoms(String formula) {
        Map<String, Integer> map = new HashMap<>();

        char[] f = formula.toCharArray();
        int[] stack = new int[f.length / 3 + 1];
        stack[0] = 1;       // push initial value 1 to stack
        int sIndex = 0;

        for (int i = f.length - 1; i >= 0; --i) {
            int times = 0, pos = 1;
            while (Character.isDigit(f[i])) {
                times += pos * (f[i--] - '0');
                pos *= 10;
            }
            times = times == 0 ? stack[sIndex] : stack[sIndex] * times;
            if (f[i] == ')') {
                stack[++sIndex] = times;    // stack push
            } else if (f[i] == '(') {
                --sIndex;                   // stack pop
            } else {
                String key;
                if (Character.isLowerCase(f[i])) {
                    key = "" + f[i-1] + f[i--];
                } else {
                    key = "" + f[i];
                }
                map.put(key, map.getOrDefault(key, 0) + times);
            }
        }

        List<String> list = new ArrayList<>(map.keySet());
        Collections.sort(list);
        StringBuilder sb = new StringBuilder();
        for (String s : list) {
            sb.append(s);
            int c = map.get(s);
            if (c > 1) sb.append(c);
        }
        return sb.toString();
    }
}

__________________________________________________________________________________________________
sample 36604 kb submission
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;

class Solution {
    public String countOfAtoms(String formula) {
        if (formula == null || formula.length() <= 2) {
            return formula;
        }

        Stack<HashMap<String, Integer>> stack = new Stack<>();
        HashMap<String, Integer> map = new HashMap<>();

        int len = formula.length();
        int i = 0;

        while (i < len) {
            char c = formula.charAt(i);
            i++;

            if (c == '(') {
                stack.push(map);
                map = new HashMap<>();
            } else if (c == ')') {
                int[] cnt = getCount(i, formula);
                i = cnt[0];
                int val = cnt[1];

                HashMap<String, Integer> temp = map;
                map = stack.pop();
                for (Map.Entry<String, Integer> e : temp.entrySet()) {
                    map.put(e.getKey(), map.getOrDefault(e.getKey(), 0) + e.getValue() * val);
                }
            } else {
                int start = i - 1;
                while (i < len && Character.isLowerCase(formula.charAt(i))) {
                    i++;
                }
                String elem = formula.substring(start, i);

                int[] cnt = getCount(i, formula);
                i = cnt[0];
                int val = cnt[1];

                map.put(elem, map.getOrDefault(elem, 0) + val);
            }
        }

        StringBuilder sb = new StringBuilder();
        List<String> elems = new ArrayList<>(map.keySet());
        Collections.sort(elems);

        for (String e : elems) {
            sb.append(e);
            if (map.get(e) > 1) {
                sb.append(map.get(e));
            }
        }

        return sb.toString();
    }

    private int[] getCount(int idx, String formula) {
        int val = 0;
        while (idx < formula.length() && Character.isDigit(formula.charAt(idx))) {
            val = val * 10 + (formula.charAt(idx) - '0');
            idx++;
        }
        if (val == 0) {
            val = 1;
        }
        return new int[] { idx, val };
    }
}
__________________________________________________________________________________________________
