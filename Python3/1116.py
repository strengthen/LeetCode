__________________________________________________________________________________________________
sample 44 ms submission
from threading import Lock

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.l_zero = Lock()
        self.l_even = Lock()
        self.l_odd = Lock()
        
        self.l_even.acquire()
        self.l_odd.acquire()
        
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        
        for i in range(self.n):
            self.l_zero.acquire()
            printNumber(0)
            try:
                if i & 1:
                    self.l_even.release()
                else:
                    self.l_odd.release()
            except:
                pass
        
        
        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(2, self.n+1, 2):
            self.l_even.acquire()
            printNumber(i)
            try:
                self.l_zero.release()
            except:
                pass
        
        
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n+1, 2):
            self.l_odd.acquire()
            printNumber(i)
            try:
                self.l_zero.release()
            except:
                pass
__________________________________________________________________________________________________
sample 48 ms submission
from threading import Lock

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.locks = (Lock(), Lock(), Lock())
        self.locks[1].acquire()
        self.locks[2].acquire()
        
    # printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber) -> None:
        for i in range(self.n):
            self.locks[0].acquire()
            printNumber(0)
            self.locks[i%2+1].release()
        
        
    def even(self, printNumber) -> None:
        for i in range(2, self.n+1, 2):
            self.locks[2].acquire()
            printNumber(i)
            self.locks[0].release()
        
    def odd(self, printNumber) -> None:
        for i in range(1, self.n+1, 2):
            self.locks[1].acquire()
            printNumber(i)
            self.locks[0].release()
__________________________________________________________________________________________________
