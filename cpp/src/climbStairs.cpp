#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Climbing Stairs: how many ways to reach step n if you can take 1 or 2 steps?
// Write your solution here:
int climbStairsRecurrsive(int const& numStairs) {
    if(numStairs <= 2) return numStairs;
    int numWays = climbStairsRecurrsive(numStairs - 1) + climbStairsRecurrsive(numStairs - 2);
    return numWays;
}

int climbStairs(int const& numStairs) {
    if(numStairs <= 2) return numStairs;
    vector<int> cost(numStairs);
    cost[0] = 1;
    cost[1] = 2;
    for(int i = 2; i < numStairs; i++) {
        cost[i] = cost[i - 1] + cost[i - 2];
    }
    return cost[numStairs - 1];
}

int main() {
    cout << "Climb 1: " << climbStairs(1) << endl;  // Expected: 1
    cout << "Climb 2: " << climbStairs(2) << endl;  // Expected: 2
    cout << "Climb 5: " << climbStairs(5) << endl;  // Expected: 8
    cout << "Climb 10: " << climbStairs(10) << endl; // Expected: 89
    return 0;
}
