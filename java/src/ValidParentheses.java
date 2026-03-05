import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

/**
 * LeetCode #20 - Valid Parentheses
 *
 * Given a string s containing just the characters
 * '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * A string is valid if:
 *   1. Open brackets are closed by the same type of brackets.
 *   2. Open brackets are closed in the correct order.
 *   3. Every close bracket has a corresponding open bracket.
 *
 * Example:
 *   Input: s = "()[]{}"   Output: true
 *   Input: s = "(]"       Output: false
 *   Input: s = "([)]"     Output: false
 *   Input: s = "{[]}"     Output: true
 *
 * C++ equivalent hints:
 *   - Stack is like std::stack
 *   - push() / pop() / peek() instead of push() / pop() / top()
 *   - s.charAt(i) instead of s[i]
 *   - s.length() for strings (with parentheses, unlike arrays)
 */
public class ValidParentheses {

    public static boolean isValid(String s) {
        HashMap<Character, Character> matches = new HashMap<>();
        matches.put(')', '(');
        matches.put(']', '[');
        matches.put('}', '{');

        Stack<Character> chars = new Stack();
        int len = s.length();
        int i = 0;
        while (i < len) {
            Character current = s.charAt(i);
            if (!chars.isEmpty() && chars.peek() == matches.get(current)) {
                chars.pop();
            } else {
                chars.push(current);
            }
            i++;
        }
        return chars.isEmpty();
    }

    public static void main(String[] args) {
        System.out.println("Test 1: " + isValid("()")); // Expected: true
        System.out.println("Test 2: " + isValid("()[]{}")); // Expected: true
        System.out.println("Test 3: " + isValid("(]")); // Expected: false
        System.out.println("Test 4: " + isValid("([)]")); // Expected: false
        System.out.println("Test 5: " + isValid("{[]}")); // Expected: true
        System.out.println("Test 6: " + isValid("")); // Expected: true
        System.out.println("Test 7: " + isValid("(")); // Expected: false
    }
}
