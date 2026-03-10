/*
 * Two Sum (Hash Map Pattern)
 * ==========================
 * Amazon favorite - tests hash map usage and array traversal.
 *
 * Problem: Given an array of integers and a target sum, return the indices
 * of the two numbers that add up to the target.
 * Assume exactly one solution exists and you can't use the same element twice.
 *
 * Example:
 *   nums = [2, 7, 11, 15], target = 9
 *   Output: [0, 1]  (because nums[0] + nums[1] = 2 + 7 = 9)
 *
 * Key insight: For each number, check if (target - number) already exists
 * in our hash map. This turns an O(n^2) brute force into O(n).
 *
 * Time:  O(n)
 * Space: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> seen;  // value -> index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (seen.count(complement)) {
            return {seen[complement], i};
        }

        seen[nums[i]] = i;
    }

    return {};  // no solution found
}

/*
 * Follow-up: Two Sum II - Input Array Is Sorted
 * ==============================================
 * If the array is already sorted, use two pointers instead of a hash map.
 * This gives O(1) space.
 */
vector<int> twoSumSorted(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) {
            return {left, right};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return {};
}

/*
 * Follow-up: Three Sum
 * ====================
 * Find all unique triplets that sum to zero.
 * Sort + fix one element + two pointer scan = O(n^2).
 * Very commonly asked at Amazon.
 */
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < (int)nums.size() - 2; i++) {
        // skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1, right = nums.size() - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                // skip duplicates
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

int main() {
    // Two Sum
    vector<int> nums = {2, 7, 11, 15};
    auto result = twoSum(nums, 9);
    cout << "Two Sum [2,7,11,15] target=9: [" << result[0] << ", " << result[1] << "]" << endl;

    // Two Sum Sorted
    vector<int> sorted = {1, 3, 5, 7, 9};
    auto result2 = twoSumSorted(sorted, 8);
    cout << "Two Sum Sorted [1,3,5,7,9] target=8: [" << result2[0] << ", " << result2[1] << "]" << endl;

    // Three Sum
    vector<int> nums3 = {-1, 0, 1, 2, -1, -4};
    auto result3 = threeSum(nums3);
    cout << "Three Sum [-1,0,1,2,-1,-4]:" << endl;
    for (auto& triplet : result3) {
        cout << "  [" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }

    return 0;
}
