#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*
 * Partition Equal Subset Sum
 * ==========================
 * Given a non-empty array of positive integers, determine if the array can be
 * partitioned into two subsets such that the sum of elements in both subsets
 * is equal.
 *
 * Examples:
 *   nums = [1, 5, 11, 5]  => true   (subsets: [1, 5, 5] and [11])
 *   nums = [1, 2, 3, 5]   => false  (no way to split into equal halves)
 *   nums = [3, 3, 3, 4, 5] => true  (subsets: [3, 3, 3] and [4, 5])
 *
 * Hint: This is a 0/1 knapsack problem in disguise. If the total sum is odd,
 *       it's impossible. Otherwise, can you find a subset that sums to
 *       totalSum / 2?
 *
 * Think about:
 *   - What does dp[j] represent?
 *   - Why does iteration order matter for 0/1 knapsack?
 *
 * Time:  O(n * target)
 * Space: O(target)
 */
bool canPartition(vector<int>& nums) {
    // Your code here
    int total = 0;
    for(auto val : nums) {
        total += val;
    }
    if(total % 2 != 0) return false;

    int target = total / 2;
    vector<bool> sumPossible(target + 1, false);
    sumPossible[0] = true;
    sumPossible[1] = false;

    for(int i = 0; i < nums.size(); i++) {
        for(int j = sumPossible.size() - 1; j >= 1; j--) {
            int remain = j - nums[i];
            bool possible = remain >= 0 ? sumPossible[remain] : false;
            if(possible) {
                sumPossible[j] = true;
            }
        }
    }

    return sumPossible[target];
}

int main() {
    vector<int> t1 = {1, 5, 11, 5};
    cout << "t1 [1,5,11,5]: " << (canPartition(t1) ? "true" : "false") << endl;
    // Expected: true  (subsets: {1,5,5} and {11})

    vector<int> t2 = {1, 2, 3, 5};
    cout << "t2 [1,2,3,5]: " << (canPartition(t2) ? "true" : "false") << endl;
    // Expected: false

    vector<int> t3 = {3, 3, 3, 4, 5};
    cout << "t3 [3,3,3,4,5]: " << (canPartition(t3) ? "true" : "false") << endl;
    // Expected: true  (subsets: {3,3,3} and {4,5})

    vector<int> t4 = {1, 1};
    cout << "t4 [1,1]: " << (canPartition(t4) ? "true" : "false") << endl;
    // Expected: true

    vector<int> t5 = {1, 2, 5};
    cout << "t5 [1,2,5]: " << (canPartition(t5) ? "true" : "false") << endl;
    // Expected: false

    vector<int> t6 = {2, 2, 1, 1};
    cout << "t6 [2,2,1,1]: " << (canPartition(t6) ? "true" : "false") << endl;
    // Expected: true  (subsets: {2,1} and {2,1})

    vector<int> t7 = {100};
    cout << "t7 [100]: " << (canPartition(t7) ? "true" : "false") << endl;
    // Expected: false  (single element, can't split)

    return 0;
}
