//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
//Note:
//Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
//The solution set must not contain duplicate quadruplets.
//For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
//
//A solution set is:
//(-1,  0, 0, 1)
//(-2, -1, 1, 2)
//(-2,  0, 0, 2)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        unordered_map<int, vector<pair<int, int> > > record;
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        if (num.size() < 4) return result;
        for(int i = 0; i <= num.size() - 1; ++i) {
            for(int j = i+1; j <= num.size() - 1; ++j) {
                int tmp = num[i] + num[j];
                auto ite = record.find(tmp);
                if (ite != record.end()) {
                    record[tmp].push_back(make_pair(i, j));
                } else {
                    auto tmp_pair = make_pair(i, j);
                    vector<pair<int, int> > tmp_vec = {tmp_pair};
                    record[tmp] = tmp_vec;
                }
            }
        }
        for (int i = 0; i < num.size(); ++i) {
            for (int j = i+1; j < num.size()-2; ++j) {
                int t = target - num[i] - num[j];
                if (record.find(t) != record.end()) {
                    for (auto p : record[t]) {
                        int a = p.first;
                        int b = p.second;
                        if (a > j) {
                            vector<int> temp = {num[i], num[j], num[a], num[b]};
                            result.push_back(temp);
                        }
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
    vector<int> s = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int> > result;
    result = sol.fourSum(s, target);
    for (auto i : result) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}
