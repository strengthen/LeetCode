__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def count_indents(self, paths):
        res = []
        for path in paths:
            count = 0
            i = 0
            while i < len(path) and path[i] == '\t':
                count += 1
                i += 1
                
            res.append((count, path[i:]))
            
        return res
    
    def lengthLongestPath(self, s: str) -> int:
        paths = s.split('\n')
        ind_paths = self.count_indents(paths)   # [(0,'dir'), (1, 'tmp') ...]
        
        stack = []
        max_len = 0
        curr_len = 0
        
        for level, name in ind_paths:
            while stack and stack[-1][0] >= level:
                _, name2 = stack.pop()
                curr_len -= len(name2) + 1
                
            stack.append((level, name))
            curr_len += len(name) + 1   # +1 because of the '/' before the name
            if '.' in name:
                max_len = max(max_len, curr_len-1)  # -1 because the first 'dir' doesn't start with '/'
                
        return max_len                
__________________________________________________________________________________________________
sample 13008 kb submission
class Solution:
    def lengthLongestPath(self, input: str) -> int:
        
        
        
        # if "\n" not in input: return 0
        
        # if "\n" not in input: return len(input)
        
        input = input.split("\n")
        level = 0
        w = input.pop(0)
        stack = [len(w)]
        cur_len, max_len = len(w), 0
        is_file = False
        if "." in w:
            max_len = cur_len
            is_file = True
        
        while input:
            # check th level of the nect word
            w = input.pop(0)
            #count = 0
            i = 0
            while i+1 <= len(w) and w[i:i+1] == "\t":
                i += 1
                #count += 1
                
            # update
            lw = len(w[i:])
            for _ in range(level - i+1):
                prev = stack.pop()
                cur_len -= prev + 1 # 1 for "/"

            stack.append(lw)
            cur_len += 1 + lw
            if "." in w[i:]:
                max_len = max(max_len, cur_len) 
                is_file = True
            else:
                is_file = False
            level = i 
            
        return max_len                
__________________________________________________________________________________________________
