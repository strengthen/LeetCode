__________________________________________________________________________________________________
sample 96 ms submission
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        if not strs:
            return [[]]
        if len(strs) == 1:
            return [strs]
        
        anagrams = {}
        for s in strs:
            key = ''.join(sorted(s))
            val = anagrams.get(key, [])
            val.append(s)
            anagrams[key] = val
        
        res = []
        for entry in anagrams.items():
            res.append(entry[1])
        
        return res
__________________________________________________________________________________________________
sample 15312 kb submission
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        resultsObj = {}
        results = []
        for word in strs:
            sortedWord = ''.join(sorted(word))
            if not sortedWord in resultsObj:
                resultsObj[sortedWord] = [word]
            else:
                resultsObj[sortedWord].append(word)
        for k in resultsObj:
            results.append(resultsObj[k])

        return results
__________________________________________________________________________________________________
