__________________________________________________________________________________________________
class Solution:
    def genNext(self, pattern):
        next, j = [0] * len(pattern), -1
        for i in range(len(pattern)):
            while j != -1 and pattern[j + 1] != pattern[i]:
                j = next[j]
            if i and next[j + 1] == pattern[i]:
                j += 1
            next[i] = j
        return next

    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        pattern, text = "{} {} ".format(first, second), text + " "
        next, j, result = self.genNext(pattern), -1, []

        for i in range(len(text)):
            while j != -1 and pattern[j + 1] != text[i]:
                j = next[j]

            if pattern[j + 1] == text[i]:
                j += 1

            if j == len(pattern) - 1:
			    # Corner case: in "aaa good girl" the `girl` is invalid
                if (i - len(pattern) == -1 or text[i - len(pattern)] == " ") and i + 1 < len(text):
                    result.append(text[i + 1:text.index(" ", i + 1)])
                j = next[j]

        return result
__________________________________________________________________________________________________

__________________________________________________________________________________________________
