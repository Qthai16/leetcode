#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/merge-sorted-array/description/

class Solution {
public:
    void oldSolution(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // two pointers point to end
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

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1, i = m - 1, j = n - 1;
        auto& ret = nums1;
        auto& left = nums1;
        auto& right = nums2;
        while (i >= 0 && j >= 0) {
            if (right[j] > left[i]) {
                ret[k--] = right[j--];
            } else if (left[i] > right[j]) {
                ret[k--] = left[i--];
            } else { // equal
                ret[k--] = right[j--];
                ret[k--] = left[i--];
            }
        }
        while (j >= 0) { // copy remains nums2 element
            ret[k--] = right[j--];
        }
    }
};