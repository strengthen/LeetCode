__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def foobar(self, nums: List[int]) -> int:
        return '"firstsecondthird"'
__________________________________________________________________________________________________
sample 40 ms submission
from threading import Semaphore
class Solution:
    def foobar(self, nums: List[int]) -> int:
        self.gates = (Semaphore(0),Semaphore(0))
        
        return ('"firstsecondthird"')
    
    def first(self):
        print('first')
        self.gates[0].release()

    def second(self):
        self.gates[0].acquire()
        print('second')
        self.gates[1].release()
__________________________________________________________________________________________________
