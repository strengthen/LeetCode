__________________________________________________________________________________________________
sample 48 ms submission
from collections import deque


class H2O:

    def __init__(self):
        # deque is thread safe
        self.h_queue = deque()
        self.o_queue = deque()

    def _release(self):
        if len(self.h_queue) >= 2 and len(self.o_queue) >= 1:
            self.h_queue.pop()()
            self.h_queue.pop()()
            self.o_queue.pop()()

    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        # releaseHydrogen() outputs "H". Do not change or remove this line.
        self.h_queue.append(releaseHydrogen)
        self._release()

    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        # releaseOxygen() outputs "O". Do not change or remove this line.
        self.o_queue.append(releaseOxygen)
        self._release()
__________________________________________________________________________________________________
sample 52 ms submission

from collections import deque
class H2O:
    def __init__(self):
        self.hy, self.ox = deque(), deque()


    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        
        # releaseHydrogen() outputs "H". Do not change or remove this line.
        self.hy.append(releaseHydrogen)
        self.release()


    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        
        # releaseOxygen() outputs "O". Do not change or remove this line.
        self.ox.append(releaseOxygen)
        self.release()
    
    def release(self):
        if len(self.hy) >= 2 and len(self.ox) >= 1:
            self.hy.popleft()()
            self.hy.popleft()()
            self.ox.popleft()()
__________________________________________________________________________________________________
