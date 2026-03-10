#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Combination Sum II
 * ==================
 * Given a collection of candidate numbers and a target, find all unique
 * combinations where the chosen numbers sum to the target.
 * Each number may only be used ONCE. The solution set must not contain
 * duplicate combinations.
 *
 * Examples:
 *   candidates = [10,1,2,7,6,1,5], target = 8
 *   Output: [[1,1,6], [1,2,5], [1,7], [2,6]]
 *
 *   candidates = [2,5,2,1,2], target = 5
 *   Output: [[1,2,2], [5]]
 *
 * Approach: Sort the array first, then use backtracking.
 * At each step you choose whether to include a candidate or skip it.
 * Think about:
 *   - How do you avoid duplicate combinations?
 *   - When do you stop exploring a branch early (pruning)?
 *   - What do you do after a recursive call returns (backtrack step)?
 *
 * Time:  O(2^n) worst case
 * Space: O(n) recursion depth
 */

void updateResults(vector<int> const& candidates,
                    int target,
                    vector<vector<int>>& results,
                    vector<int>& currentPath,
                    int startIndex) {
    if(target == 0) {
        results.push_back(currentPath);
        return;
    }
    for(int i = startIndex; i < candidates.size(); i++) {
        if(candidates[i] == candidates[i-1] && i > startIndex) continue;
        if(target - candidates[i] >= 0) {
            currentPath.push_back(candidates[i]);
            updateResults(candidates, target - candidates[i], results, currentPath, i + 1);
            currentPath.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> results;
    vector<int> currentPath;
    sort(candidates.begin(), candidates.end());
    updateResults(candidates, target, results, currentPath, 0);
    // Your code here
    return results;
}

int main() {
    // Helper to print results
    auto print = [](const vector<vector<int>>& results) {
        cout << "[";
        for (int i = 0; i < results.size(); i++) {
            cout << "[";
            for (int j = 0; j < results[i].size(); j++) {
                cout << results[i][j];
                if (j < results[i].size() - 1) cout << ",";
            }
            cout << "]";
            if (i < results.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    };

    vector<int> c1 = {10, 1, 2, 7, 6, 1, 5};
    cout << "t1: ";
    print(combinationSum(c1, 8));
    // Expected: [[1,1,6], [1,2,5], [1,7], [2,6]]

    vector<int> c2 = {2, 5, 2, 1, 2};
    cout << "t2: ";
    print(combinationSum(c2, 5));
    // Expected: [[1,2,2], [5]]

    vector<int> c3 = {1, 1, 1, 1};
    cout << "t3: ";
    print(combinationSum(c3, 2));
    // Expected: [[1,1]]

    vector<int> c4 = {3, 7};
    cout << "t4: ";
    print(combinationSum(c4, 5));
    // Expected: []  (no combination works)

    vector<int> c5 = {1, 2, 3};
    cout << "t5: ";
    print(combinationSum(c5, 6));
    // Expected: [[1,2,3]]

    vector<int> c6 = {1};
    cout << "t6: ";
    print(combinationSum(c6, 1));
    // Expected: [[1]]

    return 0;
}
