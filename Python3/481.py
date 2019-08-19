__________________________________________________________________________________________________
sample 60 ms submission
s = [1,2,2]
index = 2
while len(s) < 100000:
	# according to the last element, we decide the value of 'val'
	val = 3 - s[-1]
	s.extend([val]*s[index])
	index += 1

class Solution(object):
    def magicalString(self, n):
        """
        :type n: int
        :rtype: int
        """
        return s[:n].count(1)
__________________________________________________________________________________________________
sample 14004 kb submission
class Solution:
    def magicalString(self, n: int) -> int:
        s_list = list(map(int,"1221121221221121122"))
        S = "1221121221221121122"
        S_len = len(S)
        if n<=S_len:
            return S[:n].count("1")
        else:
            count = 19
            i = 12
            while count<n:
                if not i%2:
                    S+=s_list[i]*'1'
                    # s_list.append(s_list[i])
                    # s_list = list(map(int,S))
                else:
                    S+=s_list[i]*'2'
                    # s_list.append(s_list[i])
                    # s_list = list(map(int,S))
                s_list.append(int(S[len(s_list)]))
                count += s_list[i]
                i+=1
            return S[:n].count("1")                
__________________________________________________________________________________________________
