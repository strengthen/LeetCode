__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def countOfAtoms(self, formula: str) -> str:
        
        stack, atom, dic, count, coeff, c = [], '', collections.defaultdict(int), 0, 1, 0
        
        for i in formula[::-1]:
            if i.isdigit():
                count += int(i) * (10 ** c)
                c += 1
            elif i == ')':
                stack.append(count)
                coeff *= count
                count = c = 0
            elif i == '(':
                coeff //= stack.pop()
                count = c = 0
            elif i.isupper():
                atom += i
                dic[atom[::-1]] += (count or 1) * coeff
                atom = ''
                count = c = 0
            else:
                atom += i
        
        check = []
        for atom in dic:
            check.append((atom, dic[atom]))
        check.sort(key=lambda x:x[0])
        ans = ''
        for atom, count in check:
            ans += atom
            if count > 1:
                ans += str(count)
        return ans
__________________________________________________________________________________________________
sample 13188 kb submission
class Solution:
    def multiply(self,multiplier):
        product=1
        
        for c in multiplier:
            product = product * c
            
        return product
    
    def sort_answer(self,dic):
        output=[]
        
        for key,val in sorted(dic.items()):
            output.append(key)
            if val==1:
                continue
            output.append(str(val))
        
        return ''.join(output)
        
    def countOfAtoms(self, formula: str) -> str:
        from collections import defaultdict
        
        multAr = []
        parentheses=0
        d=defaultdict(int)
        element=None
        elems=[]
        num=None
        
        i=len(formula)-1
        
        while i>=0:
            if formula[i].isdigit():
                if i==len(formula)-1 or num==None:
                    num=formula[i]
                else:
                    num= formula[i]+num
                    
            if formula[i].islower():
                element = formula[i-1:i+1]
                if num==None:
                    d[element]+= self.multiply(multAr)
                else:
                    d[element]+=int(num) * self.multiply(multAr)
                num=None  
                i-=2
                elems.append(element)
                continue
            
            elif formula[i].isupper():
                element=formula[i]
                if num==None:
                    d[element]+= self.multiply(multAr)
                else:
                    d[element]+=int(num) * self.multiply(multAr)
                num=None
                elems.append(element)
                
            elif formula[i]==')':
                multAr.append(int(num))
                num=None
                
            elif formula[i]=='(':
                multAr.pop()
            
            i-=1
            
        return self.sort_answer(d)
__________________________________________________________________________________________________
