__________________________________________________________________________________________________
sample 196 ms submission
class MyHashMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.map = {}

    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        self.map[key] = value

    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        if key not in self.map:
            return -1
        return self.map[key]

    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        if key in self.map:
            del self.map[key]


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
__________________________________________________________________________________________________
sample 15676 kb submission
class MyHashMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.hashmap = {}

    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        self.hashmap[key] = value

    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        if key in self.hashmap.keys():return self.hashmap[key]
        else:return -1
        

    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        if key in self.hashmap.keys():del self.hashmap[key]

            
            
# HASHMAP:
#  step one: giving a dicts : self.hashmap = {}
# step two: giving a loop ..basecontent

# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
__________________________________________________________________________________________________
