__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        from collections import Counter
        
        balls_count = Counter(hand)
        
        return self.dfs(board, balls_count)
        
    def dfs(self, board, balls_count):        
        if not board:
            return 0
        
        answer = float('inf')
        i = 0
        while i < len(board):
            j = i + 1
            while j < len(board) and board[j] == board[i]:
                j += 1
            
            gap = 3 - (j - i)
            if balls_count[board[i]] >= gap:
                if (j - i) > 3:
                    gap = 0
                balls_count[board[i]] -= gap
                a = self.dfs(board[:i] + board[j:], balls_count)
                if a >= 0:
                    answer = min(answer, a + gap)
                balls_count[board[i]] += gap
            i = j
        
        return answer if answer != float('inf') else -1
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        if not board or len(board) == 0:
            return -1
        
        hand_map = {}
        for b in hand:
            hand_map[b] = hand_map.get(b, 0) + 1
            
        min_res = [len(hand) + 1]
        self.dfs(board, hand_map, 0, min_res)
        return min_res[0] if min_res[0] != len(hand) + 1 else -1
    
    def dfs(self, board, hand_map, used, min_res):
        l = len(board)
        if l == 0:
            if min_res[0] > used:
                min_res[0] = used
            return
        
        if len(hand_map) == 0:
            return
        
        for i in range(l):
            ch = board[i]
            if ch not in hand_map:
                continue
            count = hand_map[ch]
            
            if i < l-1 and board[i+1] == ch:
                new_count = count - 1
                if new_count == 0:
                    del hand_map[ch]
                else:
                    hand_map[ch] = new_count
                new_board = self.create_board(board, i-1, i+2)
                self.dfs(new_board, hand_map, used+1, min_res)
                hand_map[ch] = count
                    
            elif count >= 2:
                new_count = count - 2
                if new_count == 0:
                    del hand_map[ch]
                else:
                    hand_map[ch] = new_count
                new_board = self.create_board(board, i-1, i+1)
                self.dfs(new_board, hand_map, used+2, min_res)
                hand_map[ch] = count
                    
    def create_board(self, board, left, right):
        l = len(board)
    
        while left >= 0 and right < l:
            ch = board[left]
            count = 0
            i, j = left, right
            while i >= 0 and board[i] == ch:
                i -= 1
                count += 1
            while j < l and board[j] == ch:
                j += 1
                count += 1
            
            if count < 3:
                break
            else:
                left, right = i, j
                
        return board[:left+1] + board[right:]
__________________________________________________________________________________________________
