//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
//For example, given array S = {-1 2 1 -4}, and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& num, int target) {
        int result = INT_MAX/2;
        if (num.size() < 3) return result;
        sort(num.begin(), num.end());

        for (int i = 0; i < num.size()-2; ++i) {
            if (i > 0 && num[i] == num[i-1]) continue;
            for (int j = i+1; j < num.size()-1; ++j) {
                if (j>i+1 && num[j-1] == num[j]) continue;
                int first = j + 1;
                int last = num.size() - 1;
                while ( first <= last ) {
                    int mid = (first + last)/2;
                    if (num[i] + num[j] + num[mid] < target) {
                        first = mid + 1;
                        int tmp = num[i]+num[j]+num[mid];
                        result = (target - tmp) < abs(target - result) ? tmp : result;
                    }else if (num[i] + num[j] + num[mid] > target) {
                        last = mid - 1;
                        int tmp = num[i]+num[j]+num[mid];
                        result = (tmp - target) < abs(target - result) ? tmp : result;
                    }else {
                        result = target;
                        break;
                    }
                }
            }
        }
        return result;
    }
};


int main(int argc, char const* argv[])
{
    Solution sol;
    vector<int> s = {1, 1, 1, 0};
    int res = sol.threeSumClosest(s, 100);
    cout << res << endl;
    return 0;
}
