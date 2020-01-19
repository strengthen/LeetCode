__________________________________________________________________________________________________
sample 12 ms submission
class Solution:
    def sumZero(self, n: int) -> List[int]:
        #return ((list(range(-int(n/2), 0))+list(range(1,int(n/2)+1))) if n>1 else [])+([0] if n%2 else [])
        #return range(-int(n/2), int(n/2)+1) if n%2 else list(range(-int(n/2), 0))+list(range(1,int(n/2)+1))
        l = list(range(-int(n/2), int(n/2)+1))
        if n%2 == 0:
            l[int(n/2)]=l[-1]
            l.pop()
        return l
__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def sumZero(self, n: int) -> List[int]:
        zero_list = {i for i in range(int(-n/2), n//2 + 1)}
        if n%2 == 0:
            zero_list.discard(0)
            
        return zero_list
__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def sumZero(self, n: int) -> List[int]:
        arr = []
        pairs = n // 2
        for i in range(0,pairs,1):
            arr.append((i+1) * -1)
            arr.append(i + 1)
        if n % 2:
            arr.append(0)
        return arr