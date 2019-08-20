__________________________________________________________________________________________________
sample 72 ms submission
from  collections import defaultdict
class Solution:
    def removeBoxes(self, boxes):
        if not boxes:
            return 0
        tmp = []
        color, count = boxes[0], 1
        for i in range(1, len(boxes)):
            if color != boxes[i]:
                tmp.append([color, count])
                color, count = boxes[i], 1
            else:
                count += 1
        tmp.append([color, count])

        lst_index = defaultdict(list)
        dt_index = defaultdict(dict)
        for i in range(len(tmp)):
            lst_index[tmp[i][0]].append(i)
            dt_index[tmp[i][0]][i] = len(lst_index[tmp[i][0]]) - 1

        memo = {}
        def helper(i, j, k):
            if i > j:
                return 0
            if i == j:
                return k * k
            if (i, j, k) in memo:
                return memo[i, j, k]
            res = k * k + helper(i, j - 1, tmp[j - 1][1])

            ttt = lst_index[tmp[j][0]]
            iii = dt_index[tmp[j][0]][j] - 1
            while iii >= 0 and ttt[iii] >= i:
                idx = ttt[iii]
                res = max(res, helper(i, idx, tmp[idx][1] + k) + helper(idx + 1, j - 1, tmp[j - 1][1]))
                iii -= 1
            memo[i, j, k] = res
            return res

        return helper(0, len(tmp) - 1, tmp[-1][1])
__________________________________________________________________________________________________
sample 76 ms submission
from  collections import defaultdict


class Solution:
    def removeBoxes(self, boxes):
        if not boxes:
            return 0
        tmp = []
        color, count = boxes[0], 1
        for i in range(1, len(boxes)):
            if color != boxes[i]:
                tmp.append([color, count])
                color, count = boxes[i], 1
            else:
                count += 1
        tmp.append([color, count])

        lst_index = defaultdict(list)
        dt_index = defaultdict(dict)
        for i in range(len(tmp)):
            lst_index[tmp[i][0]].append(i)
            dt_index[tmp[i][0]][i] = len(lst_index[tmp[i][0]]) - 1

        memo = {}
        def helper(i, j, k):
            if i > j:
                return 0
            if i == j:
                return k * k
            if (i, j, k) in memo:
                return memo[i, j, k]
            res = k * k + helper(i, j - 1, tmp[j - 1][1])

            ttt = lst_index[tmp[j][0]]
            iii = dt_index[tmp[j][0]][j] - 1
            while iii >= 0 and ttt[iii] >= i:
                idx = ttt[iii]
                res = max(res, helper(i, idx, tmp[idx][1] + k) + helper(idx + 1, j - 1, tmp[j - 1][1]))
                iii -= 1
            memo[i, j, k] = res
            return res

        return helper(0, len(tmp) - 1, tmp[-1][1])
__________________________________________________________________________________________________
