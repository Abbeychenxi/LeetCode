#coding:utf-8

def lengthOfLongestSubstring(s):
  scanned = []
  length = 0
  for index in s:
    if index not in scanned:
      scanned.append(index)
    else:
      if length < len(scanned):
        length = len(scanned)
      indexOfChar = scanned.index(index) + 1
      scanned = scanned[indexOfChar :]
      scanned.append(index)
  if length < len(scanned):
    length = len(scanned)
  return length


print lengthOfLongestSubstring("qopubjguxhxdipfzwswybgfylqvjzhar")
