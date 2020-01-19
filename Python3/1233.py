__________________________________________________________________________________________________
sample 196 ms submission
class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        if not folder:
            return folder
        folder.sort()
        stack=[folder[0]]
        check=folder[0]
        for j in range(1,len(folder)):
            if not folder[j].startswith(check+'/'):
                stack.append(folder[j])
                check=folder[j]
        return stack
__________________________________________________________________________________________________
sample 200 ms submission
class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        res = [folder[0]]
        check = folder[0]
        
        for i in range(1, len(folder)):
            if not folder[i].startswith(check + '/'):
                res.append(folder[i])
                check = folder[i]
                
        return res
__________________________________________________________________________________________________
