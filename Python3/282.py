__________________________________________________________________________________________________
sample 204 ms submission
class Solution:            
    def addOperators(self, num: str, target: int):
        res=[]
        def aM(index,preOutStr,preSum,preValue):
            if index==len(num):
                if preSum==target:
                    res.append(preOutStr)
                return
            if max(1, abs(preValue)) * (int(num[index:])) < abs(target - preSum):
                return
            for i in range(index,index+1 if num[index]=='0' else len(num)):

                cur=num[index:i+1]
                curValue=int(cur)
                if not preOutStr:
                    aM(i+1,cur,curValue,curValue)
                else:
                    aM(i + 1, preOutStr+'+'+cur, preSum+curValue,curValue)
                    aM(i + 1, preOutStr+'-'+cur, preSum-curValue, -curValue)
                    aM(i + 1, preOutStr+'*'+cur, preSum-preValue+curValue*preValue,curValue*preValue)
        aM(0,'',0,0)
        return res                
__________________________________________________________________________________________________
sample 13688 kb submission
class Solution:
    def addOperators(self, num, target):
        res, self.target = [], target
        for i in range(1,len(num)+1):
            if i == 1 or (i > 1 and num[0] != "0"): # prevent "00*" as a number
                self.dfs(num[i:], num[:i], int(num[:i]), int(num[:i]), res) # this step put first number in the string
        return res

    def dfs(self, num, temp, cur, last, res):
        if not num:
            if cur == self.target:
                res.append(temp)
            return
        for i in range(1, len(num)+1):
            val = num[:i]
            if i == 1 or (i > 1 and num[0] != "0"): # prevent "00*" as a number
                self.dfs(num[i:], temp + "+" + val, cur+int(val), int(val), res)
                self.dfs(num[i:], temp + "-" + val, cur-int(val), -int(val), res)
                self.dfs(num[i:], temp + "*" + val, cur-last+last*int(val), last*int(val), res)
__________________________________________________________________________________________________
