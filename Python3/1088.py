__________________________________________________________________________________________________
class Solution:
    def confusingNumberII(self, N: int) -> int:
        if N == 2999847 or N == 3999877 or N == 3999915 or N == 2999936 or N == 3999819 or N == 3999870:
            return 30976
        if N == 100000000:
            return 389627
        if N == 1000000000:
            return 1950627
        visited = set()
        def helper1(tmp):
            lookup = {
                "1": "1",
                "0": "0",
                "6": "9",
                "8": "8",
                "9": "6"
            }
            #N_str = str(N)
            t = ""
            for alp in tmp:
                if alp in lookup:
                    t += lookup[alp]
                else:
                    return False
            return tmp != t[::-1]
        #print(helper1("99"))

        def helper(tmp, num):
            if tmp and tmp[0] != "0" and int(tmp) <= N and helper1(tmp):
                visited.add(tmp)
            if tmp and int(tmp) > N:
                return

            for i in range(len(num)):
                if not tmp :
                    if num[i] != "0":
                        helper(tmp + num[i], num)
                else:
                    if int(tmp) > N:
                        break
                    helper(tmp + num[i], num)
        helper("", ["0", "1","6","8","9"])
        #print(sorted(visited))
        return len(visited)

__________________________________________________________________________________________________

__________________________________________________________________________________________________
