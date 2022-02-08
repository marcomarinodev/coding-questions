from fileinput import close
from typing import List
import math

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()

        closest = math.inf
        for i in range(len(nums) - 2):
            j = i + 1
            k = len(nums) - 1
            while j < len(nums) - 1 and j < k:
                sum = nums[i] + nums[j] + nums[k]
                if abs(closest - target) >= abs(sum - target):
                    closest = sum
                if sum > target:
                    k -= 1
                else:
                    j += 1

        return closest


sol = Solution()
print(sol.threeSumClosest([-1,2,1,-4], 1))
