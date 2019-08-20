__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def replaceWords(self, dict: List[str], sentence: str) -> str:
    	D, s = {}, sentence.split()
    	for d in dict:
    		if d[0] in D: D[d[0]].append([d,len(d)])
    		else: D[d[0]] = [[d,len(d)]]
    	for i in D: D[i].sort(key = lambda x: x[1])
    	for i,j in enumerate(s):
    		f, t = j[0], len(j)
    		if f not in D: continue
    		for a,b in D[j[0]]:
    			if b > t: break
    			if a == j[:b]:
    				s[i] = a
    				break
    	return " ".join(s) 
__________________________________________________________________________________________________
sample 16688 kb submission
class Solution:
    def replaceWords(self, dict: List[str], sentence: str) -> str:
        initial_words = sentence.split()
        words = set(initial_words)

        dict.sort(key=lambda x: len(x))
        len_dict = {}

        for w in dict:
            l = len(w)
            if l in len_dict:
                len_dict[l].append(w)
            else:
                len_dict[l] = [w]

        replacements = {}

        for word in words:
            # Find all possible roots
            i = 0
            while(i < len(word)-1):
                root = ''
                found = False

                for j in range(i, len(word)-1):
                    root += word[j]
                    l = len(root)

                    if (l in len_dict) and (root in len_dict[l]):
                        found = True

                        if (word in replacements): 
                            if (len(root) < len(replacements[word])):
                                replacements[word] = root
                        else:
                            replacements[word] = root

                        break

                if found:
                    i += len(root)
                else:
                    break

        for i in range(len(initial_words)):
            w = initial_words[i]

            if (w in replacements):
                initial_words[i] = replacements[w]

        return " ".join(initial_words)
__________________________________________________________________________________________________
