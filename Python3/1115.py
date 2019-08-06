__________________________________________________________________________________________________
sample 52 ms submission
from threading import Lock

class FooBar:
    def __init__(self, n):
        self.n, self.a, self.b = n, Lock(), Lock()
        self.b.acquire()

    def foo(self, pF):
        for i in range(self.n):
            self.a.acquire()
            pF()
            self.b.release()

    def bar(self, pB):
        for i in range(self.n):
            self.b.acquire()
            pB()
            self.a.release()
__________________________________________________________________________________________________
sample 60 ms submission
class FooBar:
    def __init__(self, n):
        self.n = n
        self.foo_num = 0
        self.bar_num = 0

        
    def run(self):
        if hasattr(self, 'printFoo') and hasattr(self, 'printBar'):
            for i in range(self.n):
                self.printFoo()
                self.printBar()
        
        
    def foo(self, printFoo: 'Callable[[], None]') -> None:  
        # printFoo() outputs "foo". Do not change or remove this line.
        self.printFoo = printFoo 
        self.run()


    def bar(self, printBar: 'Callable[[], None]') -> None:
        # printBar() outputs "bar". Do not change or remove this line.
        self.printBar = printBar
        self.run()
__________________________________________________________________________________________________
