__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        arr = list(s)
        balance = 0
        for i in range(len(arr)):
            if arr[i] == "(":
                balance += 1
            elif arr[i] == ")":
                if balance == 0:
                    arr[i] = ""
                else:
                    balance -= 1
        i = len(arr) - 1
        while balance > 0 and i >= 0:
            if arr[i] == "(":
                arr[i] = ""
                balance -= 1
            i -= 1
        if balance > 0:
            return ""
        return "".join(arr)
__________________________________________________________________________________________________
sample 72 ms submission
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        counter = 0
        li = list(s)

        for i, char in enumerate(li):
            if char == '(': counter += 1
            elif char == ')':
                if counter > 0: counter -= 1
                else: li[i] = '#'

        for i in range(len(li))[::-1]:
            if counter == 0: break
            if li[i] == '(':
                li[i] = '#'
                counter -= 1

        return ''.join(li).replace('#', '')
__________________________________________________________________________________________________
