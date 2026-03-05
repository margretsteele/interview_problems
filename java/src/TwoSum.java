import java.util.Arrays;
import java.util.HashMap;

/**
 * LeetCode #1 - Two Sum
 *
 * Given an array of integers nums and an integer target,
 * return indices of the two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.
 *
 * Example:
 *   Input: nums = [2, 7, 11, 15], target = 9
 *   Output: [0, 1]  (because nums[0] + nums[1] == 9)
 *
 * C++ equivalent hint:
 *   - HashMap is like std::unordered_map
 *   - Arrays don't have .size(), use .length
 */
public class TwoSum {

    public static int[] twoSum(int[] nums, int target) {
        // TODO: implement this
        if (nums.length < 2) {
            return new int[] {};
        }

        HashMap<Integer, int[]> sums = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int sum = nums[i] + nums[j];
                if (sum == target) {
                    sums.put(target, new int[] { i, j });
                }
            }
        }

        return sums.get(target);
    }

    public static void main(String[] args) {
        // Test case 1
        int[] result1 = twoSum(new int[] { 2, 7, 11, 15 }, 9);
        System.out.println("Test 1: " + Arrays.toString(result1)); // Expected: [0, 1]

        // Test case 2
        int[] result2 = twoSum(new int[] { 3, 2, 4 }, 6);
        System.out.println("Test 2: " + Arrays.toString(result2)); // Expected: [1, 2]

        // Test case 3
        int[] result3 = twoSum(new int[] { 3, 3 }, 6);
        System.out.println("Test 3: " + Arrays.toString(result3)); // Expected: [0, 1]
    }
}
