__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        myDic = {}
        a = self.dist(p1, p2)
        if a in myDic: myDic[a] += 1
        else: myDic[a] = 1 
        a = self.dist(p1, p3)
        if a in myDic: myDic[a] += 1
        else: myDic[a] = 1 
        a = self.dist(p1, p4)
        if a in myDic: myDic[a] += 1
        else: myDic[a] = 1 
        a = self.dist(p2, p3)
        if a in myDic: myDic[a] += 1
        else: myDic[a] = 1 
        a = self.dist(p2, p4)
        if a in myDic: myDic[a] += 1
        else: myDic[a] = 1 
        a = self.dist(p3, p4)
        if a in myDic: myDic[a] += 1
        else: myDic[a] = 1 

        if len(myDic) != 2: return False
        for k, v in myDic.items():
            if v % 2 != 0: return False
        return True
        #print(myDic)
    
    def dist(self, p1, p2):
        return (p1[0]-p2[0])**2+(p1[1]-p2[1])**2
__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        
        # get all the 
        # distnace between a point = p2 -p1
    
        if(not p1 or not p2 or not p3 or not p4):
            return False
        
        d12 = (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2
        d13 = (p1[0] - p3[0]) ** 2 + (p1[1] - p3[1]) ** 2
        d14 = (p1[0] - p4[0]) ** 2 + (p1[1] - p4[1]) ** 2
        d23 = (p2[0] - p3[0]) ** 2 + (p2[1] - p3[1]) ** 2
        d24 = (p2[0] - p4[0]) ** 2 + (p2[1] - p4[1]) ** 2
        d34 = (p3[0] - p4[0]) ** 2 + (p3[1] - p4[1]) ** 2

        # print(" distances -> ", d12, d13, d14, d23, d24, d34)

        distances = sorted([d12, d13, d14, d23, d24, d34])
        return ((distances[0] == distances[1] == distances[2] == distances[3]) and (distances[3] != distances[4]) and (distances[4] == distances[5]))
    
    
    def validSquare_2(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        pts = [p1, p2, p3, p4]
        distances = []

        for i in range(4):
            for j in range(i+1, 4):
                dist = self.getDistance(pts[i], pts[j])
                distances.append(dist)
                
        distances = sorted(distances)
        return ((distances[0] == distances[1] == distances[2] == distances[3]) and (distances[3] != distances[4]) and (distances[4] == distances[5]))
        
                
    def getDistance(self, p1, p2) -> int:
        return (p1[0] - p2[0])** 2 + (p1[1] - p2[1])**2        
__________________________________________________________________________________________________
