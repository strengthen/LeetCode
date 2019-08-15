__________________________________________________________________________________________________
sample 96 ms submission
import random
class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.arr = []
        self.d = dict()
        
        

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val in self.d:
            return False
        self.d[val] = len(self.arr)
        self.arr.append(val)     
        return True

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        
        if val not in self.d:
            return False
        
        index = self.d[val]
        
        #swap
        temp = self.arr[-1]
        self.arr[-1] = self.arr[index]
        self.arr[index] = temp        
        
        self.d[temp] = index
        
        self.arr.pop()
        del self.d[val]
        return True
    
    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        return random.choice(self.arr)
# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
__________________________________________________________________________________________________
sample 16688 kb submission
class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.size = 0
        self.array = []
        self.val2i = {}

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val in self.val2i: return False
        if self.size == len(self.array): self.array.append(val)
        else: self.array[self.size] = val
        self.val2i[val] = self.size
        self.size += 1
        #print(self.size)
        return True
        
        

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val not in self.val2i: return False
        #print(self.val2i)
        i = self.val2i[val]
        del self.val2i[val]
        #print(self.val2i)
        if i != self.size - 1:
            self.array[i], self.array[self.size - 1] = self.array[self.size - 1], self.array[i]
            self.val2i[self.array[i]] = i
        self.size -= 1
        
        #print(self.size)
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        #print(self.size)
        i = random.randrange(self.size)
        return self.array[i]
# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
__________________________________________________________________________________________________
