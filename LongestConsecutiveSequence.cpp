//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//For example, Given      , The longest consecutive elements sequence is    . Return its length: 4.
//Your algorithm should run in O(n) complexity.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> used;
        for (auto n : num) {
            used[n] = false;
        }
        int longest = 0;
        for(auto index : num) {
            if (used[index])
                continue;
            int length = 1;
            used[index] = true;
            for(int nxt = index + 1; used.find(nxt) != used.end(); ++nxt) {
                used[nxt] = true;
                ++length;
            }
            for(int pre = index - 1; used.find(pre) != used.end(); --pre) {
                used[pre] = true;
                ++length;
            }
            longest = max(longest, length);
        }
        return longest;
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;
    vector<int> vec = {100, 4, 200, 1, 3, 2};
    int res = sol.longestConsecutive(vec);
    cout << res << endl;
    return 0;
}
