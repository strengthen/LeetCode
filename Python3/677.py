__________________________________________________________________________________________________
sample 28 ms submission
class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dc={}
        

    def insert(self, key: str, val: int) -> None:
        self.dc[key]=val

    def sum(self, prefix: str) -> int:
        sum=0
        for key in self.dc:
            if key.startswith(prefix):
                sum+=self.dc[key]
        return sum


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
__________________________________________________________________________________________________
sample 13068 kb submission
import collections
class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.value = 0
class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        

    def insert(self, key: str, val: int) -> None:
        current = self.root
        for c in key:
            current = current.children[c]
        current.value = val

    def sum(self, prefix: str) -> int:
        def searchForValue(root):
            value = root.value
            for c in root.children:
                childNode = root.children.get(c)
                value = value + searchForValue(childNode)
            return value
        current = self.root
        for c in prefix:
            current = current.children.get(c)
            if not current:
                return 0
        return searchForValue(current)
            
        

# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
__________________________________________________________________________________________________
