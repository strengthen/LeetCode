__________________________________________________________________________________________________
sample 84 ms submission
class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        maps = collections.defaultdict(list)
        for path in paths:
            roots = path.split(' ')
            root, files = roots[0], roots[1:]
            for file in files:
                name, content = file.split('(')
                maps[content].append(root + '/' + name)

        return [x for x in maps.values() if len(x) > 1]
__________________________________________________________________________________________________
sample 21788 kb submission
class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        h = {}
        duplicates = set([])
        for path in paths:
            fs = path.split(" ")
            p = fs[0]
            for fs in fs[1:]:
                c = fs.split("(")[1].split(")")[0]
                f = fs.split("(")[0]
                if c in h:
                    h[c].append(p+"/"+f)
                    duplicates.add(c)
                else:
                    h[c]=[p+"/"+f]
        out=[]
        for c in duplicates:
            out.append(h[c])
        return out
__________________________________________________________________________________________________
