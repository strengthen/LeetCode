__________________________________________________________________________________________________
sample 80 ms submission
#https://leetcode.com/problems/word-ladder-ii/discuss/40482/Python-simple-BFS-layer-by-layer
class Solution:
    def findLadders(self, beginWord, endWord, wordList):
        '''wordList = set(wordList)
        res = []
        layer = {}
        layer[beginWord] = [[beginWord]]
        while layer:
            newlayer = collections.defaultdict(list)
            for w in layer:
                if w == endWord: 
                    res.extend(k for k in layer[w])
                else:
                    for i in range(len(w)):
                        for c in 'abcdefghijklmnopqrstuvwxyz':
                            neww = w[:i]+c+w[i+1:]
                            if neww in wordList:
                                newlayer[neww]+=[j+[neww] for j in layer[w]]
            wordList -= set(newlayer.keys())
            layer = newlayer
        return res'''
    

        '''if endWord not in wordList or not endWord or not beginWord:
            return []
        wordList = set(wordList)
        forward, backward = {beginWord}, {endWord}
        direction = 1
        parents = collections.defaultdict(set)
        while forward and backward:
            if len(forward) > len(backward):
                forward, backward = backward, forward
                direction *= -1
            next_forward = set()
            wordList -= forward
            for word in forward:
                for i in range(len(word)):
                    first, second = word[:i], word[i+1:]
                    for ch in string.ascii_lowercase:
                        combined_word = first + ch + second
                        if combined_word in wordList:
                            next_forward.add(combined_word)
                            if direction == 1:
                                parents[combined_word].add(word)
                            else:
                                parents[word].add(combined_word)
            if next_forward & backward:
                self.res = []
                path = [endWord]
                self.dfs(parents, endWord, beginWord,path)
                return self.res
            forward = next_forward
        return []'''
        if endWord not in wordList or not beginWord or not endWord:
            return []
        wordList = set(wordList)
        parents = collections.defaultdict(set)
        forward, backward = {beginWord}, {endWord}
        direction = 1
        while forward and backward:
            if len(forward) > len(backward):
                forward,backward = backward, forward 
                direction *= -1
            nextForward = set()
            wordList -= forward
            for w in forward:
                for i in range(len(w)):
                    first, second = w[:i], w[i+1:]
                    for ch in string.ascii_lowercase:
                        combinedWord = first + ch + second 
                        if combinedWord in wordList:
                            nextForward.add(combinedWord)
                            if direction == 1:
                                parents[combinedWord].add(w)
                            else:
                                parents[w].add(combinedWord)
            forward = nextForward 
            if nextForward & backward:
                self.res = []
                path = [endWord]
                self.dfs(parents, endWord, beginWord, path)
                return self.res 
        return []
    def dfs(self,parents,cur_w,beginWord,path):
        if cur_w == beginWord:
            self.res.append(path[::-1])
            return
        for eword in parents[cur_w]:
            path.append(eword)
            self.dfs(parents,eword,beginWord,path)
            path.pop()
__________________________________________________________________________________________________
sample 14200 kb submission
class Solution:
    def findLadders(self,beginWord, endWord, wordList):
        tree, words, n = collections.defaultdict(set), set(wordList), len(beginWord)
        if endWord not in wordList: return []
        found, bq, eq, nq, rev = False, {beginWord}, {endWord}, set(), False
        while bq and not found:
            words -= set(bq)
            for x in bq:
                for y in [x[:i] + c + x[i + 1:] for i in range(n) for c in 'abcdefghijklmnopqrstuvwxyz']:
                    if y in words:
                        if y in eq: found = True
                        else: nq.add(y)
                        tree[y].add(x) if rev else tree[x].add(y)
            bq, nq = nq, set()
            if len(bq) > len(eq): bq, eq, rev = eq, bq, not rev
        def bt(x): return [[x]] if x == endWord else [[x] + rest for y in tree[x] for rest in bt(y)]
        return bt(beginWord)
__________________________________________________________________________________________________
