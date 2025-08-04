#include <gtest/gtest.h>

#include "BinarySearch.h"
#include "debug/RandomUtils.h"

TEST(binary_search, tc1) {
    std::vector<int> a;
    for (auto i = 0; i < 100; i++) {
        a.push_back(libs::random_num(100, 1000));
    }
    std::sort(a.begin(), a.end());
    for (auto i = 0; i < 50; i++) {
        auto v = libs::random_num(100, 1000);
        auto d = std::lower_bound(a.begin(), a.end(), v) - a.begin();
        ASSERT_EQ(d, lower_bound(a, v));
    }
}
