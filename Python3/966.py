__________________________________________________________________________________________________
sample 192 ms submission
class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        def removevowels(word):
            for x in ['a', 'e', 'i', 'o', 'u']:
                word = word.replace(x, '.')
            
            return word
        
        X, Y = {}, {}
        for word in wordlist:
            x = word.lower()
            if x in X:
                X[x] += [word]
                
            else:
                X[x] = [word]
            
            y = removevowels(x)
            if y not in Y:
                Y[y] = word
        
        for i, q in enumerate(queries):
            x = q.lower()
            if x in X:
                queries[i] = q if q in X[x] else X[x][0]
                
            else:
                y = removevowels(x)
                queries[i] = Y[y] if y in Y else ''
        
        return queries
__________________________________________________________________________________________________
sample 196 ms submission
class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        def devowel(words):
            return "".join("*" if letter in 'aeiou' else letter for letter in words)

        wordOrig = set(wordlist)
        wordCap = {}
        wordVow = {}
        
        for word in wordlist:
            wordLow = word.lower()
            wordCap.setdefault(wordLow, word)
            wordVow.setdefault(devowel(wordLow), word)
        
        def helper(query):
            if query in wordOrig:
                return query
            
            queryLow = query.lower()
            if queryLow in wordCap:
                return wordCap[queryLow]
            
            queryVow = devowel(queryLow)
            if queryVow in wordVow:
                return wordVow[queryVow]
            return ''
        
        return map(helper, queries) 
__________________________________________________________________________________________________
