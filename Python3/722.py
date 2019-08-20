__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        res, buffer, block_comment_open = [], '', False
        for line in source:
            i = 0
            while i < len(line):
                char = line[i]
                if char == '/' and (i + 1) < len(line) and line[i + 1] == '/' and not block_comment_open:
                    i = len(line) 
                elif char == '/' and (i + 1) < len(line) and line[i + 1] == '*' and not block_comment_open:
                    block_comment_open = True
                    i += 1
                elif char == '*' and (i + 1) < len(line) and line[i + 1] == '/' and block_comment_open:
                    block_comment_open = False
                    i += 1
                elif not block_comment_open:
                    buffer += char
                i += 1
            if buffer and not block_comment_open:
                res.append(buffer)
                buffer = ''
        return res
__________________________________________________________________________________________________
sample 28 ms submission
class Solution(object):
    def removeComments(self, source):
        """
        :type source: List[str]
        :rtype: List[str]
        """
        res, buff, isOpen = [], "", False
        for comment in source: 
            i, n = 0, len(comment)
            while i < len(comment):
                if i - 1 < n and comment[i: i + 2] == "//" and not isOpen:
                    break
                elif i - 1 < n and comment[i: i + 2] == "/*" and not isOpen:
                    isOpen = True
                    i += 1
                elif i - 1 < n and comment[i: i + 2] == "*/" and isOpen: 
                    isOpen = False
                    i += 1
                elif not isOpen:
                    buff += comment[i]
                i += 1
            if buff and not isOpen:
                res.append(buff)
                buff = ""
        return res
__________________________________________________________________________________________________
