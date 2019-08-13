__________________________________________________________________________________________________
sample 76 ms submission
import string
import collections

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordList = set(wordList)
        if endWord not in wordList: return 0
        if endWord == beginWord: return 1
        N, level = len(beginWord), 1
        head, tail = {beginWord}, {endWord}
        wordList.remove(endWord)
        chars = set('abcdefghijklmnopqrstuvwxyz')
        while head and tail:
            if len(head) > len(tail):
                head, tail = tail, head
            s = set()
            while head:
                w = head.pop()
                for i in range(N):
                    prefix, suffix = w[:i], w[i+1:]
                    for c in chars:
                        nextWord = prefix + c + suffix
                        if nextWord in tail:
                            return level + 1
                        if nextWord in wordList:
                            s.add(nextWord)
                            wordList.remove(nextWord)
            head = s
            level += 1
        return 0
__________________________________________________________________________________________________
sample 13512 kb submission
from collections import deque

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        
        words = deque([beginWord])
        allowedwords = set(wordList)
        letters = 'abcdefghijklmnopqrstuvwxyz'
        
        level = 1
        while(words):
            levelwidth = len(words)
            for i in range(levelwidth):
                w = words.popleft()
                if w==endWord: return level
            
                newwords = []
                for i in range(len(w)):
                    for c in letters:
                        neww = w[0:i] + c + w[i+1:]
                        if neww in allowedwords:
                            words.append(neww)
                            allowedwords.remove(neww)
                            
            level += 1
        
        return 0
__________________________________________________________________________________________________
