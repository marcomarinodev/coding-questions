import math

class Solution:
    def longestPalindrome(self, s: str) -> int:
        dict = {}
        odd = False
        maxPalindromeLen = 0

        for c in s:
            if c in dict:
                dict[c] += 1
            else:
                dict[c] = 1

        for key in dict:
            if dict[key] % 2 == 1 and not odd:
                maxPalindromeLen += 1
                odd = True
            maxPalindromeLen += dict[key] if (dict[key] % 2 == 0) else dict[key] - 1 

        return maxPalindromeLen

sol = Solution()
print(sol.longestPalindrome("abcCccdd"))
print(sol.longestPalindrome("a"))
print(sol.longestPalindrome("bb"))
print(sol.longestPalindrome("acccaccca"))
print(sol.longestPalindrome("ccc"))