//
//  Longest-Substring-Without-Repeating-Characters.cpp
//  LeetCode
//
//  Created by 陈希 on 14/11/30.
//  Copyright (c) 2014年 陈希. All rights reserved.
//

/*
 Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
    最长不重复字串的长度
*/

#include "Longest-Substring-Without-Repeating-Characters.h"
#include <iostream>
using namespace std;
#include <map>

int Solution::lengthOfLongestSubstring(string s)
{
    map<char, int> m;
    int maxLen = 0;
    int lastRepeatPos = -1;
    for(int i=0; i<s.size(); i++){
        if (m.find(s[i])!=m.end() && lastRepeatPos < m[s[i]]) {
            lastRepeatPos = m[s[i]];
        }
        if ( i - lastRepeatPos > maxLen ){
            maxLen = i - lastRepeatPos;
        }
        m[s[i]] = i;
    }
    return maxLen;
}