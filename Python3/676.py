__________________________________________________________________________________________________
sample 28 ms submission
class TrieNode(object):
    def __init__(self):
        self.children = {}
        self.isword = False
        self.word = None

class Trie(object):
    def __init__(self):
        self.root = TrieNode()
        
    def add(self, w):
        p = self.root
        for c in w:
            if c not in p.children:
                p.children[c] = TrieNode()
            p = p.children[c]
        p.isword = True
        p.word = w
        
    def prefix(self, w):
        p = self.root
        for c in w:
            if c not in p.children:
                return None
            p = p.children[c]
        return p
    
    def search(self, w):
        p = self.root
        
        def dfs(word, nd, cnt):
            if cnt > 1 or not word:   
                return cnt == 1 and nd.isword
            return any([dfs(word[1:], nd.children[c], cnt+(c!=word[0])) for c in nd.children])
        return dfs(w, p, 0)
        
class MagicDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.T = Trie()

    def buildDict(self, dict: List[str]) -> None:
        """
        Build a dictionary through a list of words
        """
        for w in dict:
            self.T.add(w)
            
        
    def search(self, word: str) -> bool:
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        """
        return self.T.search(word)
        
# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)
__________________________________________________________________________________________________
sample 32 ms submission
class MagicDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.buckets = collections.defaultdict(list)
        

    def buildDict(self, dict: List[str]) -> None:
        """
        Build a dictionary through a list of words
        """
        for w in dict:
            self.buckets[len(w)].append(w)

    def search(self, word: str) -> bool:
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        """
        return any(sum(a!=b for a, b in zip(word, candidate))==1
                  for candidate in self.buckets[len(word)])


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)
__________________________________________________________________________________________________
