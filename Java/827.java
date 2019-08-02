__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    int my, mx;
    int[][] il;
    int[][] grid;
    int[] s;
    
    private int markIsland(int y, int x, int i) {
        if (y < 0 || x < 0 || y >= my || x >= mx || grid[y][x] == 0 || il[y][x] != 0) return 0;
        il[y][x] = i;
        
        return 1 + markIsland(y-1, x, i) + markIsland(y+1, x, i)
                 + markIsland(y, x-1, i) + markIsland(y, x+1, i);
    }
    
    public int largestIsland(int[][] grid) {
        this.grid = grid;
        my = grid.length;
        mx = grid[0].length;
        il = new int[my][mx];
        s = new int[250];
        
        int i = 0;
        for (int y = 0; y < my; y++) {
            for (int x = 0; x < mx; x++) {
                if (il[y][x] == 0 && grid[y][x] == 1) {
                    i++;
                    s[i] = markIsland(y, x, i);
                }
            }
        }
        
        if (i == 0) return 1;
        if (i == 1) return Math.min(s[1]+1, mx*my);
        
        int max = 0;
        
        for (int y = 0; y < my; y++) {
            for (int x = 0; x < mx; x++) {
                if (grid[y][x] == 0) {
                    int a = y > 0 ? il[y-1][x] : 0;
                    int b = y < my-1 ? il[y+1][x] : 0;
                    int c = x > 0 ? il[y][x-1] : 0;
                    int d = x < mx-1 ? il[y][x+1] : 0;
                    
                    int k = s[a];
                    if (b != a) k += s[b];
                    if (c != b && c != a) k += s[c];
                    if (d != c && d != b && d != a) k += s[d];
                    
                    max = Math.max(max, k+1);
                }
            }
        }
        
        return max;
    }
}
__________________________________________________________________________________________________
sample 37816 kb submission
import java.util.*;

public class Solution {

    private final boolean log;

    Solution() {
        this.log = false;
    }

    Solution(boolean log) {
        this.log = log;
    }

    public int largestIsland(int[][] grid) {

        int[] groups = new int[grid.length * grid[0].length];
        Set<Integer> zeros = new HashSet<>();
        assignGroups(grid, groups, zeros);
        mergeGroups(grid, groups);
        Map<Integer, Integer> islandSizes = getGroupSizes(groups);
        Optional<Integer> optional = islandSizes.values().stream().max(Integer::compareTo);
        int maxMergedSize = optional.orElse(0);

        for (Integer zero : zeros) {
            int mergedSize = getMergedSize(grid, groups, islandSizes, zero) + 1;
            if (mergedSize > maxMergedSize) {
                maxMergedSize = mergedSize;
            }
        }

        return maxMergedSize;

    }

    private HashMap<Integer, Integer> getGroupSizes(int[] groups) {
        HashMap<Integer, Integer> groupSizes = new HashMap<>();
        for (int i = 0; i < groups.length; i++) {
            if (groups[i]!=-1) {
                groupSizes.put(groups[i], groupSizes.getOrDefault(groups[i], 0) + 1);
            }
        }
        return groupSizes;
    }

    private void mergeGroups(int[][] grid, int[] groups) {
        boolean groupsChanged = true;
        while (groupsChanged) {
            groupsChanged = false;
            for (int i = 0; i < groups.length; i++) {
                int x = i / grid.length;
                int y = i % grid.length;
                if (groups[i] != -1) {
                    if (x > 0 && groups[i - grid.length] != -1) {
                        if (merge(groups, i, i - grid.length)) {
                            groupsChanged = true;
                        }
                    }
                    if (y > 0 && groups[i - 1] != -1) {
                        if (merge(groups, i, i - 1)) {
                            groupsChanged = true;
                        }
                    }
                    if (x < grid.length - 1 && groups[i + grid.length] != -1) {
                        if (merge(groups, i, i + grid.length)) {
                            groupsChanged = true;
                        }
                    }
                    if (y < grid[x].length - 1 && groups[i + 1] != -1) {
                        if (merge(groups, i, i + 1)) {
                            groupsChanged = true;
                        }
                    }
                }
            }
        }
    }

    private void assignGroups(int[][] grid, int[] islands, Set<Integer> zeros) {
        for (int i = 0; i < islands.length; i++) {
            int x = i / grid.length;
            int y = i % grid.length;
            if (grid[x][y] == 1) {
                islands[i] = i;
            } else {
                islands[i] = -1;
                zeros.add(i);
            }
        }
    }

    private int getMergedSize(int[][] grid, int[] islands, Map<Integer, Integer> islandSizes, Integer zero) {
        int x = zero / grid.length;
        int y = zero % grid.length;
        Set<Integer> islandsToMerge = new HashSet<>();
        if (x > 0) {
            int head = headOf(islands, zero - grid.length);
            islandsToMerge.add(head);
        }
        if (y > 0) {
            int head = headOf(islands, zero - 1);
            islandsToMerge.add(head);
        }
        if (x < grid.length - 1) {
            int head = headOf(islands, zero + grid.length);
            islandsToMerge.add(head);
        }
        if (y < grid[x].length - 1) {
            int head = headOf(islands, zero + 1);
            islandsToMerge.add(head);
        }
        int sizeOfIslands = 0;
        for (Integer island : islandsToMerge) {
            sizeOfIslands += islandSizes.getOrDefault(island, 0);
        }
        return sizeOfIslands;
    }

    private int headOf(int[] islands, int island) {
        int head = island;
        while (head != -1 && head != islands[head]) {
            head = islands[head];
        }
        return head;
    }

    private boolean merge(int[] islands, int a, int b) {
        if (islands[a] == islands[b]) return false;
        int headOfA = headOf(islands, a);
        int headOfB = headOf(islands, b);
        int head = Math.min(headOfA, headOfB);
        islands[a] = head;
        islands[b] = head;
        return true;
    }
}
__________________________________________________________________________________________________
