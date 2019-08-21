__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        def dist(code):
            return sum((min(int(c), 10-int(c)) for c in code))
        if "0000" in deadends or target in deadends:
            return -1
        new_codes = set()
        illegal = {*deadends}
        convert = {
            '0': ['9', '1'],
            '1': ['0', '2'],
            '2': ['1', '3'],
            '3': ['2', '4'],
            '4': ['3', '5'],
            '5': ['4', '6'],
            '6': ['5', '7'],
            '7': ['6', '8'],
            '8': ['7', '9'],
            '9': ['8', '0'],
        }
        for i in range(4):
            pre, x, sur = target[:i], convert[target[i]], target[i+1:]
            new_codes.add(pre + x[0] + sur)
            new_codes.add(pre + x[1] + sur)
        moves = new_codes - illegal
        if not moves:
            return -1
        result = dist(target)
        for move in moves:
            if dist(move) < result:
                return result
        return result + 2
__________________________________________________________________________________________________
sample 13740 kb submission
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadends = set(deadends)
        if "0000" in deadends:
            return -1
        deadends.add("0000")
        nbr = {str(i): [str((i - 1) % 10), str((i + 1) % 10)] for i in range(10)}
        start, end = {"0000"}, {target}
        count = 0
        while start and end:
            count += 1
            if len(start) > len(end):
                start, end = end, start
            tmp = set()
            for wheels in start:
                for i in range(4):
                    for num in nbr[wheels[i]]:
                        nxt = wheels[:i] + num + wheels[i + 1:]
                        if nxt in end:
                            return count
                        if nxt not in deadends:
                            deadends.add(nxt)
                            tmp.add(nxt)
            start = tmp
        return -1
__________________________________________________________________________________________________
