__________________________________________________________________________________________________
sample 124 ms submission
class Solution:     #eat my ass
    def containVirus(self, grid: List[List[int]]) -> int:   
        N, M, out = len(grid), len(grid[0]), 0
        regions = self.initialize(grid)
        while True:
            threats, max_idx, max_threat, wall_count = self.find_threats(regions, grid)
            if max_threat == 0: break
            out += wall_count
            regions.pop(max_idx)
            threats.pop(max_idx)
            regions, grid = self.advance_virus(regions, grid, threats)
        return out\
    
    def initialize(self, grid):
        regions, seen = [], set()
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == 0 or (row,col) in seen: continue
                stack, new_region = [(row,col)], []
                seen.add((row,col))
                while stack:
                    i0, j0 = stack.pop()
                    edge = False
                    for i, j in [(i0+1,j0),(i0-1,j0),(i0,j0+1),(i0,j0-1)]:
                        if (i,j) not in seen and 0 <= i < len(grid) and 0 <= j < len(grid[0]):
                            if grid[i][j] == 1:
                                seen.add((i,j))
                                stack.append((i,j))
                            else: edge = True
                    if edge: new_region.append((i0,j0))
                regions.append(new_region)
        return regions
    
    def find_threats(self, regions, grid):
        threats, max_idx, max_threat, wall_count = [], 0, 0, 0
        for idx, region in enumerate(regions):
            curr_threat, curr_walls = set(), 0
            for i0, j0 in region:
                for i, j in [(i0+1,j0),(i0-1,j0),(i0,j0+1),(i0,j0-1)]:
                    if 0 <= i < len(grid) and 0 <= j < len(grid[0]) and grid[i][j] == 0:
                        curr_threat.add((i,j))
                        curr_walls += 1
            if len(curr_threat) > max_threat: max_idx, max_threat, wall_count = idx, len(curr_threat), curr_walls
            threats.append(curr_threat)
        return threats, max_idx, max_threat, wall_count

        
    def advance_virus(self, regions, grid, threats):        
        def union_join(i, j):
            leader_i, leader_j = find(i), find(j)
            remap[leader_j] = remap[j] = remap[i] = leader_i
        def find(i):
            while remap[i] != i: i = remap[i]
            return i
        
        remap, converted = {idx: idx for idx in range(len(regions))}, {}
        for idx, region in enumerate(regions):
            updated_region = []
            for i0, j0 in threats[idx]:
                if (i0,j0) in converted: union_join(converted[(i0,j0)], idx)
                else: 
                    converted[(i0,j0)], grid[i0][j0] = idx, 1
                    updated_region.append((i0,j0))
                    for i, j in [(i0+1,j0),(i0-1,j0),(i0,j0+1),(i0,j0-1)]:
                        if (i,j) in converted and converted[(i,j)] != idx: 
                            union_join(converted[(i,j)], idx)   
            regions[idx] = updated_region
            
        new_regions = []
        for i in range(len(regions)):
            if remap[i] != i:
                leader_i = find(i)
                regions[leader_i].extend(regions[i])
            else: new_regions.append(regions[i])

        return new_regions, grid
__________________________________________________________________________________________________
sample 124 ms submission
class Solution:     #eat my ass
    def containVirus(self, grid: List[List[int]]) -> int:   
        N, M, out = len(grid), len(grid[0]), 0
        regions = self.initialize(grid)
        while True:
            threats, max_idx, max_threat, wall_count = self.find_threats(regions, grid)
            if max_threat == 0: break
            out += wall_count
            regions.pop(max_idx)
            threats.pop(max_idx)
            regions, grid = self.advance_virus(regions, grid, threats)
        return out\
    
    def initialize(self, grid):
        regions, seen = [], set()
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == 0 or (row,col) in seen: continue
                stack, new_region = [(row,col)], []
                seen.add((row,col))
                while stack:
                    i0, j0 = stack.pop()
                    edge = False
                    for i, j in [(i0+1,j0),(i0-1,j0),(i0,j0+1),(i0,j0-1)]:
                        if (i,j) not in seen and 0 <= i < len(grid) and 0 <= j < len(grid[0]):
                            if grid[i][j] == 1:
                                seen.add((i,j))
                                stack.append((i,j))
                            else: edge = True
                    if edge: new_region.append((i0,j0))
                regions.append(new_region)
        return regions
    
    def find_threats(self, regions, grid):
        threats, max_idx, max_threat, wall_count = [], 0, 0, 0
        for idx, region in enumerate(regions):
            curr_threat, curr_walls = set(), 0
            for i0, j0 in region:
                for i, j in [(i0+1,j0),(i0-1,j0),(i0,j0+1),(i0,j0-1)]:
                    if 0 <= i < len(grid) and 0 <= j < len(grid[0]) and grid[i][j] == 0:
                        curr_threat.add((i,j))
                        curr_walls += 1
            if len(curr_threat) > max_threat: max_idx, max_threat, wall_count = idx, len(curr_threat), curr_walls
            threats.append(curr_threat)
        return threats, max_idx, max_threat, wall_count

        
    def advance_virus(self, regions, grid, threats):        
        def union_join(i, j):
            leader_i, leader_j = find(i), find(j)
            remap[leader_j] = remap[j] = remap[i] = leader_i
        def find(i):
            while remap[i] != i: i = remap[i]
            return i
        
        remap, converted = {idx: idx for idx in range(len(regions))}, {}
        for idx, region in enumerate(regions):
            updated_region = []
            for i0, j0 in threats[idx]:
                if (i0,j0) in converted: union_join(converted[(i0,j0)], idx)
                else: 
                    converted[(i0,j0)], grid[i0][j0] = idx, 1
                    updated_region.append((i0,j0))
                    for i, j in [(i0+1,j0),(i0-1,j0),(i0,j0+1),(i0,j0-1)]:
                        if (i,j) in converted and converted[(i,j)] != idx: 
                            union_join(converted[(i,j)], idx)   
            regions[idx] = updated_region
            
        new_regions = []
        for i in range(len(regions)):
            if remap[i] != i:
                leader_i = find(i)
                regions[leader_i].extend(regions[i])
            else: new_regions.append(regions[i])

        return new_regions, grid
__________________________________________________________________________________________________
