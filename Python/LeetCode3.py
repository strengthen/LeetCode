__________________________________________________________________________________________________
52ms
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max = 0;
        len = 0
        hash = {}
        index = -1
        
        for i, c in enumerate(s):
            # 找到重複字母
            if c in hash and hash[c] > index:
                index = hash[c]
                
            hash[c] = i
            
            len = i - index
            
            if len > max:
                max = len
                
        return max

__________________________________________________________________________________________________
56ms
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = start_pos = 0
        seen_chars = {}

        for i in range(len(s)):
            char = s[i]
            if ((char in seen_chars) and (seen_chars[char] >= start_pos)):
                if ((i - start_pos) > max_length):
                    max_length = (i - start_pos)

                start_pos = seen_chars[char] + 1

            seen_chars[char] = i

        if ((len(s) - start_pos) > max_length):
            return (len(s) - start_pos)

        return max_length
__________________________________________________________________________________________________
60ms
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        temp = s[0]
        max_len = 1
        for letter in s[1:]:
            if letter in temp:
                i = temp.find(letter)
                temp = temp [i+1:]
            temp += letter
            if len(temp) > max_len:
                max_len = len(temp)
        return max_len
__________________________________________________________________________________________________
64ms
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        
        d = set()
        left = 0
        right = 0
        max_len = 0
        
        while right < len(s):
            if s[right] not in d:
                d.add(s[right])
                if right - left + 1 > max_len:
                    max_len = right - left + 1
            else:
                while s[left] != s[right]:
                    d.remove(s[left])
                    left += 1
                left += 1
            right += 1
                
        return max_len
__________________________________________________________________________________________________
68ms
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dic = {}
        begin = max_length = 0
        for i,l in enumerate(s):
            if begin > len(s)-max_length:
                break
            elif l in dic:
                length  = i - begin
                if length > max_length:
                    max_length = length
                new_begin  = dic[l] + 1
                for j in s[begin:dic[l]+1]:
                    del dic[j]
                begin = new_begin
                dic[l] = i
            else:
                dic[l] = i
        return max(max_length, len(dic))
__________________________________________________________________________________________________
