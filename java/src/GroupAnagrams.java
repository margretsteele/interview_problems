import java.util.*;

/**
 * LeetCode #49 - Group Anagrams
 *
 * Given an array of strings, group the anagrams together.
 * You can return the answer in any order.
 *
 * Example:
 *   Input:  ["eat","tea","tan","ate","nat","bat"]
 *   Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * This is a real-world pattern — grouping/categorizing data by a computed key.
 * Think: grouping records by a normalized identifier.
 *
 * Java things you'll use:
 *   - HashMap<String, List<String>>
 *   - Arrays.sort(char[])
 *   - String.toCharArray() / new String(char[])
 *   - map.computeIfAbsent(key, k -> new ArrayList<>())
 *   - new ArrayList<>(map.values())
 */
public class GroupAnagrams {

    public static List<List<String>> groupAnagrams(String[] strs) {
        // TODO: implement this
        return new ArrayList<>();
    }

    public static void main(String[] args) {
        // Test 1
        String[] input1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
        System.out.println("Test 1: " + groupAnagrams(input1));
        // Expected: [[bat], [nat, tan], [ate, eat, tea]] (order may vary)

        // Test 2
        String[] input2 = {""};
        System.out.println("Test 2: " + groupAnagrams(input2));
        // Expected: [[]]

        // Test 3
        String[] input3 = {"a"};
        System.out.println("Test 3: " + groupAnagrams(input3));
        // Expected: [[a]]

        // Test 4
        String[] input4 = {"abc", "bca", "cab", "xyz", "zyx", "yxz"};
        System.out.println("Test 4: " + groupAnagrams(input4));
        // Expected: [[abc, bca, cab], [xyz, zyx, yxz]] (order may vary)
    }
}
