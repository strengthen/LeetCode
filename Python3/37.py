__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        one = ord('1')

        seen = [[[0]*9 for _ in range(9)] for _ in range(9)]
        free_cells = []

        row_to_cells = [[] for _ in range(9)]
        col_to_cells = [[] for _ in range(9)]
        sq_to_cells = [[] for _ in range(9)]

        for r in range(9):
            for c in range(9):
                if board[r][c] == '.':
                    row_to_cells[r].append((r, c))
                    col_to_cells[c].append((r, c))
                    sq_to_cells[r // 3 * 3 + c // 3].append((r, c))
                    free_cells.append((r, c))

        neighbors = [[set(row_to_cells[r] + col_to_cells[c] + sq_to_cells[r // 3 * 3 + c // 3]) for c in range(9)] for r
                     in range(9)]

        for r, row in enumerate(board):
            for c, ch in enumerate(row):
                if ch != '.':
                    d = ord(ch) - one
                    for nr, nc in neighbors[r][c]:
                        seen[nr][nc][d] += 1
                else:
                    neighbors[r][c].remove((r, c))

        options = [[sum(v == 0 for v in seen[r][c]) if board[r][c] == '.' else -1 for c in range(9)] for r in
                   range(9)]
        pq = [set() for _ in range(10)]
        for r, c in free_cells:
            pq[options[r][c]].add((r, c))

        def next_cell():
            for i in range(1, 10):
                if pq[i]:
                    return pq[i].pop()

        def put(r, c, d, o):
            board[r][c] = chr(d + one)
            flag = True
            for nr, nc in neighbors[r][c]:
                if board[nr][nc] == '.':
                    prev_opt = options[nr][nc]
                    seen[nr][nc][d] += 1
                    if seen[nr][nc][d] == 1:
                        pq[prev_opt].remove((nr, nc))
                        pq[prev_opt - 1].add((nr, nc))
                        options[nr][nc] -= 1
                        if prev_opt == 1:
                            flag = False
            return flag

        def take(r, c, d, o):
            board[r][c] = '.'
            for nr, nc in neighbors[r][c]:
                if board[nr][nc] == '.':
                    prev_opt = options[nr][nc]
                    seen[nr][nc][d] -= 1
                    if seen[nr][nc][d] == 0:
                        pq[prev_opt].remove((nr, nc))
                        pq[prev_opt + 1].add((nr, nc))
                        options[nr][nc] += 1

        def recurse(i):
            if i == T:
                return True
            r, c = next_cell()
            o = options[r][c]
            for d, s in enumerate(seen[r][c]):
                if s == 0:
                    if put(r, c, d, o) and recurse(i + 1):
                        return True
                    take(r, c, d, o)
            pq[o].add((r, c))
            return False

        T = len(free_cells)
        recurse(0)
__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        def get_related_cells(target_cell):
            target_grid_index = target_cell[0] // 3 * 3 + target_cell[1] // 3
            # Return all related unsolved cells.
            related_cells = []
            for cell in self.unsolved_cells:
                grid_index = cell[0] // 3 * 3 + cell[1] // 3
                if cell[0] == target_cell[0] or cell[1] == target_cell[1] or grid_index == target_grid_index:
                    related_cells.append(cell)
            return related_cells
        
        def get_unique_solution(cell):
            # Return the unique solution if the cell has only one candidate, otherwise return None.
            if len(self.candidates[cell[0]][cell[1]]) == 1:
                return list(self.candidates[cell[0]][cell[1]])[0]
            else:
                return None
        
        def update_candidates(cell, value):
            changed_candidates = []
            
            # Update the cell.
            if cell in self.unsolved_cells:
                self.board[cell[0]][cell[1]] = value
                self.unsolved_cells.remove(cell)
            
            # Disable all other candidates for that cell.
            for digit in self.digits:
                if digit in self.candidates[cell[0]][cell[1]] and digit != value:
                    self.candidates[cell[0]][cell[1]].remove(digit)
                    changed_candidates.append((cell, digit))
            
            # Update all the related candidates.
            related_cells = get_related_cells(cell)
            for other_cell in related_cells:
                if value in self.candidates[other_cell[0]][other_cell[1]]:
                    self.candidates[other_cell[0]][other_cell[1]].remove(value)
                    changed_candidates.append((other_cell, value))
            
            return changed_candidates
        
        def rollback(updated_cells, updated_candidates):
            # Undo updates.
            for cell in updated_cells:
                self.unsolved_cells.add(cell)
                self.board[cell[0]][cell[1]] = "."
            for (cell, value) in updated_candidates:
                self.candidates[cell[0]][cell[1]].add(value)
        
        def _solveSudoku(updated_cells = [], updated_candidates = []):
            unique_candidates = []
            while len(self.unsolved_cells) > 0:
                # Check validality.
                for cell in self.unsolved_cells:
                    if len(self.candidates[cell[0]][cell[1]]) == 0:
                        # No possible solutions.
                        rollback(updated_cells, updated_candidates)
                        return False
                
                list_unsolved_cells = list(self.unsolved_cells)
                for cell in list_unsolved_cells:
                    value = get_unique_solution(cell)
                    if value is not None:
                        # Update all candidates with unique solution.
                        updated_cells.append(cell)
                        delta_updated_candidates = update_candidates(cell, value)
                        updated_candidates += delta_updated_candidates
                if len(self.unsolved_cells) == len(list_unsolved_cells):
                    break
            
            if len(self.unsolved_cells) > 0:
                # Need to form a guess.
                cell = min(self.unsolved_cells, key = lambda cell: len(self.candidates[cell[0]][cell[1]]))
                for value in self.candidates[cell[0]][cell[1]]:
                    initial_updated_cells = [cell]
                    initial_updated_candidates = update_candidates(cell, value)
                    
                    is_solved = _solveSudoku(initial_updated_cells, initial_updated_candidates)
                    if is_solved:
                        return True
                
                # No solution found after iterating all possible candidates of a given cell.
                rollback(updated_cells, updated_candidates)
                return False
            else:
                return True
        
        self.board = board
        self.digits = "123456789"
        self.unsolved_cells = set([(i, j) for i in range(9) for j in range(9) if self.board[i][j] == "."])
        self.candidates = [[set(self.digits) for _ in range(9)] for _ in range(9)]
        
        # Initialize all candidates.
        for i in range(9):
            for j in range(9):
                value = board[i][j]
                if value != ".":
                    update_candidates((i, j), value)
        
        _solveSudoku()
__________________________________________________________________________________________________
