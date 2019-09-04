__________________________________________________________________________________________________
sample 528 ms submission
class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        s,d,n=[0]*len(puzzles),{},ord('a')
        for w in words:
            t=0
            for c in w: t|=1<<(ord(c)-n)
            d[t]=d.get(t,0)+1
        for i,w in enumerate(puzzles):
            a=[1<<(ord(w[0])-n)]
            for c in w[1:]:
                t=1<<(ord(c)-n)
                a+=[x|t for x in a]
            s[i]=sum([d.get(x,0) for x in a])
        return s
__________________________________________________________________________________________________
sample 556 ms submission
class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        ans, d = [], {}
        for w in words:
            s = set(w)
            if len(s) <= 7:
                mask = 0
                for c in s:
                    mask |= 1 << (ord(c) - ord('a'))
                d[mask] = d.get(mask, 0) + 1
        for p in puzzles:
            all_masks = [1 << (ord(p[0]) - ord('a'))]
            for c in p[1:]:
                cur = 1 << (ord(c) - ord('a'))
                all_masks += [m|cur for m in all_masks]
            ans.append(sum(d.get(m, 0) for m in all_masks))
        return ans
__________________________________________________________________________________________________
sample 608 ms submission
class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        counter = {}
        for w in words:
            s = set(w)
            if len(s) <= 7:
                mask = 0
                for c in s:
                    mask |= 1 << (ord(c) - ord('a'))
                counter.setdefault(mask, 0)
                counter[mask] += 1

        res = []
        for p in puzzles:
            all_masks = [1 << (ord(p[0]) - ord('a'))]
            for c in p[1:]:
                new_masks = list(all_masks)
                nw = 1 << ord(c) - ord('a')
                for i in range(len(new_masks)):
                    new_masks[i] |= nw
                all_masks.extend(new_masks)
            x = sum([counter.get(m, 0) for m in all_masks])
            res.append(x)
            
        return res
