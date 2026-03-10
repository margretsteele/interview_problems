#include <iostream>

using namespace std;

// Paint Fence (Google variant)
//
// Given n fence posts and 2 colors (black and white), count the number of ways
// to paint all posts such that no 3 consecutive posts share the same color.
//
// DP approach: track how many consecutive posts of the current color we've used.
//   - one[c] = ways ending with exactly 1 post of color c
//   - two[c] = ways ending with exactly 2 consecutive posts of color c
// Transitions:
//   - new_one[c] = one[1-c] + two[1-c]   (switch to color c, run of 1)
//   - new_two[c] = one[c]                 (extend run of 1 to 2; 2->3 is forbidden)
//
// Write your solution here:
int paintFence(int n) {
    int singles = 2;
    int doubles = 2;
    int sum = singles + doubles;
    if(n < 1) return -1;
    if(n == 1) return 2;
    for(int i = 3; i <= n; i++) {
        int prev = singles;
        singles = prev + doubles;
        doubles = prev;

        sum = singles + doubles;
    }
    return sum;
}

int main() {
    cout << "n=1: " << paintFence(1) << endl;  // Expected: 2 (B or W)
    cout << "n=2: " << paintFence(2) << endl;  // Expected: 4 (BB, BW, WB, WW)
    cout << "n=3: " << paintFence(3) << endl;  // Expected: 6 (BBW, BWB, BWW, WBB, WBW, WWB)
    cout << "n=4: " << paintFence(4) << endl;  // Expected: 10
    cout << "n=5: " << paintFence(5) << endl;  // Expected: 16
    cout << "n=10: " << paintFence(10) << endl; // Expected: 178
    return 0;
}
