__________________________________________________________________________________________________
sample 692 ms submission
class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        if not tree:
            return 0
        if len(set(tree)) <= 2:
            return len(tree)

        ans = size = cnt = 1
        type1 = type2 = tree[0]

        for fruit in tree[1:]:
            if fruit == type1:
                cnt += 1
            else:
                if fruit != type2:
                    ans = max(ans, size)
                    size = cnt
                type1, type2 = fruit, type1
                cnt = 1

            size += 1

        return max(ans, size)
__________________________________________________________________________________________________
sample 16884 kb submission
class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        dic = {}
        fruits=[]
        fruit_point = {}
        left, res = 0, 0
        if len(tree) < 2:
            return len(tree)
        for i, fruit in enumerate(tree):
            #print (dic, fruits)
            if fruit not in dic:
                dic[fruit] = 1
                fruit_point[fruit] = i
            else:
                dic[fruit] += 1
                fruit_point[fruit] = i
            if len(dic) > 2:
                #print(fruit_point)
                temp = float('inf')
                for key in fruit_point:
                    #print (key, fruit_point[key], temp)
                    if fruit_point[key] < temp:
                        temp = fruit_point[key]
                        first_key = key
                        first_pointer = fruit_point[key]
                #print(first_key, first_pointer)
                del fruit_point[first_key]
                del dic[first_key]
                left = first_pointer + 1
            res = max(res, i - left + 1)
        return res
__________________________________________________________________________________________________
