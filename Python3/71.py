__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def simplifyPath(self, path: str) -> str:
        path_list = filter(None, path.split('/'))
        ret_list = []
        for i in path_list:
            if i == '..': 
                try:
                    del ret_list[-1]
                except:
                    pass
            elif i == '.': pass
            else : ret_list.append(i)
        
        return ('/'+'/'.join(ret_list))
__________________________________________________________________________________________________
sample 12984 kb submission
class Solution:
    def simplifyPath(self, path: str) -> str:
        path = [p for p in path.split('/') if p]
        stack = []
        for p in path:
            if p == '..':
                if stack:
                    stack.pop()
            elif p != '.':
                stack.append(p)
                
        return "/" + "/".join(stack)                   
__________________________________________________________________________________________________
