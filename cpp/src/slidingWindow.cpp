/*
 * Sliding Window Problems
 * =======================
 * One of the most common patterns at Amazon. Learn to recognize when
 * a problem involves a contiguous subarray/substring and can be solved
 * by expanding/shrinking a window.
 *
 * Two flavors:
 *   1. Fixed-size window (easy) - window size is given
 *   2. Variable-size window (medium) - find optimal window size
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
 * Problem 1: Maximum Sum Subarray of Size K (Fixed Window)
 * ========================================================
 * Given an array and integer k, find the maximum sum of any
 * contiguous subarray of size k.
 *
 * Example: nums = [2, 1, 5, 1, 3, 2], k = 3
 * Output: 9  (subarray [5, 1, 3])
 *
 * Time:  O(n)
 * Space: O(1)
 */
int maxSumSubarray(const vector<int>& nums, int k) {
    int windowSum = 0;
    int maxSum = 0;

    for (int i = 0; i < nums.size(); i++) {
        windowSum += nums[i];

        // once we've hit window size, start sliding
        if (i >= k) {
            windowSum -= nums[i - k];  // remove element leaving the window
        }

        if (i >= k - 1) {
            maxSum = max(maxSum, windowSum);
        }
    }

    return maxSum;
}

/*
 * Problem 2: Longest Substring Without Repeating Characters (Variable Window)
 * ===========================================================================
 * Given a string, find the length of the longest substring without
 * repeating characters.
 *
 * Example: s = "abcabcbb"
 * Output: 3  ("abc")
 *
 * Key insight: Expand the window by moving right pointer. When a duplicate
 * is found, shrink from the left until no duplicates remain.
 *
 * Time:  O(n)
 * Space: O(min(n, alphabet_size))
 */
int lengthOfLongestSubstring(const string& s) {
    unordered_map<char, int> lastSeen;  // char -> most recent index
    int maxLen = 0;
    int left = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];

        // if we've seen this char and it's within our current window, shrink
        if (lastSeen.count(c) && lastSeen[c] >= left) {
            left = lastSeen[c] + 1;
        }

        lastSeen[c] = right;
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

/*
 * Problem 3: Minimum Window Substring (Hard - Amazon loves this one)
 * ==================================================================
 * Given strings s and t, find the minimum window in s that contains
 * all characters of t (including duplicates).
 *
 * Example: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 *
 * Strategy: Expand right to include all chars of t, then shrink left
 * to find the minimum valid window.
 *
 * Time:  O(n + m)
 * Space: O(m) where m = |t|
 */
string minWindow(const string& s, const string& t) {
    if (t.size() > s.size()) return "";

    unordered_map<char, int> need;  // chars we need and their counts
    for (char c : t) need[c]++;

    int have = 0;           // how many unique chars we've satisfied
    int required = need.size();  // how many unique chars we need
    int left = 0;
    int minLen = INT_MAX;
    int minStart = 0;

    unordered_map<char, int> window;  // chars in our current window

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        window[c]++;

        // check if this char's count is now satisfied
        if (need.count(c) && window[c] == need[c]) {
            have++;
        }

        // try to shrink the window while it's still valid
        while (have == required) {
            int windowLen = right - left + 1;
            if (windowLen < minLen) {
                minLen = windowLen;
                minStart = left;
            }

            char leftChar = s[left];
            window[leftChar]--;
            if (need.count(leftChar) && window[leftChar] < need[leftChar]) {
                have--;
            }
            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

int main() {
    // Problem 1: Max sum subarray
    vector<int> nums = {2, 1, 5, 1, 3, 2};
    cout << "Max sum subarray of size 3: " << maxSumSubarray(nums, 3) << endl;
    // Expected: 9

    // Problem 2: Longest substring without repeating
    cout << "Longest substring 'abcabcbb': " << lengthOfLongestSubstring("abcabcbb") << endl;
    // Expected: 3
    cout << "Longest substring 'bbbbb': " << lengthOfLongestSubstring("bbbbb") << endl;
    // Expected: 1
    cout << "Longest substring 'pwwkew': " << lengthOfLongestSubstring("pwwkew") << endl;
    // Expected: 3

    // Problem 3: Minimum window substring
    cout << "Min window 'ADOBECODEBANC' containing 'ABC': "
         << minWindow("ADOBECODEBANC", "ABC") << endl;
    // Expected: "BANC"

    return 0;
}
