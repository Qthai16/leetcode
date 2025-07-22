#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        auto ind = n + m - 1;
        if (nums2.empty() || n == 0) return;
        while (i >= 0 && j >= 0) {
            if (nums2[j] >= nums1[i]) {
                nums1[ind] = nums2[j];
                j--;
            } else {
                nums1[ind] = nums1[i];
                i--;
            }
            ind--;
        }
        while (j >= 0) {
            nums1[ind] = nums2[j];
            j--;
            ind--;
        }
        return;
    }
};