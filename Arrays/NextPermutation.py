from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        if len(nums) == 1: 
            return

        m = len(nums) - 1
        p = m
        c = p - 1

        while (nums[c] >= nums[p] and c >= 0):
            p = c
            c -= 1

        while (c >= 0 and nums[c] >= nums[m] and m >= 0):
            m -= 1
                
        if (c >= 0):
            tmp = nums[m]
            nums[m] = nums[c]
            nums[c] = tmp

        # sort from p to m
        nums[p:] = sorted(nums[p:])
        print(nums)

sol = Solution()
sol.nextPermutation([1,2,3])
sol.nextPermutation([3,2,1])
sol.nextPermutation([1,1,5])
sol.nextPermutation([1,5,1])
sol.nextPermutation([1,2,3,4,5])
sol.nextPermutation([1,2,4,5,3])
sol.nextPermutation([1,2,5,4,3])
sol.nextPermutation([1,1])
sol.nextPermutation([1])
sol.nextPermutation([0,0,0,0,0,0])
sol.nextPermutation([5,1,1])
