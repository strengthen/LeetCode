__________________________________________________________________________________________________
312ms
class StreamChecker:

    def __init__(self, words: List[str]):
        trie = {}
        
        for word in words:
            subtrie = trie
            
            for char in word[::-1]:
                if char in subtrie:
                    subtrie = subtrie[char]
                else:
                    subtrie[char] = {}
                    subtrie = subtrie[char]
            subtrie['end'] = True
                    
        self.trie = trie
        #print(self.trie)
        self.arr = []
    
    def query(self, letter: str) -> bool:
        arr = self.arr
        arr.append(letter)
        trie = self.trie
        #print(self.arr)
        for i in range(len(arr)-1, -1, -1):
            #print(trie)
            l = arr[i]
            if l not in trie: 
                return False
            else: 
                trie = trie[l]
            #print(trie)
            if 'end' in trie: 
                return True
            
        return False
# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
__________________________________________________________________________________________________
424ms
class StreamChecker:

    def __init__(self, words: List[str]):
        self.words, self.cur, self.pool = set(words), set(), set()
        for word in words:
            for i in range(1, len(word) + 1):
                self.pool.add(word[:i])
        
    def query(self, letter: str) -> bool:
        temp, ans = {letter} if letter in self.pool else set(), True if letter in self.words else False
        for c in self.cur:
            new = c + letter
            if new in self.pool:
                temp.add(new)
            if new in self.words:
                ans = True
        self.cur = temp.copy()
        return ans


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
__________________________________________________________________________________________________
436ms
class TrieNode:
    def __init__(self):
        self.is_word = False
        self.children = collections.defaultdict(TrieNode)
    
class StreamChecker:

    def __init__(self, words: List[str]):
        self.n = 0
        self.root = TrieNode()
        for word in words:
            self.n = max(len(word), self.n)
            cur = self.root
            for ch in word[::-1]:
                cur = cur.children[ch]
            cur.is_word = True
        self.stream = collections.deque([], self.n)

    def query(self, letter: str) -> bool:
        self.stream.append(letter)
        cur = self.root
        for i in range(len(self.stream) - 1, -1, -1):
            ch = self.stream[i]
            cur = cur.children.get(ch, None)
            if cur is None:
                return False
            else:
                if cur.is_word == True:
                    return True
        return False
# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
__________________________________________________________________________________________________

__________________________________________________________________________________________________

__________________________________________________________________________________________________