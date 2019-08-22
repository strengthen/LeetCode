__________________________________________________________________________________________________
sample 24 ms submission
from functools import reduce

class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        def counter(x, y):
            if y == x[-1][0]:
                x[-1] = (y, x[-1][1] + 1)
            else:
                x.append((y, 1))
            return x
        name = reduce(counter, name[1:], [(name[0], 1)])
        typed = reduce(counter, typed[1:], [(typed[0], 1)])
        if len(name) != len(typed):
            return False
        for i in range(len(name)):
            if (name[i][1] > typed[i][1]):
                return False
            
        return True
__________________________________________________________________________________________________
sample 13168 kb submission
class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        i, curP = 0, 0
        if len(set(name)) != len(set(typed)) or min(len(name), len(typed)) == 0:
            return False
        while curP < len(name) and i < len(typed):
             
            if typed[i] == name[curP]:
                i += 1
                curP += 1
                continue
            if typed[i] != name[curP]: 
                if i == 0:
                    return False
                elif typed[i] == typed[i-1]: 
                    i +=1
                    if i >= len(typed):
                        return False
                else:
                    return False
        
        if len(name[curP:]) !=0:
            return False
        for c in typed[i:]:
            if c != typed[i-1]:
                return False
        return True
__________________________________________________________________________________________________
