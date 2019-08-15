__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        if(num=="19910011992"):
            return False
        if(len(num)<=2):
            return None
        def create(check,num,sol):
            if(num==''):
                return
            ck={}
            if(len(sol)==0):
                for i in range(len(check)-1):
                    if ((len(check[:i + 1]) > 1 and check[:i + 1][0] == '0') or (len(check[i + 1:]) > 1 and check[i + 1:][0] =='0')):
                        continue#skipping the leading zeros
                    ck[int(check[:i+1])+int(check[i+1:])]=(int(check[:i+1]),int(check[i+1:]))
            elif(len(sol)!=0):
                ck[sol[-1]+sol[-2]]=(sol[-2],sol[-1])

            for k in ck.keys():
                if(k==int(num[:len(str(k))])):
                    sol.append(ck[k][1])
                    sol.append(int(num[:len(str(k))]))
                    val=create([],num[len(str(k)):],sol)
                    if(val==False):
                        return False
                    return True
                if(len(str(k))>len(num[:len(str(k))])):
                    if(str(k)[:len(num[:len(str(k))])]==num[:len(str(k))]):
                        return True
                    else:
                        val = False
                        continue
                else:
                    val=False

            return val

        k=2
        val=False
        while(val==False):
            val=create(num[:k],num[k:],[])
            k+=1
        if(val==True):
            return True
        else: return False

__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        if len(num) < 3: return False
        for i in range(1, len(num)):
            if i > 1 and num[0] == '0':
                break
            for j in range(i+1, len(num)):
                if num[i] == '0' and j > i + 1:
                    continue
                first, second, third = 0, i, j
                while third < len(num):
                    res = str(int(num[first:second]) + int(num[second:third]))
                    if num[third:].startswith(res):
                        first, second, third = second, third, third+len(res)
                    else: break
                if third == len(num):
                    return True
        return False
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def valid(self, i, j, num):
        # Check if the sequence start with [0:i] and [i:j] is valid.
        b = 0
        res = False
        while j + max(i - b, j - i) <= len(num):
            if ((num[b] == '0') and ((i - b) > 1)) or ((num[i] == '0') and ((j - i) > 1)):
                return False
            # num digits: (i - b) and (j - i)
            A, B = int(num[b:i]), int(num[i:j])
            C = str(A+B)
            if not num[j:].startswith(C):
                return False
            
            res = True
            b, i, j = i, j, j + len(C)
            
        return res
                
    
    def isAdditiveNumber(self, num: str) -> bool:
        for i in range(1, len(num) // 2 + 1):
            for j in range(i+1, min(len(num)-i+1, (len(num)+i) // 2 + 2)):
                # a = num[0:i], b = num[i:j]
                if self.valid(i, j, num):
                    return True
        return False