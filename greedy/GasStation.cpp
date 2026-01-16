#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/gas-station

// int maybeBetterSolution(vector<int>& gas, vector<int>& cost) {
//     // this solution failed some edge cases
//     if (gas.size() == 1) return gas[0] >= cost[0] ? 0 : -1;
//     int start = 0, curgas = 0, i = start, precurgas = 0;
//     while (start < gas.size()) {
//         precurgas = curgas;
//         curgas += gas[i] - cost[i];
//         if (curgas > 0 || (curgas == 0 && (curgas != precurgas))) {
//             i = (i + 1)%gas.size();
//             if (i == start)
//                 return i;
//             continue;
//         }
//         curgas = 0;
//         start += 1;
//         i = start;
//     }
//     return -1;
// }

class Solution {
public:
    int naiveSolution(vector<int> &gas, vector<int> &cost) {
        // check if total cost > total gas, return -1
        // O(N^2) time complexity. Loop O(N) in gas, for each start index, check if we can finish the whole loop, else increase start index
        int size = gas.size();
        int gassum = 0, costsum = 0, start = 0;
        bool setstart = false;
        for (int i = 0; i < size; i++) {
            gassum += gas[i];
            costsum += cost[i];
            if (gas[i] > 0 && !setstart) {
                start = i;
                setstart = true;
            }
        }
        if (costsum > gassum)
            return -1;

        int ret = start;
        int curgas = 0;
        while (start < size) {// there is gurantee at least one solution
            curgas += gas[ret] - cost[ret];
            if (curgas < 0) {   // equal 0 is ok, because we have arrive at next station
                start = ret + 1;// start at next station, due to all station between [start, ret] is invalid
                ret = start;
                curgas = 0;
                continue;
            }
            ret = (ret + 1) % size;
            if (ret == start)
                return ret;
        }
        // will never reach here
        return -1;
    }

    int betterSolution(vector<int> &gas, vector<int> &cost) {
        // one pass
        int curgas = 0, start = 0, i = 0, totalSurPlus = 0, cnt = 0;
        vector<bool> visited(gas.size(), false);
        while (start < gas.size()) {
            if (!visited[i]) {
                visited[i] = true;
                totalSurPlus += gas[i] - cost[i];
                cnt += 1;
            }
            curgas += gas[i] - cost[i];
            if (curgas < 0) {
                start = i + 1;
                i = start;
                curgas = 0;
                if (cnt == gas.size()) break;
                continue;
            }
            i = (i + 1) % gas.size();
            if (i == start) break;
        }
        return totalSurPlus < 0 ? -1 : start;
    }

    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        return betterSolution(gas, cost);
    }
};