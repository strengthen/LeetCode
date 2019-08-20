__________________________________________________________________________________________________
sample 196 ms submission
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        res=[float('-inf'),float('inf')]
        if not nums: return res
        if not nums[0]: return res
        numlst=len(nums)
        dicts=collections.defaultdict(list)
        
        for inx,lst in enumerate(nums):
            for val in lst:
                dicts[val].append(inx)
                
        dicts=sorted(dicts.items(),key=lambda obj: obj[0])
        lendic=len(dicts)
        formed,l=0,0
        cnt=[0 for i in range(numlst)]
        for r in range(lendic):
            for inx in dicts[r][1]:
                cnt[inx]+=1
                if 1==cnt[inx]: formed+=1
            while formed==numlst and l<=r:
                for inx2 in dicts[l][1]:
                    cnt[inx2]-=1
                    if 0==cnt[inx2]:
                        formed-=1
                        if dicts[r][0]-dicts[l][0]<res[1]-res[0]: 
                            res[0]=dicts[l][0]
                            res[1]=dicts[r][0]
                l+=1
        return res
__________________________________________________________________________________________________
sample 17424 kb submission
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        K=len(nums)
        heap=[]
        MAX=10**5
        res=[-MAX, MAX]
        curMax=-MAX
        for i, num in enumerate(nums):
            if len(num):
                heapq.heappush(heap, [num[0], i, 0])
                curMax=max(curMax,num[0])
        
        while len(heap)==K:
            tmp = [heap[0][0], curMax]
            if tmp[1]-tmp[0] < res[1]-res[0]:
                res=tmp
            # cur=num, array, index
            num, array, index = heapq.heappop(heap)
            if index+1<len(nums[array]):
                cur=[nums[array][index+1], array, index+1]
                curMax=max(curMax, cur[0])
                heapq.heappush(heap, cur)
        return res
__________________________________________________________________________________________________
