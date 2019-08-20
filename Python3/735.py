__________________________________________________________________________________________________
sample 100 ms submission
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        # use a stack for this question
        stk = []
        for a in asteroids:
            # when a is going to right, u would always want to add it to stack
            if a > 0:
                stk.append(a)
            else:
                # when a is going left, if it's the first element, or all other elements are going left, you also just add it to stack
                if not stk or stk[-1] < 0:
                    stk.append(a)
                else: # otherwise, deal with collision
                    while stk and abs(a) >= stk[-1] and stk[-1]>0:
                        if abs(a) == stk[-1]:
                            stk.pop()
                            a = 0
                            continue
                        else:
                            stk.pop()
                    if not stk or stk[-1]<0:
                        if a == 0: continue
                        stk.append(a)
        return stk
__________________________________________________________________________________________________
sample 13812 kb submission
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        for num in asteroids:
            if num>0:
                stack.append(num)
            else:
                while stack and stack[-1]>0 and stack[-1]<abs(num):
                    stack.pop()
                if not stack or stack[-1]<0:
                    stack.append(num)
                elif stack[-1]==-num:
                    stack.pop()
        return stack
__________________________________________________________________________________________________
