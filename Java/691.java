__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int minStickers(String[] stickers, String target) {
        int[] order = new int[26];
        Arrays.fill(order, -1);
        int len = 0;
        char[] tarr = target.toCharArray();
        for (char ch : tarr)
        {
            if (order[ch - 'a'] == -1)
            {
                order[ch - 'a'] = len++;
            }
        }
        int nStickers = stickers.length;
        int[][] s = new int[nStickers][len];
        boolean[] found = new boolean[len];
        for (int i = 0; i < nStickers; ++i)
        {
            String sticker = stickers[i];
            for (char ch : sticker.toCharArray())
            {
                int idx = order[ch - 'a'];
                if (idx >= 0)
                {
                    ++s[i][idx];
                    found[idx] = true;
                }
            }
        }
        int[] tcnt = new int[len];
        for (char ch : tarr)
        {
            int idx = order[ch - 'a'];
            if (!found[idx])
            {
                return -1;
            }
            ++tcnt[idx];
        }
        boolean[] remove = new boolean[nStickers];
        int lefts = nStickers;
        for (int i = 0; i < nStickers; ++i)
        {
            if (!remove[i])
            {
                for (int j = 0; j < nStickers; ++j)
                {
                    if (!remove[j] && i != j && cover(s[i], s[j]))
                    {
                        remove[j] = true;
                        --lefts;
                    }
                }
            }
        }
        int[][] supd = new int[lefts][len];
        for (int i = 0, idx = 0; i < nStickers; ++i)
        {
            if (!remove[i])
            {
                supd[idx++] = s[i];
            }
        }
        int[] ret = new int[1];
        ret[0] = Integer.MAX_VALUE;
        helper(supd, tcnt, 0, new int[15], 0, tcnt[0], ret);
        return ret[0];
    }
    
    private boolean cover(int[] a, int[] b)
    {
        for (int i = 0; i < a.length; ++i)
        {
            if (a[i] < b[i])
            {
                return false;
            }
        }
        return true;
    }
    
    private void helper(int[][] s, int[] t, int index, int[] path, int count, int remain, int[] ret)
    {
        if (count >= ret[0])
        {
            return;
        }
        while (remain <= 0)
        {
            if (++index >= t.length)
            {
                break;
            }
            remain = t[index];
            for (int i = 0; i < count; ++i)
            {
                remain -= s[path[i]][index];
                if (remain <= 0)
                {
                    break;
                }
            }
        }
        if (index >= t.length)
        {
            ret[0] = Math.min(ret[0], count);
            return;
        }
        for (int i = 0; i < s.length; ++i)
        {
            if (s[i][index] > 0)
            {
                path[count] = i;
                helper(s, t, index, path, count + 1, remain - s[i][index], ret);
            }
        }
    }
}
__________________________________________________________________________________________________
sample 37656 kb submission
class Solution {
    int[][] countMap;
    int cnt = Integer.MAX_VALUE;

    public int minStickers(String[] stickers, String target) {
        if (stickers == null || stickers.length == 0) {
            return -1;
        }
        if (target == null) {
            return -1;
        }
        if (target.length() == 0) {
            return 0;
        }

        int stickersLen = stickers.length;
        countMap = new int[stickersLen][26];

        for (int i = 0; i < stickersLen; i++) {
            String s = stickers[i];
            for (char c : s.toCharArray()) {
                countMap[i][c - 'a']++;
            }
        }

        helper(stickers, target, 0, 0, new int[26]);
        return cnt == Integer.MAX_VALUE ? -1 : cnt;
    }

    private void helper(String[] stickers, String target, int position, int curCnt, int[] availableChars) {
        if (curCnt >= cnt) {
            return;
        }

        if (position == target.length()) {
            cnt = Math.min(cnt, curCnt);
            return;
        }

        char c = target.charAt(position);
        if (availableChars[c - 'a'] > 0) {
            availableChars[c - 'a']--;
            helper(stickers, target, position + 1, curCnt, availableChars);
            availableChars[c - 'a']++;
        } else {
            for (int i = 0; i < stickers.length; i++) {
                if (countMap[i][c - 'a'] == 0) {
                    continue;
                }
                for (int j = 0; j < 26; j++) {
                    availableChars[j] += countMap[i][j];
                }
                helper(stickers, target, position, curCnt + 1, availableChars);
                for (int j = 0; j < 26; j++) {
                    availableChars[j] -= countMap[i][j];
                }
            }
        }
    }
}
__________________________________________________________________________________________________
