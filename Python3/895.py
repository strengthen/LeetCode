__________________________________________________________________________________________________
sample 332 ms submission
class FreqStack:

    def __init__(self):
        self.count = collections.defaultdict(int)
        self.freqTable = collections.defaultdict(list)
        self.maxFreq = 0
        

    def push(self, x: int) -> None:
        self.count[x] += 1
        freq = self.count[x]
        self.freqTable[freq].append(x)
        if freq>self.maxFreq:
            self.maxFreq = freq
        

    def pop(self) -> int:
        out = self.freqTable[self.maxFreq].pop()
        self.count[out] -= 1
        if not self.freqTable[self.maxFreq]:
            self.maxFreq -= 1
        return out

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(x)
# param_2 = obj.pop()
__________________________________________________________________________________________________
sample 19708 kb submission
class FreqStack:
#keep max freq 
#keep dict for frequency
#keep dict for occurance of same frequency
    def __init__(self):
        self.maxFreq = 0
        self.freq = {}
        self.stack = collections.defaultdict(list)
        

    def push(self, x: int) -> None:
        if x in self.freq:
            self.freq[x] += 1
        else:
            self.freq[x] = 1
            
        f = self.freq[x]
        self.maxFreq = max(self.maxFreq,f)
        self.stack[f].append(x)
        

    def pop(self) -> int:
        x = self.stack[self.maxFreq].pop()
        self.freq[x] -=1
        if not self.stack[self.maxFreq]:
            self.maxFreq -=1
        return x

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(x)
# param_2 = obj.pop()
__________________________________________________________________________________________________
