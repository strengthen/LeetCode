__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        
        strs.sort(key=len)
        
        #print(strs)
        
        used_0=0
        used_1=0
        res=0
        res_0=0
        res_1=0
        res_comb=0
        for i in range(len(strs)):
            tmp_0=strs[i].count("0")
            #tmp_1=strs[i].count("1")
            tmp_1=len(strs[i])-tmp_0
            
            if m-used_0>=tmp_0 and n-used_1>=tmp_1:
                res+=1
                used_0+=tmp_0
                used_1+=tmp_1
                
        #return res
        used_0=0
        used_1=0
        
        strs.sort(key=lambda k: k.count("0"))
        for i in range(len(strs)):
            tmp_0=strs[i].count("0")
            #tmp_1=strs[i].count("1")
            tmp_1=len(strs[i])-tmp_0
            
            if m-used_0>=tmp_0 and n-used_1>=tmp_1:
                res_0+=1
                used_0+=tmp_0
                used_1+=tmp_1    
        
        used_0=0
        used_1=0
        strs.sort(key=lambda k: k.count("1"))
        for i in range(len(strs)):
            tmp_0=strs[i].count("0")
            #tmp_1=strs[i].count("1")
            tmp_1=len(strs[i])-tmp_0
            
            if m-used_0>=tmp_0 and n-used_1>=tmp_1:
                res_1+=1
                used_0+=tmp_0
                used_1+=tmp_1  
        
        used_0=0
        used_1=0
        
        strs.sort(key=lambda k: (len(k),-k.count("0")*k.count("1")))
        for i in range(len(strs)):
            tmp_0=strs[i].count("0")
            #tmp_1=strs[i].count("1")
            tmp_1=len(strs[i])-tmp_0
            
            if m-used_0>=tmp_0 and n-used_1>=tmp_1:
                res_comb+=1
                used_0+=tmp_0
                used_1+=tmp_1    
        
        return max([res,res_0,res_1,res_comb])
__________________________________________________________________________________________________
sample 52 ms submission
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        results = self.keyComb(strs, m, n, len)
        results_2 = self.keyComb(strs, m, n, lambda x: -1*len(x))
        results_3 = self.keyComb(strs, m, n, lambda x: x.count('1'))
        results_4 = self.keyComb(strs, m, n, lambda x: x.count('0'))
        
        results_5 = self.keyComb(strs, m, n, lambda x: x.count('0'), 
                                 double=True, key_2=len)
        results_6 = self.keyComb(strs, m, n, lambda x: x.count('0'), 
                                 double=True, key_2=lambda x: -1*len(x))
        
        results_7 = self.keyComb(strs, m, n, lambda x: x.count('1'), 
                                 double=True, key_2=len)
        results_8 = self.keyComb(strs, m, n, lambda x: x.count('1'), 
                                 double=True, key_2=lambda x: -1*len(x))
        return max(len(results), len(results_2), len(results_3), len(results_4), len(results_5), len(results_6), len(results_7), len(results_8))
    
    def keyComb(self,  strs, m, n, key, double=False, key_2=None,):
        # m's -> 0's, n's -> 1's
        result = []
        strs.sort(key=key)
        if double:
            strs.sort(key=key_2)
        for str_i in strs:
            ones = str_i.count('1')
            zeros = str_i.count('0')
            # print ('string {} ones {}, zeroes{}, m {}, n {} \n'.format(str_i, ones,zeros, m, n))
            if zeros <= m and ones <= n:
                m -= zeros
                n -= ones
                result.append(str_i)
            if ones == 0 and zeros == 0:
                break
        return result
__________________________________________________________________________________________________
