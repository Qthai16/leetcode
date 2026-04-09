#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/candy
// try 1 2 87 4 3 2 1 and 1 2 87 87 87 2 1 first as test case if you understand them you understand this problem
// oh btw they come out as 1 2 5 4 3 2 1 and 1 2 3 1 3 2 1

// {1 2 87 4 3 2 1}
// {1 2 5 4 3 2 1}

// [2,2,2,2,2]
// [1,1,1,1,1]

// {1 2 87 87 87 2 1}
// {1 2 3 1 3 2 1}

// [60, 80, 100, 100, 100, 100, 100]
// candies for children
// [1, 2, 3, 1, 1, 1, 1]

class Solution {
public:
    int candy(vector<int>& ratings) {
        const auto& r = ratings;
        vector<int> candy(r.size(), 1);
        for (int i = 1; i < r.size(); i++) {
            if (r[i] > r[i-1]) {

            }
        }
    }
};