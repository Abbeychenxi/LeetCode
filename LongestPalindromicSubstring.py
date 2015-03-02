#coding: utf-8
"""
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
给定一个字符串,查找最长回文字符串你可以假设的最大长度是1000,并存在一个独特的最长回文字符串。
"""

class Solution:
  # @return a string
  
  def processString(self, s):
    s = " ".join(s)
    l = s.split(" ")
    l.insert(0, '$')
    s = '#'.join(l)
    s += '#^'
    return s

  def longestPalindrome(self, s):
    # length = len(s)
    # isPalinded = [[False for n in range(length)]for n in range(length)]
    # maxOfLength = 1
    # start = 0
    # for i in range(0, length):
    #   isPalinded[i][i] = True
    #   for j in range(0, i):
    #     isPalinded[j][i] = (s[j] == s[i] and (i - j < 2 or isPalinded[j+1][i-1]))
    #     if isPalinded[j][i] and maxOfLength < (i - j + 1):
    #       maxOfLength = i - j + 1
    #       start = j
    # return s[start : maxOfLength + 1]
    # 时间复杂度O(n^2)超过限制
    s = self.processString(s)
    # print s
    mx = 0
    id = 0
    p = [0 for n in range(0, len(s))]
    for i in range(1, len(s) - 1):
      # print i
      p[i] = min(p[2 * id - i], mx - i) if mx > i else 1
      while s[i + p[i]] == s[i - p[i]]:
        p[i] += 1
      if i + p[i] > mx:
        mx = i + p[i]
        id = i
    maxLength = max(p)
    index = p.index(maxLength)
    start = index - maxLength + 1
    end = index + maxLength - 1
    s = s[start : end]
    l = s.split('#')
    return ''.join(l)





sol = Solution()
print sol.longestPalindrome("aba")