from math import floor
from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        current = head
        size = 0
        last = None

        # first scan to get the linked list size
        while (current != None):
            size += 1
            last = current
            current = current.next
        
        # iterate throught the middle node
        mid = (size/2 - 1) if (size % 2 == 0) else floor(size/2)
        iterator = 0
        current = head
        while (iterator < mid):
            iterator += 1
            current = current.next

        # from now, we have to reverse the list
        prev = None
        next = current

        while (next != None):
            next = current.next
            current.next = prev
            prev = current
            current = next

        current = head

        while (current != None):
            # print("curr = {}; last = {}".format(current.val, last.val))
            if current.val != last.val:
                return False
            current = current.next
            last = last.next

        return True

sol = Solution()
print(sol.isPalindrome(ListNode(1, ListNode(2, ListNode(3, ListNode(1))))))
print(sol.isPalindrome(ListNode(1, ListNode(2, ListNode(3, ListNode(4,
    ListNode(3, ListNode(2, ListNode(1)))
))))))
print(sol.isPalindrome(ListNode(1)))
print(sol.isPalindrome(None))