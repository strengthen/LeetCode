__________________________________________________________________________________________________
sample 32 ms submission
from itertools import combinations
class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        generator = list(map("".join, combinations(characters, combinationLength)))[::-1]
        self.next = generator.pop
        self.hasNext = lambda: bool(generator)


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()
__________________________________________________________________________________________________
sample 36 ms submission
import collections

class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.chars = characters
        self.combLen = combinationLength
        self.queue = collections.deque(itertools.combinations(self.chars, self.combLen))
            
    def next(self) -> str:
        return ''.join(self.queue.popleft())

    def hasNext(self) -> bool:
        return bool(self.queue)


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()
__________________________________________________________________________________________________
sample 40 ms submission
from itertools import combinations
class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.it = combinations(characters, combinationLength)
        self.buffer = "".join(next(self.it)) if characters else None

    def next(self) -> str:
        res = self.buffer 
        try:
            self.buffer = "".join(next(self.it))
        except:
            self.buffer = None
        return res

    def hasNext(self) -> bool:
        return self.buffer is not None
        


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()