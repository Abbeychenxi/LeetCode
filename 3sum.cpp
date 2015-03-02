//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note:
//Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
//The solution set must not contain duplicate triplets.
//For example, given array S = {-1 0 1 2 -1 -4},
//
//  A solution set is:
//  (-1, 0, 1)
//  (-1, -1, 2)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    std::vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        if (num.size() < 3) return result;
        sort(num.begin(), num.end());

        for(int i = 0; i < num.size() - 2; ++i) {
            if ( i > 0 && num[i] == num[i-1]) continue;
            for (int j = i+1; j < num.size() - 1; ++j) {
                if (j > i+1 && num[j] == num[j-1]) continue;
                const int target = -(num[i] + num[j]);
                int first = j + 1;
                int last = num.size() - 1;
                if(target < num[first] || target > num[last]) continue;
                while (first <= last) {
                    int mid = (first + last)/2;
                    if(num[mid] == target) {
                        result.push_back({num[i], num[j], target});
                        break;
                    }else if (num[mid] > target)
                        last = mid - 1;
                    else {
                        first = mid + 1;
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
    vector<int> s = {0, 0, 0};
    vector<vector<int> > res;
    res = sol.threeSum(s);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}
