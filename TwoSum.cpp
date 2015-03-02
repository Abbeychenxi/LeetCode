//
//  TwoSum.cpp
//  LeetCode
//
//  Created by 陈希 on 14/11/29.
//  Copyright (c) 2014年 陈希. All rights reserved.
//

/*Given an array of integers, find two numbers such that they add up to a specific target number.
 
 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 
 You may assume that each input would have exactly one solution.
 
 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2*/

#include "TwoSum.h"
#include <iostream>

using namespace std;

vector<int> Solution::twoSum(vector<int> &numbers, int target) {
    vector<int> res;
    
    vector<int> nums;
    nums = numbers;
    sort(numbers.begin(), numbers.end());

    for (auto index1 = numbers.begin(); index1 != numbers.end(); ++index1) {
        for(auto index2 = index1 + 1; index2 != numbers.end(); ++index2) {
            if (*index1 + *index2 == target) {
                cout << *index1 << " " << *index2 << endl;
                index1 = find(nums.begin(), nums.end(), *index1);
                for (auto index = nums.begin(); index != nums.end(); ++index) {
                    if (index == index1) {
                        continue;
                    }
                    if (*index == *index2) {
                        index2 = index;
                    }
                }
//                cout << *nums.begin() << endl;
//                cout << index1 - nums.begin() << " " << *index1 << endl;
                if (index1 > index2) {
                    swap(index1, index2);
                }
                res.push_back(index1 - nums.begin() + 1);
                res.push_back(index2 - nums.begin() + 1);
                return res;
            }
            if (*index1 + *index2 > target) {
                break;
            }
        }
    }
    return res;
}