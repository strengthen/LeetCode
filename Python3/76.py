__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # Defaultdict is very useful in this problem, though i don't like to import modules
        target_count_dict = collections.defaultdict(int)
        for ch in t:
            target_count_dict[ch] += 1
        remain_missing = len(t)
        start_pos, end_pos = 0, float('inf')
        current_start = 0
        
        # Enumerate function makes current_end indexes from 1
        for current_end, ch in enumerate(s, 1):
            # Whenever we encounter a character, no matter ch in target or not, we minus 1 in count dictionary
            # But, only when ch is in target, we minus the length of remain_missing
            # When the remain_missing is 0, we find a potential solution.
            if target_count_dict[ch] > 0:
                remain_missing -= 1
            target_count_dict[ch] -= 1
            
            if remain_missing == 0:
                # Remove redundant character
                # Try to find the fist position in s that makes target_count_dict value equals 0
                # Which means we can't skip this character in s when returning answer
                while target_count_dict[s[current_start]] < 0:
                    target_count_dict[s[current_start]] += 1
                    current_start += 1
                if current_end - current_start < end_pos - start_pos:
                    start_pos, end_pos = current_start, current_end
                
                # We need to add 1 to current_start, and the correspondence value in dictionary, is because
                # this is the first character of the potential answer. So, in future iteration, when we encounter this character,
                # We can remove this currently first character to try to find a shorter answer.
                target_count_dict[s[current_start]] += 1
                remain_missing += 1
                current_start += 1
        
        return s[start_pos:end_pos] if end_pos != float('inf') else ""
__________________________________________________________________________________________________
sample 13212 kb submission
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        t_map = {}
        for c in t:
            t_map[c] = t_map.get(c, 0) + 1
        
        start = 0
        end = 0
        count = len(t_map)
        size = len(s)
        l = 0
        r = float('inf')
        
        while end < size:
            c = s[end]
            if c in t_map:
                t_map[c] -= 1
                if t_map[c] == 0:
                    count -= 1
            
            end += 1
            
            while count == 0:
                if r - l > end - start:
                    l = start
                    r = end
                    
                tmp = s[start]
                if tmp in t_map:
                    t_map[tmp] += 1
                    if t_map[tmp] > 0:
                        count += 1
                
                start += 1
        
        return '' if r == float('inf') else s[l: r]
__________________________________________________________________________________________________
