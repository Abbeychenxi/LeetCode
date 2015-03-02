#coding: utf-8

"""
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
"""

# Definition for singly-linked list.
class ListNode:
  def __init__(self, x):
    self.val = x
    self.next = None

class Solution:
  # @return a ListNode
  def dfs(self, l, numbers):
    numbers.append(l.val)
    if l.next:
      l = l.next
      self.dfs(l, numbers)

  def listToNum(self, _list):
    length = len(_list) - 1
    _list = _list[::-1]
    number = 0
    for num in _list:
      number += num * 10**length
      length -= 1
    return number

  def addTwoNumbers(self, l1, l2):
    list1 = []
    list2 = []
    self.dfs(l1, list1)
    self.dfs(l2, list2)
    print list1, list2
    num1 = self.listToNum(list1)
    num2 = self.listToNum(list2)
    print num1, num2
    res = num1 + num2
    res = str(res)[::-1]
    nodes = []
    for index in res:
      nodes.append(ListNode(int(index)))
    for i in range(0, len(nodes) - 1):
      nodes[i].next = nodes[i + 1]
    return nodes[0]

l11 = ListNode(2)
l12 = ListNode(4)
l13 = ListNode(3)
l11.next = l12
l12.next = l13
l21 = ListNode(5)
l22 = ListNode(6)
l23 = ListNode(4)
l21.next = l22
l22.next = l23
# l1 = ListNode(0)
# l2 = ListNode(0)

sol = Solution()
print sol.addTwoNumbers(l11, l21).val
