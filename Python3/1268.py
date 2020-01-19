__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        
        ans, res = [], []
        products.sort()
        
        for i in range(len(searchWord)):
            to_search = searchWord[ : i + 1]
            
            k, j = 0, 0
            while j < len(products) and len(ans) != 3:
                if to_search == products[j][ : i + 1]:
                    ans.append(''.join(products[j]))
                j += 1
                
            res.append(ans)
            ans = []
            
            
        return res
 

class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        '''
        time: O(len(searchWord) * lglen(products))
        space: O(len(searchWord))
        '''
        res = [None] * len(searchWord)
        products.sort()
        last_idx = 0
        for i in range(len(searchWord)):
            idx = self.binarySearchFirstAppearance(products, last_idx, searchWord[: i + 1])
            if idx == -1:
                return res
            else:
                last_idx = idx
                res[i] = [products[idx]]
                idx += 1
                while idx < len(products) and products[idx][: i + 1] == searchWord[: i + 1] and len(res[i]) < 3:
                    res[i].append(products[idx])
                    idx += 1
        return res
            
    def binarySearchFirstAppearance(self, lst, start, target):
        '''
        if target exists, return index
        if not exist, return -1
        time: O(lgn)
        space: O(1)
        '''
        n = len(target)
        left, right = start, len(lst) - 1
        mid = left + (right - left) // 2
        while left < right:
            mid = left + (right - left) // 2
            if lst[mid][:n] == target:
                right = mid
            elif lst[mid][:n] > target:
                right = mid - 1
            else:
                left = mid + 1
        if lst[left][:n] == target:
            return left
        else:
            return -1
__________________________________________________________________________________________________
sample 60 ms submission
class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        cur, ans = '', []
        for char in searchWord:
            cur += char
            i = bisect.bisect_left(products, cur)
            ans.append([product for product in products[i : i + 3] if product.startswith(cur)])
        return ans
__________________________________________________________________________________________________
