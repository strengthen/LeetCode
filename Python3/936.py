__________________________________________________________________________________________________
sample 76 ms submission
class Solution:
    def movesToStamp(self, stamp: str, target: str) -> List[int]:
        d={}
        m=len(stamp)
        for i in range(m):
            d.setdefault(stamp[i],[])
            d[stamp[i]].append(i)
            
        target=re.split('('+stamp+')',target)
        target=[x for x in target if len(x) > 0]
        
        res=[]
        last=[]
        start=0
        n=len(target)
        for i in range(n):
            x=target[i]
            if (i == 0 and x[0] != stamp[0]) or (i == n-1 and x[-1] != stamp[-1]):
                return []
            if x == stamp:
                last.append(start)
            else:
                l = self.find(x,start,stamp,d,target,i)
                if len(l) == 0:
                    return []
                else:
                    res += l
            start += len(x)
            
        res += last
        return res
    
    def find(self,s,start,stamp,d,target,ti):
        bins=[]
        self.binsearch(s,0,start,stamp,d,bins,target,ti)
        l=[]
        prev=None
        for b in bins:
            if prev is None:
                l.append(b)
                prev=0
            else:
                if l[prev][2] == len(stamp)-1:
                    l.insert(prev,b)
                else:
                    l.insert(prev+1,b)
                    prev += 1
        l=[x[0] for x in l]
        return l
    
    def binsearch(self,s,i,start,stamp,d,bins,target,ti):
        if i == len(s):
            return True
        else:
            if ti == 0 and i == 0:
                choice=[0]
            elif len(bins) > 0 and bins[-1][-1] != len(stamp)-1:
                choice=[0]
            else:
                choice=d[s[i]]
            for j in choice:
                fst=start+i-j
                sec=j
                k=i
                while k < len(s) and j < len(stamp) and s[k] == stamp[j]:
                    trd=j
                    if (ti < len(target)-1 and (trd == len(stamp)-1 or k == len(s)-1 or s[k+1] == stamp[0])) or (ti == len(target)-1 and ((k < len(s)-1 and (trd == len(stamp)-1 or s[k+1] == stamp[0])) or (k == len(s)-1 and trd == len(stamp)-1))):
                        bins.append([fst,sec,trd])
                        if self.binsearch(s,k+1,start,stamp,d,bins,target,ti):
                            return True
                        bins.pop()
                    k += 1
                    j += 1
__________________________________________________________________________________________________
sample 192 ms submission
class Solution:
    def movesToStamp(self, stamp: str, target: str) -> List[int]:
        if not stamp or not target: return []
        self.stamp, self.target = stamp, list(target)
        res, i = [], 0
        while i < len(self.target):
            if self.match(0, i):
                res.append(i)
                i += len(self.stamp)
            else:
                i += 1
        if all([i != '?' for i in self.target]):
            return []
        stamp_char = collections.defaultdict(list)
        for i, c in enumerate(self.stamp):
            stamp_char[c].append(i)
        todo = -1
        while todo == -1 or todo != sum([1 for i in self.target if i != '?']):
            todo = sum([1 for i in self.target if i != '?'])
            for i, c in enumerate(self.target):
                if c != '?':
                    for i_stamp in stamp_char[c]:
                        if self.match(i_stamp, i):
                            res.append(i - i_stamp)
                        # print(f'i_stamp={i_stamp} i={i} target = {self.target}')
        return res[::-1] if all( [i == '?' for i in self.target] ) else []

    def match(self, i_stamp: int, i_target: int) -> bool:
        # print(f'match i_stamp={i_stamp} i_target={i_target} target={self.target}')
        i_s, i_t = i_stamp, i_target
        if i_s < 0 or i_s >= len(self.stamp) or i_t < 0 or i_t >= len(self.target):
            return False
        def check_char(a,b):
            return self.stamp[a] == self.target[b] or self.target[b] == '?'
        def check_direction(direction, a, b):
            while ((direction == -1 and a >= 0 and b >= 0) or (direction == 1 and a < len(self.stamp) and b < len(self.target) ) ) and check_char(a, b):
                a += direction
                b += direction
            # print(f'i_stamp={i_stamp} i_target={i_target} a={a} b={b}')
            return a
        left = check_direction(-1, i_s, i_t) == -1
        if not left:
            return False
        i_s, i_t = i_stamp, i_target
        right = check_direction(1, i_s, i_t) == len(self.stamp)
        # print(f'i_stamp={i_stamp} i_target={i_target} i_s={i_s} i_t={i_t}')
        if not right: 
            return False
        # update self.target to ? on matched indices
        i_t, i_end = i_target - i_stamp, i_target - i_stamp + len(self.stamp)
        while i_t < i_end:
            self.target[i_t] = '?'
            i_t += 1
        return True
__________________________________________________________________________________________________
