__________________________________________________________________________________________________
class FileSystem:

    def __init__(self):
        self.d = dict()
        self.d["/"] = 0

    def create(self, path: str, value: int) -> bool:
        prefix = "/" + "/".join(path[1:].split("/")[:-1])
        if prefix in self.d:
            self.d[path] = value
            return True
        else:
            return False

    def get(self, path: str) -> int:
        return self.d.get(path, -1)


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.create(path,value)
# param_2 = obj.get(path)

__________________________________________________________________________________________________
class wrap:
    def __init__(self, val = None):
        self.val = val 
        self.child = collections.defaultdict(wrap) 
        
class FileSystem:

    def __init__(self):
        self.d = wrap()

    def create(self, path: str, value: int) -> bool:
        ps = path.split('/')[1:]
        p = self.d
        for pt in ps[:-1]:
            if pt in p.child:
                p = p.child[pt]
            else:
                return False
        p.child[ps[-1]] = wrap(value)
        return True

    def get(self, path: str) -> int:
        ps = path.split('/')[1:]
        p = self.d
        for pt in ps:
            if pt in p.child:
                p = p.child[pt]
            else:
                return -1        
        return p.val if p.val is not None else -1


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.create(path,value)
# param_2 = obj.get(path)
__________________________________________________________________________________________________
