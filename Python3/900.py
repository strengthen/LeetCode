__________________________________________________________________________________________________
sample 36 ms submission
class RLEIterator:

    def __init__(self, A):
        self.A = A
        self.pointer = 1
        self.num = 0

    def next(self, n):
        while self.pointer < len(self.A):
            if self.num + n > self.A[self.pointer - 1]:
                n -= self.A[self.pointer - 1] - self.num
                self.num = 0
                self.pointer += 2
            else:
                self.num += n
                return self.A[self.pointer]
        return -1
                
# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(A)
# param_1 = obj.next(n)
__________________________________________________________________________________________________
sample 13432 kb submission
class RLEIterator(object):

    def __init__(self, A):
        """
        :type A: List[int]
        """#510
        i=0 
        # while i<len(A) and A[i]==0:
        #     i+=2
        self.curr=0
        self.i = 0
        self.A=A
        #-1 if i>len(A) else i
        

    def next(self, n):
        """
        :type n: int
        :rtype: int
        """
        #print(self.i,self.curr,n)
        if self.i == -1 or self.i>=len(self.A):
            return -1
        if self.curr+n-1 < self.A[self.i]:
           self.curr+=n
           return self.A[self.i+1]
        else:
            n=n-(self.A[self.i]-self.curr)
            self.i+=2
            self.curr=0
            return self.next(n)


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(A)
# param_1 = obj.next(n)
__________________________________________________________________________________________________
