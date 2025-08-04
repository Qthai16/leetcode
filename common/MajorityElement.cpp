#include <vector>
#include <cstdlib>

using namespace std;

int majorityElement(vector<int> &nums) {
    int64_t major = 0;
    int maxf = 0;
    for (int n: nums) {
        if (maxf == 0) {
            major = n;
        }
        maxf += n == major ? 1 : -1;
    }
    return major;
}