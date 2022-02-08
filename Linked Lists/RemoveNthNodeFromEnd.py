# Definition for singly-linked list.
from typing import List, Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head == None:
            return None
        
        last = head
        current = head
        prev = None

        for i in range(1, n):
            if last != None:
                last = last.next


        while (last != None and last.next != None):
            prev = current
            current = current.next
            last = last.next   

        if prev == None:
            head = current.next
        else:
            prev.next = current.next

        return head      

def printList(head: ListNode):
    current = head
    while (current != None):
        print(current.val)
        current = current.next
    print("-------")

sol = Solution()

list1 = ListNode(1, 
    ListNode(2,
        ListNode(3,
            ListNode(4,
                ListNode(5)
            )
        )
    )
)

# printList(sol.removeNthFromEnd(list1, 2))

list2 = ListNode(1, ListNode(2))
printList(sol.removeNthFromEnd(list2, 1))

list3 = ListNode(1)
# printList(sol.removeNthFromEnd(list3, 1))

list4 = None
# printList(sol.removeNthFromEnd(list4, 0))

list5 = ListNode(1, 
    ListNode(2,
        ListNode(3,
            ListNode(4,
                ListNode(7)
            )
        )
    )
)

# printList(sol.removeNthFromEnd(list5, 5))