__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def isRationalEqual(self, S: str, T: str) -> bool:
        def num(s):
            if s == "":
                return 0
            return int(s)
        
        def get_int(s):
            return (num(s.split(".")[0]), 1)
        
        def get_non_rep(s):
            nrp = s.split(".")[1].split("(")[0] if '.' in s else ""
            return (num(nrp), 10 ** len(nrp))
        
        def get_rep(s, dnrp):
            rp = s.split('(')[1].split(')')[0] if '(' in s else ""
            return (num(rp), (int('9' * len(rp)) if rp != "" else 1) * dnrp)
        
        def n_digits(n):
            return len(str(n)) if n > 0 else 0
        
        def fraction(s):
            ip, dip = get_int(s)
            nrp, dnrp = get_non_rep(s)
            rp, drp = get_rep(s, dnrp)
            
            print(ip, nrp, rp)
            
            numerator = ip * dnrp * drp + nrp * dip * drp + rp * dip * dnrp
            denom = dip * dnrp * drp
            
            return (numerator, denom)

        (ns, ds) = fraction(S)
        (nt, dt) = fraction(T)
        
        print(ns, ds)
        print(nt, dt)
        
        return ns * dt == ds * nt
__________________________________________________________________________________________________
sample 13100 kb submission
class Solution:
    def isRationalEqual(self, S: str, T: str) -> bool:
        def gcd(x, y):
            while y > 0:
                x, y = y, x % y
            return x
        
        def convert(x):
            zero = x.replace("(", "").replace(".", "").replace(")", "")
            if zero == "0" * len(zero):
                return "0"
            
            index_digit = x.find(".")
            index_left = x.find("(")
            if index_left == -1:
                up = int(float(x) * 10**len(x))
                down = int(10**len(x))
                max_c = gcd(up, down)
                return str(up//max_c) + "/" + str(down//max_c)
            else:
                mutiply_by =  10 ** (index_left - index_digit-1) 
                interger_part = int(x[:index_left].replace(".", ""))
                recursion_l = len(x) - index_left - 2
                recursion_part = int(x[index_left +1:-1])
                down = (10 ** recursion_l - 1)
                up = recursion_part + interger_part * down
                down *= mutiply_by
                max_c = gcd(up, down)
                return str(up//max_c) + "/" + str(down//max_c)

        return convert(S) == convert(T)
__________________________________________________________________________________________________
