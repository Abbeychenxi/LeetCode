#coding: utf-8

'''
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

'''

class Solution:
  # @return an integer
  def process(slef, x):
    str_x = str(x)
    str_x = str_x[::-1]
    x = int(str_x)
    return x

  def reverse(self, x):
    if x > 0:
      x = self.process(x)
      if x > 2147483647:
        x = 0
    else:
      x = -x
      x = self.process(x)
      if x > 2147483647:
        x = 0
      x = -x
    return x


sol = Solution()
print sol.reverse(1563847412)