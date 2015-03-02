//
//  Median of Two Sorted Arrays.cpp
//  LeetCode
//
//  Created by 陈希 on 14/11/30.
//  Copyright (c) 2014年 陈希. All rights reserved.
//

/*
 There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 有两个数组A和B的大小排序分别为m和n。找到两个数组的中值。
*/

#include "Median of Two Sorted Arrays.h"
#include <vector>
using namespace std;

double Solution::findMedianSortedArrays(int A[], int m, int B[], int n)
{
    vector<int> C;
    for (int i = 0; i < m; i++) {
        C.push_back(A[i]);
    }
    for (int i = 0; i < n; i++) {
        C.push_back(B[i]);
    }
    sort(C.begin(), C.end());
    if (m+n == 1) {
        return C[0];
    }
    if ((m+n) % 2 == 0) {
        auto i = C.begin() + (m+n)/2 - 1;
        double res = *i;
        i = i + 1;
        res += *i;
        return res/2;
    }
    auto i = C.begin();
    i = i + (m+n+1)/2 -1;
    return *i;
}