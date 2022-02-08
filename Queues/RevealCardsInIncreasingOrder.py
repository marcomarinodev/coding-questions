import collections
from typing import List, final

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

sol = Solution()

print(sol.deckRevealedIncreasing([17,13,11,2,3,5,7]))
print(sol.deckRevealedIncreasing([1,2,3,4]))
print(sol.deckRevealedIncreasing([1,1000]))
print(sol.deckRevealedIncreasing([1]))