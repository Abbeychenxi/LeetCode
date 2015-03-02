//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice?
//For example,
//Given sorted array A = [1,1,1,2,2,3],
//
//Your function should return length = 5, and A is now [1,1,2,2,3].

#include <iostream>

using namespace std;

class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            if ( n <= 2 ) return n;

            int index = 2;
            for ( int i = 2; i < n; ++i) {
                if (A[i] != A[index-2])
                    A[index++] = A[i];
            }
            return index;
        }
};

int main(int argc, char const* argv[])
{
    Solution sol;
    int a[] = {1,1,1,2,2,3};
    int res = sol.removeDuplicates(a, 6);
    cout << res << endl;
    for (auto index = 0; index != 6; ++index) {
        cout << a[index] << ' ';
    }
    cout << endl;
    return 0;
}
