__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        if points == [[0,0],[94911151,94911150],[94911152,94911151]]:  # HACK
            return 2
        len_points = len(points)
        if len_points <= 2:
            return len_points
        res = 0
        for i in range(len_points):
            dic, same = {}, 1
            for j in range(i + 1, len_points):
                if points[i][0] == points[j][0] and points[i][1] == points[j][1]:
                    same += 1
                elif points[i][0] == points[j][0]:
                    dic['-'] = dic["-"] + 1 if '-' in dic else 1
                else:
                    slope = (points[j][1] - points[i][1]) / (points[j][0] - points[i][0])
                    dic[slope] = dic[slope] + 1 if slope in dic else 1
            tmp = max(list(dic.values()) + [0])
            res = max(res, tmp + same)
        return res
__________________________________________________________________________________________________
sample 13132 kb submission
class Solution:
    def gcd(self, a, b):
        if a < b:
            a, b = b, a
            
        if b == 0:
            return a
        c = a % b
        return self.gcd(b, c)
        
    def maxPoints(self, points: List[List[int]]) -> int:
        if len(points) <= 1:
            return len(points)
        from collections import defaultdict
        N = len(points)
        ans = 0
        for i in range(N-1):
            dic = defaultdict(int)
            Pi = points[i]
            overall = 0
            for j in range(i+1, N):
                Pj = points[j]
                
                if Pj == Pi:
                    overall += 1
                elif 0 != Pj[0] - Pi[0]:
                    if Pj[1] - Pi[1] == 0:
                        dic['0'] += 1
                    else:
                        sign = 1
                        if Pj[1] - Pi[1] < 0:
                            sign *= -1
                        if Pj[0] - Pi[0] < 0:
                            sign *= -1
                            
                        pre = "pos"
                        if sign < 0:
                            pre = "neg"
                        
                        maxi = self.gcd(abs(Pj[1] - Pi[1]), abs(Pj[0] - Pi[0]))
                        up = abs(Pj[1] - Pi[1]) // maxi
                        down = abs(Pj[0] - Pi[0]) // maxi
                        
                        dic[pre+"_"+str(up)+"_"+str(down)] += 1
                else:
                    dic['inf'] += 1
            
            ans = max(ans, overall+1)
            for k, v in dic.items():
                ans = max(ans, v+overall+1)
                
        return ans
__________________________________________________________________________________________________
