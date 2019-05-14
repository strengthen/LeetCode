__________________________________________________________________________________________________
def longestDupSubstring(self, s: str) -> str:
    low, high = 2, len(s) - 1
    best = ''

    while low <= high:
        mid = low + (high - low) // 2
        v = self.find_duplicate_substr_of_len_k(s, mid)

        if v != '':
            best = v
            low = mid + 1
        else:
            high = mid - 1

    return best


def find_duplicate_substr_of_len_k(self, s, k):
    MOD = (1 << 61) - 1
    BASE = 26
    D = pow(BASE, k - 1, MOD)
    chash = 0
    seen = collections.defaultdict(list)

    for i in range(len(s)):
        if i >= k:
            l_chval = ord(s[i - k]) - ord('a')
            chash = (chash - l_chval * D) % MOD

        chval = ord(s[i]) - ord('a')
        chash = (chash * BASE + chval) % MOD

        if i >= k - 1:
            if chash in seen:
                substr_i = s[i - k + 1:i + 1]
                for j in seen[chash]:
                    substr_j = s[j - k + 1:j + 1]
                    if substr_i == substr_j:
                        return substr_i

            seen[chash].append(i)

    return ''
__________________________________________________________________________________________________

__________________________________________________________________________________________________
