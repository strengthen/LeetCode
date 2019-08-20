__________________________________________________________________________________________________
sample 236 ms submission
class Solution:
    def outerTrees(self, points: List[List[int]]) -> List[List[int]]:
        if len(points)==0:
            return 0
        if len(points)==1:
            return points
        points.sort(key=lambda x: (x[0], x[1]))
        temp=[]
        kik=[]
        pp=0
        while len(points)>0:
            ind=0
            z=points[0]
            while ind+1<=len(points)-1 and points[ind+1][0]==z[0]:
                ind+=1
            if pp==0 and ind!=0:
                kik+=points[1:ind]
                pp=1
            else:
                pp=1
            if ind==len(points)-1:
                kik+=points[1:ind]
            p=[z[0],z[1],points[ind][1]]
            points=points[ind+1:]
            temp.append(p)
        upper=[[temp[0][0],temp[0][2]]]
        lower=[[temp[0][0],temp[0][1]]]
        for x in range(1,len(temp)):
            upc=[temp[x][0],temp[x][2]]
            loc=[temp[x][0],temp[x][1]]
            if len(upper)<2:
                upper.append(upc)
            else:
                ff=0
                while len(upper)>=2 and ff==0:
                    prev=upper[-1]
                    prev2=upper[-2]
                    if prev2[1]==upc[1]:
                        if prev[1]>=upc[1]:
                            ff=1
                            upper.append(upc)
                        else:
                            upper.pop()
                    else:
                        yy=((prev[0]-prev2[0])*upc[1]+prev2[1]*(upc[0]-prev[0]))/(upc[0]-prev2[0])
                        if yy<=prev[1]:
                            ff=1
                            upper.append(upc)
                        else:
                            upper.pop()
                if len(upper)==1 and upc not in upper:
                    upper.append(upc)     
            if len(lower)<2:
                lower.append(loc)
            else:
                ff=0
                while len(lower)>=2 and ff==0:
                    prev=lower[-1]
                    prev2=lower[-2]
                    if prev2[1]==loc[1]:
                        if prev[1]<=loc[1]:
                            ff=1
                            lower.append(loc)
                        else:
                            lower.pop()
                    else:
                        yy=((prev[0]-prev2[0])*loc[1]+prev2[1]*(loc[0]-prev[0]))/(loc[0]-prev2[0])
                        if yy>=prev[1]:
                            ff=1
                            lower.append(loc)
                        else:
                            lower.pop()
                if len(lower)==1 and loc not in lower:
                    lower.append(loc)
        for z in lower:
            if z not in upper:
                upper.append(z)
        if len(kik)>0:
            for z in kik:
                upper.append(z)
        return upper            
__________________________________________________________________________________________________
sample 260 ms submission
class Solution:
    def outerTrees(self, points: List[List[int]]) -> List[List[int]]:
        if len(points)<=4:
            return points
        
        lines = collections.defaultdict(list)
        
        for p in points:
            lines[p[0]].append(p[1])
        res = []
        left = float("inf")
        right= float("-inf")
        xcords = []
        
        for k in lines:            
            lines[k].sort()
            xcords.append(k)
        
        xcords.sort()
        for y in lines[xcords[0]]:
            res.append([xcords[0],y])
        
        if len(xcords)>1:
             for y in lines[xcords[-1]]:
                res.append([xcords[-1],y])
        
        def ccw(o,a1,a2):
            return ((a1[1]-o[1])*(a2[0]-o[0])-(a2[1]-o[1])*(a1[0]-o[0]))>=0
        #upper part
        o = [xcords[0],lines[xcords[0]][-1]]
        s = o
        e = [xcords[-1],lines[xcords[-1]][-1]]
        
        for i in range(1,len(xcords)-1):
            a1 = [xcords[i],lines[xcords[i]][-1]]
            flag = True
            for j in range(i+1,len(xcords)):
                a2 = [xcords[j],lines[xcords[j]][-1]]
            
                if not ccw(o,a1,e) or not ccw(s,a1,a2):
                    flag = False
                    break
            if flag:
                res.append(a1)
                s = a1
        
        #lower part        
        o = [xcords[0],lines[xcords[0]][0]]
        s = o
        e = [xcords[-1],lines[xcords[-1]][0]]
        
        for i in range(1,len(xcords)-1):
            a1 = [xcords[i],lines[xcords[i]][0]]
            flag = True
            for j in range(i+1,len(xcords)):
                a2 = [xcords[j],lines[xcords[j]][0]]
            
                if not ccw(o,e,a1) or not ccw(s,a2,a1):
                    flag = False
                    break
            if flag:
                res.append(a1)
                s = a1
        
        return res    
__________________________________________________________________________________________________
sample 272 ms submission
class Solution:
    def outerTrees(self, points: List[List[int]]) -> List[List[int]]:
        if len(points) < 4: return points
        points.sort()

        def is_convex(o,a,b,in_line):
            # check if vector oa cross product vector ob has positive (or zero) result
            ans = (a[0]-o[0])*(b[1]-o[1]) - (a[1]-o[1])*(b[0]-o[0])
            if ans != 0: in_line[0] = False
            return ans >= 0

        bottom = []
        in_line = [True]
        for x in points:
            while len(bottom) > 1 and not is_convex(bottom[-2],bottom[-1],x,in_line):
                bottom.pop()
            bottom.append(x)
        if in_line[0]: return bottom


        top = []
        for x in reversed(points):
            while len(top) > 1 and not is_convex(top[-2],top[-1],x,in_line):
                top.pop()
            top.append(x)

        # print(is_convex([2,2],[2,0],[1,1]))

        result = bottom[:-1] + top[:-1]
        return result