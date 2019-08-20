__________________________________________________________________________________________________
sample 24 ms submission
import itertools

class Solution:
    def flipLights(self, n: int, m: int) -> int:
        """
        seen = set()
        for cand in itertools.product((0, 1), repeat=4):
            A = []
            for i in range(min(n, 3)):
                light = 1
                light ^= cand[0]
                light ^= cand[1] and i % 2
                light ^= cand[2] and i % 2 == 0
                light ^= cand[3] and i % 3 == 0
                A.append(light)
            seen.add(tuple(A))

        return len(seen)
        """

        n = min(n, 3)
        if m == 0: return 1
        if m == 1: return [2, 3, 4][n-1]
        if m == 2: return [2, 4, 7][n-1]
        return [2, 4, 8][n-1]

__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def flipLights(self, n: int, m: int) -> int:
        #执行m个未知操作
        #一共n灯，返回可能的状态数
        # 1, 3, 7...
        # 初始为turned on...
        #考虑将每个灯作为一个二进制数，
        #由于even, odd number的公约数为6，所以1....7..... 13....是循环的
        # 因此最多有2**6个不同状态，即64个
        # m个操作可以造成多少不同值
        # 而在前6个中，不同m可能造成的结果为：
        # 111111
        # m=1,  000000, 101010, 010101, 011011
        # m=2, 可以在m=1基础上执行，010101, 
        # 其中2和6，以及3和5总是一致的，因此总的自由灯，一共只有4个，即2**4=16种解
        # 考虑获得不同组合所需的操作。。。，即前4个灯的不同值
        # 0000,m=1,m=2,m=3,...
        # 0001,m=2
        # 0010, 0011, 0100, 0101, 0110, 0111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111 m=0，或m=2
        # 
        
        
        #m=1总是使得其中一半为亮，一半为灭
        # m=2则可以使得全亮，全灭
        #考虑dp来处理m<6
        
        
        #m=1为 0000
        
#        cache={}
#        
#        
#        def op1(list_):
#            lis=list(list_)
#            for i in range(len(lis)):
#                lis[i]=1-lis[i]
#            return tuple(lis)
#        def op2(list_):
#            lis=list(list_)
#            for i in range(len(lis)):
#                if (i+1)%2==0:
#                    lis[i]=1-lis[i]
#            return tuple(lis)
#        def op3(list_):
#            lis=list(list_)
#            for i in range(len(lis)):
#                if (i+1)%2==1:
#                    lis[i]=1-lis[i]
#            return tuple(lis)
#        def op4(list_):
#            lis=list(list_)
#            for i in range(len(lis)):
#                if (i+1)%3==1:
#                    lis[i]=1-lis[i]
#            return tuple(lis)
#        
#        cache[4,0]={(1,1,1,1)}
#        cache[3,0]={(1,1,1)}
#        cache[2,0]={(1,1)}
#        cache[1,0]={(1,)}
#        n=2
#        m=10
#        #当m变大时，则有：
#        i=1
#        while i<=m:
#            newones=set()
#            for lis in cache[n,i-1]:
#                newones.add(op1(lis))
#                newones.add(op2(lis))
#                newones.add(op3(lis))
#                newones.add(op4(lis))
#            cache[n,i]=newones
#            i+=1 
#        print(cache)
#        print({k:len(v) for k,v in cache.items()})
#        

        
        
        #统计获得，在n=3, m=1, 有4种，m=2有7种，而m=3开始是8
        # n=4，m=1, 4种, m=2有7种，之后是8种
        # n=2, m=1, 3种，m-2为4种，之后是4种
        # n=1, m=1, 1种
        
        if n>=3:
            m=min(m,3)
            return [1,4,7,8][m]       #m=1则为1
        if n==2:
            m=min(m,2)
            return [1,3,4][m]
        if n==1:
            m=min(m,1)
            return [1,2][m]
        #只需要考虑n种情况下，可能有的结果，其中
__________________________________________________________________________________________________
