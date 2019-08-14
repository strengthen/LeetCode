__________________________________________________________________________________________________
sample 108 ms submission
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = {}
        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        trie = self.root
        
        for i in word:
            # add letter if not present as a child
            if i not in trie:
                trie[i] = {}
            
            # enter childe node
            trie = trie[i]
        
        #attach end-of-word indicator
        trie["#"] = "#"
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        trie = self.root
        
        for i in word:
            if i not in trie:
                return False
            trie = trie[i]
        
        if "#" in trie:
            return True
        
        return False
        

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        trie = self.root
        
        for i in prefix:
            if i not in trie:
                return False
            
            trie = trie[i]
        
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
__________________________________________________________________________________________________
sample 21628 kb submission
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.prefix_set = set()
        self.element_set = set()
        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        if word:
            if word not in self.element_set:
                self.element_set.add(word)
                for i in range(len(word)+1):
                    self.prefix_set.add(word[0:i])

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        return word in self.element_set
        

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        return prefix in self.prefix_set
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
__________________________________________________________________________________________________
