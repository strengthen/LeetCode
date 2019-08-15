__________________________________________________________________________________________________
sample 104 ms submission
from collections import defaultdict
from random import choice
class RandomizedCollection:
    def __init__(self):
        self.lst = []
        self.idx = defaultdict(set)

    def insert(self, val: int) -> bool:
        self.idx[val].add(len(self.lst))
        self.lst.append(val)
        return len(self.idx[val]) == 1

    def remove(self, val: int) -> bool:
        if not self.idx[val]: return False
        remove, last = self.idx[val].pop(), self.lst[-1]
        self.lst[remove] = last
        self.idx[last].add(remove)
        self.idx[last].discard(len(self.lst) - 1)
        self.lst.pop()
        return True

    def getRandom(self) -> int:
        return choice(self.lst)

        


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
__________________________________________________________________________________________________
sample 108 ms submission
import random
from collections import defaultdict
class RandomizedCollection:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.val_pos = defaultdict(set)
        self.pos = []

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        """
        ret = False
        if val not in self.val_pos:
            ret = True
        self.val_pos[val].add(len(self.pos))
        self.pos.append(val)
        return ret
    
    def remove(self, val: int) -> bool:
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        """
        
        if len(self.val_pos.get(val, [])) < 1:
            return False
        #print(self.val_pos[val])
        vi = self.val_pos[val].pop()
        swp = self.pos[-1]
        self.pos[vi] = swp
        self.val_pos[swp].add(vi)
        self.val_pos[swp].discard(len(self.pos)-1)
        self.pos.pop()
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the collection.
        """
        return random.choice(self.pos)


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
__________________________________________________________________________________________________
