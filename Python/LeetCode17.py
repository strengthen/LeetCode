__________________________________________________________________________________________________
28ms
class Solution:
    def letterCombinationsHelper(self, digits, mappings, char, result):
        if(len(digits) > 0):
            for newChar in mappings[digits[0]]:
                self.letterCombinationsHelper(digits[1:], mappings, char + newChar, result)
        
        else:
            if(len(char) > 0):
                result.append(char)
                                 
        return result
        
    def letterCombinations(self, digits: 'str') -> 'List[str]':
        mappings = {
            "2": ["a", "b", "c"],
            "3": ["d", "e", "f"],
            "4": ["g", "h", "i"],
            "5": ["j", "k", "l"],
            "6": ["m", "n", "o"],
            "7": ["p", "q", "r", "s"],
            "8": ["t", "u", "v"],
            "9": ["w", "x", "y", "z"],
        }
        
        return self.letterCombinationsHelper(digits, mappings, "", [])
__________________________________________________________________________________________________
32ms
class Solution:
    def letterCombinations(self, digits: 'str') -> 'List[str]':
        digit2char={'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs','8':'tuv','9':'wxyz'}
        res = []
        if len(digits) <= 0:
            return res
        res = list(digit2char[digits[0]])
        
        for d in list(digits)[1:]:
            chars = digit2char[d]
            temp = []
            for i in range(len(res)):
                for c in chars:
                    temp.append(res[i]+c)
            res = temp
            
        return res
__________________________________________________________________________________________________
36ms
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        
        
        mapping = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', 
                   '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        if len(digits) == 0:
            return []
        if len(digits) == 1:
            return list(mapping[digits[0]])
        prev = self.letterCombinations(digits[:-1])
        additional = mapping[digits[-1]]
        return [s + c for s in prev for c in additional]
__________________________________________________________________________________________________
12124 kb 
class Solution:
    def letterCombinations(self, digits: 'str') -> 'List[str]':
        digit_map = {
                    '2': 'abc',
                    '3': 'def',
                    '4': 'ghi',
                    '5': 'jkl',
                    '6': 'mno',
                    '7': 'pqrs',
                    '8': 'tuv',
                    '9': 'wxyz',
                    }

        input = str(digits)
        if not input:
            ret = []
            return ret
        else:
            ret = ['']
            for char in input:
                letters = digit_map.get(char)
                ret = [prefix+letter for prefix in ret for letter in letters]
            return ret
__________________________________________________________________________________________________
12156 kb
class Solution:
    def letterCombinations(self, digits):
        
        if not len(digits):
            return []
  
        phones = {"1":"" , "2":"abc" , "3":"def" , "4":"ghi" , "5":"jkl" , "6":"mno" , "7":"pqrs" , "8":"tuv" , "9":"wxyz"}
            
        results = []
        results.append("")

        for digit in digits:
            words = phones[digit]
            temp = []
            for letter in words:
                for val in results:
                    temp.append(val+letter)
            results = temp
        return results
__________________________________________________________________________________________________
