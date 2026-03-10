/*
 * Dynamic Programming Essentials
 * ==============================
 * DP shows up frequently at Amazon, especially for L5+.
 * The key is recognizing overlapping subproblems and optimal substructure.
 *
 * Framework for solving DP problems:
 *   1. Define the subproblem (what does dp[i] represent?)
 *   2. Find the recurrence relation
 *   3. Identify base cases
 *   4. Decide iteration order (bottom-up) or use memoization (top-down)
 *   5. Optimize space if possible
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
 * Problem 1: Climbing Stairs
 * ==========================
 * You can climb 1 or 2 steps at a time. How many distinct ways to reach step n?
 *
 * dp[i] = dp[i-1] + dp[i-2]  (it's just Fibonacci!)
 *
 * Time:  O(n)
 * Space: O(1) - optimized from O(n)
 */
int climbStairs(int n) {
    if (n <= 2) return n;

    int prev2 = 1, prev1 = 2;

    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

/*
 * Problem 2: Coin Change
 * ======================
 * Given coins of different denominations and a total amount, find the
 * fewest number of coins needed to make that amount. Return -1 if impossible.
 *
 * Example: coins = [1, 5, 10, 25], amount = 30
 * Output: 2 (one 5 + one 25)
 *
 * dp[i] = min coins needed to make amount i
 * dp[i] = min(dp[i - coin] + 1) for each coin
 *
 * Time:  O(amount * num_coins)
 * Space: O(amount)
 */
int coinChange(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);  // initialize to "impossible"
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != amount + 1) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

/*
 * Problem 3: Longest Common Subsequence
 * ======================================
 * Given two strings, find the length of their longest common subsequence.
 *
 * Example: text1 = "abcde", text2 = "ace"
 * Output: 3  ("ace")
 *
 * dp[i][j] = LCS of text1[0..i-1] and text2[0..j-1]
 *
 * If chars match:    dp[i][j] = dp[i-1][j-1] + 1
 * If chars differ:   dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 *
 * Time:  O(m * n)
 * Space: O(m * n), can optimize to O(min(m, n))
 */
int longestCommonSubsequence(const string& text1, const string& text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

/*
 * Problem 4: Maximum Subarray (Kadane's Algorithm)
 * =================================================
 * Find the contiguous subarray with the largest sum.
 *
 * Example: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 * Output: 6  (subarray [4, -1, 2, 1])
 *
 * At each position, decide: extend the current subarray or start fresh?
 * dp[i] = max(nums[i], dp[i-1] + nums[i])
 *
 * Time:  O(n)
 * Space: O(1)
 */
int maxSubArray(const vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

/*
 * Problem 5: Word Break
 * =====================
 * Given a string and a dictionary, determine if the string can be
 * segmented into dictionary words.
 *
 * Example: s = "leetcode", dict = ["leet", "code"]
 * Output: true
 *
 * dp[i] = true if s[0..i-1] can be broken into dictionary words
 *
 * Time:  O(n^2 * k) where k = avg word length for substr comparison
 * Space: O(n)
 */
bool wordBreak(const string& s, const vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;  // empty string is always valid

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

/*
 * Problem 6: Minimum Path Sum (Grid DP)
 * ======================================
 * Robot on a grid — move only right or down. Each cell has a cost.
 * Find the path from top-left to bottom-right with the smallest total cost.
 *
 * Example:
 *   1  3  1
 *   1  5  1
 *   4  2  1
 * Output: 7  (path: 1→3→1→1→1)
 *
 * "How did I get here?" → from above or from the left, pick the cheaper one
 *
 * Base cases: top row and left column can only be reached one way (accumulate)
 * Recurrence: dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
 *
 * Time:  O(m * n)
 * Space: O(m * n)
 */
int minCost(vector<vector<int>> const& grid) {
    int height = grid.size();
    int width = grid[0].size();

    vector<vector<int>> costGrid(height, vector<int>(width, 0));
    costGrid[0][0] = grid[0][0];

    // Base case: top row — can only come from the left
    for (int i = 1; i < width; i++) {
        costGrid[0][i] = grid[0][i] + costGrid[0][i - 1];
    }

    // Base case: left column — can only come from above
    for (int i = 1; i < height; i++) {
        costGrid[i][0] = grid[i][0] + costGrid[i - 1][0];
    }

    // Fill the rest: pick the cheaper path (above or left)
    for (int i = 1; i < height; i++) {
        for (int j = 1; j < width; j++) {
            costGrid[i][j] = grid[i][j] + min(costGrid[i - 1][j], costGrid[i][j - 1]);
        }
    }

    return costGrid[height - 1][width - 1];
}

int main() {
    // Climbing Stairs
    cout << "Climbing 5 stairs: " << climbStairs(5) << " ways" << endl;
    // Expected: 8

    // Coin Change
    vector<int> coins = {1, 5, 10, 25};
    cout << "Coin change for 30: " << coinChange(coins, 30) << " coins" << endl;
    // Expected: 2

    vector<int> coins2 = {2};
    cout << "Coin change for 3 with [2]: " << coinChange(coins2, 3) << endl;
    // Expected: -1

    // LCS
    cout << "LCS of 'abcde' and 'ace': "
         << longestCommonSubsequence("abcde", "ace") << endl;
    // Expected: 3

    // Max Subarray
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Max subarray sum: " << maxSubArray(nums) << endl;
    // Expected: 6

    // Word Break
    cout << "Word break 'leetcode': "
         << (wordBreak("leetcode", {"leet", "code"}) ? "true" : "false") << endl;
    // Expected: true
    cout << "Word break 'catsandog': "
         << (wordBreak("catsandog", {"cats","dog","sand","and","cat"}) ? "true" : "false") << endl;
    // Expected: false

    // Min Path Sum
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Min path sum: " << minCost(grid) << endl;
    // Expected: 7 (path: 1→3→1→1→1)

    return 0;
}
