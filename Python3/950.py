__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        N = len(deck)
        index = collections.deque(range(N))
        ans = [None] * N

        for card in sorted(deck):
            ans[index.popleft()] = card
            if index:
                index.append(index.popleft())

        return ans
__________________________________________________________________________________________________
sample 13032 kb submission
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
      sortedDeck = sorted(deck)
      newDeck = []
      while sortedDeck:
        if newDeck:
          newDeck.append(newDeck.pop(0))
        newDeck.append(sortedDeck.pop())
      newDeck.reverse()
      return newDeck
__________________________________________________________________________________________________
