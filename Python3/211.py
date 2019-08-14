__________________________________________________________________________________________________
sample 116 ms submission
import string 
class WordDictionary(dict): 
    allowed = {*string.ascii_lowercase} 
 
    def __init__(self): 
        """ 
        Initialize your data structure here. 
        """ 
         
 
    def addWord(self, word: str) -> None: 
        """ 
        Adds a word into the data structure. 
        """
        self.setdefault(len(word),[]).append(word)
 
    def search(self, word: str) -> bool: 
        """ 
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. 
        """
        l = len(word)
        if l not in self:
            return False
        elif word in self[l]: 
            return True 
        else: 
            cands = self[l].copy()
            
            for i,c in enumerate(word):
                if c=='.':
                    continue
                cands = [cand for cand in cands if cand[i]==c]
                if not cands:
                    return False
            return True       
__________________________________________________________________________________________________
sample 21984 kb submission
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie = {}
        return
    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        node = self.trie
        for w in word:
            if(w not in node):
                node[w] = {}
            node = node[w]
        node['EOW'] = word
        return 
    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        node = self.trie
        found = self.rsearch(node,word,0)
        return found
    def rsearch(self,node,word,i):
        if(i==len(word)):
            if('EOW' in node):
                return True
            return False
        found = False
        if(word[i]=='.'):
            for k in node.keys():
                if(k != 'EOW'):
                    found = self.rsearch(node[k],word,i+1)
                    if(found):
                        return found
        else:
            w = word[i]
            if(w in node):
                found = self.rsearch(node[w],word,i+1)
        return found 
                
                    
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
__________________________________________________________________________________________________
