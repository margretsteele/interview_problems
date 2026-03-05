/**
 * LeetCode #21 - Merge Two Sorted Linked Lists
 *
 * Merge two sorted linked lists and return it as a sorted list.
 * The list should be made by splicing together the nodes of the two lists.
 *
 * Example:
 *   Input:  1 -> 2 -> 4
 *           1 -> 3 -> 4
 *   Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4
 *
 * C++ equivalent hints:
 *   - No pointers! Use object references instead (null instead of nullptr)
 *   - node.next instead of node->next
 *   - node.val instead of node->val
 *   - new ListNode(val) instead of new ListNode(val) (same, but no delete needed)
 */
public class MergeSortedLists {

    static class ListNode {

        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
            this.next = null;
        }
    }

    public static ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode root = new ListNode(0);
        ListNode current = root;
        // TODO: implement this
        while (list1 != null || list2 != null) {
            if (list1.val <= list2.val) {
                //root.append(list1.val);
                list1 = list1.next;
            } else {
                //root.append(list2.val);
                list2 = list2.next;
            }
        }
        return root.next;
    }

    // Helper: build a linked list from an array
    private static ListNode buildList(int[] values) {
        if (values.length == 0) return null;
        ListNode head = new ListNode(values[0]);
        ListNode current = head;
        for (int i = 1; i < values.length; i++) {
            current.next = new ListNode(values[i]);
            current = current.next;
        }
        return head;
    }

    // Helper: print a linked list
    private static String listToString(ListNode head) {
        StringBuilder sb = new StringBuilder();
        while (head != null) {
            sb.append(head.val);
            if (head.next != null) sb.append(" -> ");
            head = head.next;
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        // Test 1: [1,2,4] + [1,3,4] = [1,1,2,3,4,4]
        ListNode result1 = mergeTwoLists(
            buildList(new int[] { 1, 2, 4 }),
            buildList(new int[] { 1, 3, 4 })
        );
        System.out.println("Test 1: " + listToString(result1)); // Expected: 1 -> 1 -> 2 -> 3 -> 4 -> 4

        // Test 2: [] + [] = []
        ListNode result2 = mergeTwoLists(null, null);
        System.out.println("Test 2: " + listToString(result2)); // Expected: (empty)

        // Test 3: [] + [0] = [0]
        ListNode result3 = mergeTwoLists(null, buildList(new int[] { 0 }));
        System.out.println("Test 3: " + listToString(result3)); // Expected: 0

        // Test 4: [5] + [1,2,3] = [1,2,3,5]
        ListNode result4 = mergeTwoLists(
            buildList(new int[] { 5 }),
            buildList(new int[] { 1, 2, 3 })
        );
        System.out.println("Test 4: " + listToString(result4)); // Expected: 1 -> 2 -> 3 -> 5
    }
}
