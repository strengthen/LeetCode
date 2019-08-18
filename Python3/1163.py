__________________________________________________________________________________________________
Runtime: 200 ms
Memory Usage: 34 MB
class Solution:
    def lastSubstring(self, s: str) -> str:
        count=collections.defaultdict(list)
        for i in range(len(s)):
            count[s[i]].append(i)
        largeC=max(count.keys())
        starts={}
        for pos in count[largeC]:
            starts[pos]=pos+1
		# Initialize all candidates and their pointers
		
        while len(starts)>1:
		# Eliminate till we have only one
            toDel=set()
            nextC=collections.defaultdict(list)
            for start,end in starts.items():
                if end==len(s):
				# Remove if reaching the end
                    toDel.add(start)
                    continue
					
                nextC[s[end]].append(start)
				# Filter by current letter
				
                if end in starts:
                    toDel.add(end)
				# "Swallow" the latter candidate
			
            nextStarts={}
            largeC=max(nextC.keys())
            for start in nextC[largeC]:
                if start not in toDel:
                    nextStarts[start]=starts[start]+1
					# Select what we keep for the next step
            starts=nextStarts.copy()
        for start,end in starts.items():
            return s[start:]
__________________________________________________________________________________________________

__________________________________________________________________________________________________
