__________________________________________________________________________________________________
sample 184 ms submission
class LRUCache:

    def __init__(self, capacity: int):
        self.cache = {}
        self.capacity = capacity
        self.n = 0

    def get(self, key: int) -> int:
        if key in self.cache:
            val = self.cache[key]
            del self.cache[key]
            self.cache[key] = val
            return val
        else:
            return -1
            
        

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            del self.cache[key]
            self.cache[key] = value
        else:
            if self.n < self.capacity:
                self.cache[key] = value
                self.n += 1
            else:
                for k in self.cache:
                    del self.cache[k]
                    break
                self.cache[key] = value
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
__________________________________________________________________________________________________
sample 21384 kb submission
class LRUCache:
    def __init__(self, capacity: int):
        self.dic = {}
        #self.dic = collections.OrderedDict()
        self.remain = capacity

    def get(self, key: int) -> int:
        if key not in self.dic:
            return -1
        v = self.dic.pop(key)
        self.dic[key]=v
        return v
    
    def put(self, key: int, value: int) -> None:
        if key in self.dic:
            self.dic.pop(key)
        else:
            if self.remain>0:
                self.remain-=1
            else:
                List = list(self.dic)
                self.dic.pop(List[0])
        self.dic[key]=value
        #print(self.dic)
            
               
# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
__________________________________________________________________________________________________
