#coding: utf-8

'''
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
'''

class Solution:
    # @return a string
    def convert(self, s, nRows):
      if nRows < 2 or s < 2:
        return s
      raw = len(s)/(2 * nRows - 2) if len(s)%(2 * nRows -2) == 0 else len(s)/(2 * nRows - 2) + 1
      res = ""
      for i in range(0, nRows):
        for j in range(0, raw):
          if i == 0 or i == nRows - 1:
            if j * (2 * nRows - 2) + i > len(s) - 1:
              continue
            res += s[j * (2 * nRows - 2) + i]
          else:
            if j * (2 * nRows - 2) + i > len(s) - 1:
              continue
            if (j + 1) * (2 * nRows - 2) - i > len(s) - 1:
              res += s[j * (2 * nRows - 2) + i]
            else:
              res += s[j * (2 * nRows - 2) + i] + s[(j + 1) * (2 * nRows - 2) - i]
      return res

sol = Solution()
print sol.convert("PAYPALISHIRING", 3)
