import heapq
from typing import List, Optional

# Assuming ListNode is already defined elsewhere
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
        
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        heapq.heapify(heap)
        counter = 0 
        for l in lists:
            if l:
                heapq.heappush(heap, (l.val, counter, l))
                counter += 1

        head = ListNode(0)
        current = head

        while heap:
            val, _, node = heapq.heappop(heap)
            current.next = node
            current = current.next
            if node.next:
                counter += 1
                heapq.heappush(heap, (node.next.val, counter, node.next))

        return head.next