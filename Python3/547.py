__________________________________________________________________________________________________
sample 192 ms submission
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        seen = set()
        def visit_all_friends(i: int):
            for friend_idx,is_friend in enumerate(M[i]):
                if is_friend and friend_idx not in seen:
                    seen.add(friend_idx)
                    visit_all_friends(friend_idx)
        count = 0
        for ridx in range(len(M)):
            if ridx not in seen:
                visit_all_friends(ridx)
                count += 1
        return count
__________________________________________________________________________________________________
sample 13172 kb submission
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        def dfs1(r, c, circle):
            frds = [r, c]        
            f_s = {r, c}
            i = 0
            while i < len(frds):
                j = frds[i]
                for k in range(len(M)):
                    if M[j][k] == 1 and k not in f_s:
                        f_s.add(k)
                        frds.append(k)
                i = i + 1
            
            for i in f_s:
                for j in f_s:
                    M[i][j] = circle
            
        circle = 1
        for i in range(len(M)):
            for j in range(len(M[0])):
                if M[i][j] == 1:
                    circle = circle + 1
                    dfs1(i, j, circle)
                    break
        return circle - 1
__________________________________________________________________________________________________
