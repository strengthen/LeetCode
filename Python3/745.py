__________________________________________________________________________________________________
sample 716 ms submission
class WordFilter:
    def __init__(self, words):
        from collections import defaultdict
        self.prefixes = defaultdict(set)
        self.suffixes = defaultdict(set)
        self.weights = {}
        for index, word in enumerate(words):
            prefix, suffix = '', ''
            for char in [''] + list(word):
                prefix += char
                self.prefixes[prefix].add(word)
            for char in [''] + list(word[::-1]):
                suffix += char
                self.suffixes[suffix[::-1]].add(word)
            self.weights[word] = index

    def f(self, prefix, suffix):
        weight = -1
        for word in self.prefixes[prefix] & self.suffixes[suffix]:
            if self.weights[word] > weight:
                weight = self.weights[word]
        return weight
__________________________________________________________________________________________________
sample 748 ms submission
class WordFilter:

    def __init__(self, words: List[str]):
        self.filters = {}
        
        for idx, word in enumerate(words):
            n = len(word)
            prefixes = ['']*(n+1)
            suffixes = ['']*(n+1)
            for i in range(n):
                prefixes[i+1] = prefixes[i] + word[i]
                suffixes[i+1] = word[n-i-1] + suffixes[i]
                
            for pre in prefixes:
                for suf in suffixes:
                    self.filters[pre + '_' + suf] = idx

    def f(self, prefix: str, suffix: str) -> int:
        key = prefix + '_' + suffix
        if key in self.filters: return self.filters[key]
        return -1
        
# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)

__________________________________________________________________________________________________
