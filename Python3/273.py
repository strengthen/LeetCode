__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def numberToWords(self, num: int) -> str:
        word = {0: "Zero",
                1: "One",
                2: "Two",
                3: "Three",
                4: "Four",
                5: "Five",
                6: "Six",
                7: "Seven",
                8: "Eight",
                9: "Nine",
                10: "Ten",
                11: "Eleven",
                12: "Twelve",
                13: "Thirteen",
                14: "Fourteen",
                15: "Fifteen",
                16: "Sixteen",
                17: "Seventeen",
                18: "Eighteen",
                19: "Nineteen",
                20: "Twenty",
                30: "Thirty",
                40: "Forty",
                50: "Fifty",
                60: "Sixty",
                70: "Seventy",
                80: "Eighty",
                90: "Ninety",
                10**2: "Hundred",
                10**3: "Thousand",
                10**6: "Million",
                10**9: "Billion"
               }
        def get_hundreds(n):
            assert n <= 999
            if n <= 20: # 0 <= n <= 20
                return [word[n]]
            elif n <= 99: # 21 <= n <= 99
                d, m = divmod(n, 10)
                prefix = [word[d*10]]
                if m != 0:
                    return prefix + [word[m]]
                else:
                    return prefix
            else: # 100 <= n <= 999
                d, m = divmod(n, 100)
                prefix = [word[d], 'Hundred']
                if m == 0:
                    return prefix
                else:
                    return prefix + get_hundreds(m)
        def get_over_hundreds(num):
            if num == 0:
                return [word[num]]
            powers = [(10**9, "Billion"),
                      (10**6, "Million"),
                      (10**3, "Thousand"),
                      (1, None)]
            prefix = []
            for x, y in powers:
                d, m = divmod(num, x)
                if d > 0:
                    prefix += get_hundreds(d)
                    if y:
                        prefix += [y]
                num = m
            return prefix
        return ' '.join(get_over_hundreds(num))
__________________________________________________________________________________________________
sample 13040 kb submission
class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0: return 'Zero'
        specials = {10: 'Ten', 11: 'Eleven', 12: 'Twelve', 13: 'Thirteen', 14: 'Fourteen', 15: 'Fifteen', 16: 'Sixteen', 17: 'Seventeen', 18: 'Eighteen', 19: 'Nineteen'}
        tens =  {2: 'Twenty', 3: 'Thirty', 4: 'Forty', 5: 'Fifty', 6: 'Sixty', 7: 'Seventy', 8: 'Eighty', 9: 'Ninety'}
        ones = {1: 'One', 2: 'Two', 3: 'Three', 4: 'Four', 5: 'Five', 6: 'Six', 7: 'Seven', 8: 'Eight', 9: 'Nine'}
        weights = {0: 'Billion', 1: 'Million', 2: 'Thousand'}
        
        ans = []
        offset = 10 ** 9 # 1 billion
        x = num
        for i in range(4):
            digits = x // offset # 3 digits
            if digits > 0:
                hundred = digits // 100
                if hundred != 0:
                    ans.append(ones[hundred])
                    ans.append('Hundred')
                ten_one = digits % 100
                if ten_one in specials:
                    ans.append(specials[ten_one])
                else:
                    ten = ten_one  // 10
                    one = ten_one % 10
                    if ten in tens: ans.append(tens[ten])
                    if one in ones: ans.append(ones[one])
                if i < 3: ans.append(weights[i])
                x %= offset
            offset //= 1000
        return ' '.join(ans)
__________________________________________________________________________________________________
