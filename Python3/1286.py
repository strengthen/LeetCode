__________________________________________________________________________________________________
class CombinationIterator(object):

    def __init__(self, characters, combinationLength):
        """
        :type characters: str
        :type combinationLength: int
        """
        self.char = characters
        self.comb = combinationLength
        self.cur = 0
        
        self.comblist = [] # ['ab','ac','bc'] # populate the list with combinationLength
        self.helper('', 0, self.comb, self.comblist,0)
 
        
    def helper(self, strin , ind, cap, res, cumu):
        if cumu == cap:
            res.append(strin)
            return 
        for i in range(ind, len(self.char)):
            self.helper( strin + self.char[i] , i+1, cap,res, cumu+1 )
  
 
        
    def next(self):
        """
        :rtype: str
        """
        self.cur += 1
        return self.comblist[self.cur - 1]
        
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.cur < len(self.comblist) 
__________________________________________________________________________________________________

__________________________________________________________________________________________________
