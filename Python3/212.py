__________________________________________________________________________________________________
sample 156 ms submission
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        if not board or not board[0]: return False
        R, C = len(board), len(board[0])
        root = {}
        for word in words:
            trie = root
            for c in word:
                if c not in trie:
                    trie[c] = {}
                trie = trie[c]
            trie['#'] = word


        def dfs(i, j, parent):
            c, board[i][j] = board[i][j], '{'
            trie = parent[c]
            if '#' in trie:
                ans.add(trie['#'])
                trie.pop('#')
            
            if i and board[i - 1][j] in trie:
                dfs(i - 1, j, trie)
            if i < R - 1 and board[i + 1][j] in trie:
                dfs(i + 1, j, trie)
            if j and board[i][j - 1] in trie:
                dfs(i, j - 1, trie)
            if j < C - 1 and board[i][j + 1] in trie:
                dfs(i, j + 1, trie)
            board[i][j] = c
            if not trie:
                parent.pop(c)

        ans = set()
        for i in range(R):
            for j in range(C):
                if board[i][j] in root:
                    dfs(i, j, root)

        return list(ans)
__________________________________________________________________________________________________
sample 27988 kb submission
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = lambda: collections.defaultdict(trie)
        root = trie()
        for word in words:
            cur = root
            for letter in word:
                cur = cur[letter]
            cur['END'] = True
        ret = set()
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.dfsHelper(root, i, j, "", ret, board)
        # print(root['a']['a']['a']['b'])
        return list(ret)
    
    def dfsHelper(self, node, i, j, path, ret, board):
        if node.get('END', False) == True:
            ret.add(path)
            node['END'] = False 
        
        if 0 <= i < len(board) and 0 <= j < len(board[0]) and board[i][j] != '#':
            # print(i, j, path)
            letter = board[i][j]
            if letter not in node.keys() or not node.keys():
                return
            
            # node = node[letter]
            board[i][j] = '#'
            self.dfsHelper(node[letter], i+1, j, path + letter, ret, board)
            self.dfsHelper(node[letter], i-1, j, path + letter, ret, board)
            self.dfsHelper(node[letter], i, j+1, path + letter, ret, board)
            self.dfsHelper(node[letter], i, j-1, path + letter, ret, board)
            board[i][j] = letter            
__________________________________________________________________________________________________
