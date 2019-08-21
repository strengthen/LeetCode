__________________________________________________________________________________________________
sample 180 ms submission
class Solution:
    """
    T: O()
    S: O()
    """
    def isNStraightHand(self, hand: List[int], k: int) -> bool:
        if not k or k < 0:
            return True
        if k == 1:
            return bool(hand)
        if len(hand) % k:
            return False

        cnts = collections.Counter(x % k for x in hand)
        return len(set(cnts.values())) == 1 and len(cnts) == k
__________________________________________________________________________________________________
sample 14428 kb submission
class Solution:
    def isNStraightHand(self, hand: List[int], W: int) -> bool:
        count = collections.Counter(hand)
        while count:
            m = min(count)
            for card in range(m, m+W):
                if count[card] == 0:
                    return False
                elif count[card] == 1:
                    del count[card]
                else:
                    count[card] -= 1
        return True
__________________________________________________________________________________________________
