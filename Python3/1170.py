__________________________________________________________________________________________________
sample 72 ms submission
class Solution:
    def numSmallerByLeadingCount(self, queries: List[str], words: List[str]) -> List[int]:
        
        def score(word):
            return word.count(min(word))

        word_scores = sorted(score(word) for word in words)
        return [len(words) - bisect.bisect(word_scores, score(query)) for query in queries]
__________________________________________________________________________________________________
sample 136 ms submission
class Solution:
    def numSmallerByLeadingCount(self, queries: List[str], words: List[str]) -> List[int]:
        counter, save, ans = collections.defaultdict(int), [[float("inf"), 0]], []
        for w in words:
            cur = collections.Counter(w)
            counter[cur[min(cur, key = lambda x: ord(x))]] += 1
        for c in sorted(counter, reverse = True):
            save.append([c, save[-1][1] + counter[c]])
        save.reverse()
        for q in queries:
            cur = collections.Counter(q)
            ans.append(save[bisect.bisect(save, [cur[min(cur, key = lambda x: ord(x))], float("inf")])][1])
        return ans
__________________________________________________________________________________________________
