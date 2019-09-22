__________________________________________________________________________________________________
sample 44 ms submission
from threading import Semaphore
class FizzBuzz:
    def __init__(self, n):
        self.n = n + 1
        self.f = Semaphore(0)
        self.b = Semaphore(0)
        self.fb = Semaphore(0)
        self.num = Semaphore(1)
        self.cur = 1
        
    # printFizz() outputs "fizz"
    def fizz(self, printFizz):
        """
        :type printFizz: method
        :rtype: void
        """
        for i in range(1, self.n):
            if i % 3 == 0 and i % 5:
                self.f.acquire()
                printFizz()
                self.cur += 1
                if self.cur % 5 == 0:
                    self.b.release()
                else:
                    self.num.release()


    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz):
        """
        :type printBuzz: method
        :rtype: void
        """
        for i in range(1, self.n):
            if i % 5 == 0 and i % 3:
                self.b.acquire()
                printBuzz()
                self.cur += 1
                if self.cur % 3 == 0:
                    self.f.release()
                else:
                    self.num.release()      
    	

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz):
        """
        :type printFizzBuzz: method
        :rtype: void
        """
        for i in range(1, self.n):
            if i % 15 == 0:
                self.fb.acquire()
                printFizzBuzz()
                self.cur += 1
                self.num.release()             

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber):
        """
        :type printNumber: method
        :rtype: void
        """
        for i in range(self.n):            
            if i % 5 and i % 3:
                self.num.acquire()
                printNumber(i)
                self.cur += 1
                if self.cur % 15 == 0:
                    self.fb.release()
                elif self.cur % 3 == 0:
                    self.f.release()
                elif self.cur % 5 == 0:
                    self.b.release()
                else:
                    self.num.release()
__________________________________________________________________________________________________
sample 48 ms submission
from threading import Semaphore


class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.fz = Semaphore(0)
        self.bz = Semaphore(0)
        self.fzbz = Semaphore(0)
        self.nums = Semaphore(1)

    # printFizz() outputs "fizz"
    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        for _ in range((self.n // 3) - (self.n // 15)):
            self.fz.acquire()
            printFizz()
            self.nums.release()

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        for _ in range((self.n // 5) - (self.n // 15)):
            self.bz.acquire()
            printBuzz()
            self.nums.release()

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        for _ in range(self.n // 15):
            self.fzbz.acquire()
            printFizzBuzz()
            self.nums.release()

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n + 1):
            self.nums.acquire()
            if i % 15 == 0:
                self.fzbz.release()
            elif i % 5 == 0:
                self.bz.release()
            elif i % 3 == 0:
                self.fz.release()
            else:
                printNumber(i)
                self.nums.release()
__________________________________________________________________________________________________
