__________________________________________________________________________________________________
sample 148 ms submission
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        output = []
        minimum = float('inf')
        
        dic = {}
        
        if len(list1)>=len(list2):
            for i in range((len(list2))):
                dic[list2[i]] = i
            
            
            for i in range(len(list1)):
                if list1[i] in dic:
                    if minimum>(i+dic[list1[i]]):
                        minimum = (i+dic[list1[i]])
                        output.clear()
                        output.append(list1[i])
                    elif minimum == (i+dic[list1[i]]):
                        output.append(list1[i])
                
        else:
            dic1 = {}
            for i in range(len(list1)):
                dic[list1[i]] = i
                
            for i in range(len(list2)):
                if list2[i] in dic:
                    if minimum>(i+dic[list2[i]]):
                        minimum = (i+dic[list2[i]])
                        output.clear()
                        output.append(list2[i])
                    elif minimum == (i+dic[list2[i]]):
                        output.append(list2[i])
                    
        return output                    
__________________________________________________________________________________________________
sample 13288 kb submission
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        s = set(list1) & set(list2)
        m = 2000
        ans = []
        min_sum = min([list1.index(r) + list2.index(r) for r in s])
        for r in s:
            tmp = list1.index(r) + list2.index(r)
            if tmp == min_sum:
                ans.append(r)
        return ans
__________________________________________________________________________________________________
