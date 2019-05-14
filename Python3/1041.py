__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        left_turns = {'w':'s','s':'e','e':'n','n':'w'}
        right_turns = {'w':'n','n':'e','e':'s','s':'w'}
        
        def move(d,pos):
            if d == 'w':
                pos[0]-=1
            elif d == 'n':
                pos[1]+=1
            elif d == 'e':
                pos[0]+=1
            else:
                pos[1]-=1
            return pos
                
        d,pos = 'n',[0,0]
        
        for i in instructions:
            if i == 'G':
                pos = move(d,pos)
            elif i == 'L':
                d = left_turns[d]
            else:
                d = right_turns[d]
        return d != 'n' or pos == [0,0]                
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        visited = set()
        x, y, d = 0, 0, 0
        visited.add("0-0-0")
        for _ in range(4):
            for instruction in instructions:
                if instruction == "G":
                    if d == 0: 
                        y += 1 
                    elif d == 1: 
                        x += 1 
                    elif d == 2: 
                        y -= 1
                    elif d == 3: 
                        x -= 1
                    else:
                        raise Exception("invalid d.")
                elif instruction == "L":
                    d -= 1 
                    d %= 4
                elif instruction == "R":
                    d += 1 
                    d %= 4
                else:
                    raise Exception("invalid instruction.")
            key = "{}-{}-{}".format(x, y, d)
            if key in visited:
                return True
        return False                
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def isRobotBounded(self, i: str) -> bool:
        x = 0
        y = 0
        d = 0
        if "L" not in i and "R" not in i:
            return False
        if "L" not in i:
            return True
        if "R" not in i:
            return True

        iteration = 0
        while iteration < 4:
            for c in i:
                if c == "L":
                    d = (4+d-1)%4
                elif c == 'R':
                    d = (d+1)%4
                else:
                    if d == 0:
                        y +=1
                    elif d == 1:
                        x += 1
                    elif d == 2:
                        y-=1
                    else:
                        x -= 1
            iteration += 1
        return x == 0 and y == 0