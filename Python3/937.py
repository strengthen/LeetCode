__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def f(log):
            iden, rest = log.split(" ", 1)
            
            if rest[0].isalpha():
                return (0, rest, iden)
            return (1, )
        return sorted(logs, key = f)
__________________________________________________________________________________________________
sample 13028 kb submission
def letter_or_digit(li):
    if li[1].isalpha():
        return (0, li[1:], li[0])
    else:
        return (1, 0, 0)
    
    
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letter_logs = sorted(logs, key=lambda x: letter_or_digit(x.split()))
        
        return letter_logs
__________________________________________________________________________________________________
