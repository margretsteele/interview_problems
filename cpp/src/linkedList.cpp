/*
 * Linked List Problems
 * ====================
 * Amazon asks these frequently. Master the pointer manipulation patterns.
 *
 * Common tricks:
 *   - Dummy head node to simplify edge cases
 *   - Two pointers (fast/slow) for cycle detection and finding midpoints
 *   - Reverse by rewiring next pointers
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

/*
 * Problem 1: Reverse a Linked List
 * ================================
 * The most fundamental linked list operation. You MUST know this cold.
 *
 * Time:  O(n)
 * Space: O(1)
 */
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr) {
        ListNode* next = curr->next;  // save next
        curr->next = prev;            // reverse the link
        prev = curr;                  // advance prev
        curr = next;                  // advance curr
    }

    return prev;  // prev is the new head
}

/*
 * Problem 2: Detect Cycle (Floyd's Algorithm)
 * ============================================
 * Determine if a linked list has a cycle.
 * Slow pointer moves 1 step, fast moves 2. If they meet, there's a cycle.
 *
 * Time:  O(n)
 * Space: O(1)
 */
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}

/*
 * Follow-up: Find where the cycle starts
 * After slow and fast meet, reset one pointer to head.
 * Move both one step at a time - they meet at the cycle start.
 */
ListNode* detectCycleStart(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // found the cycle - now find the start
            ListNode* entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }

    return nullptr;  // no cycle
}

/*
 * Problem 3: Merge Two Sorted Lists
 * ==================================
 * Merge two sorted linked lists into one sorted list.
 * Uses a dummy head to simplify the logic.
 *
 * Time:  O(n + m)
 * Space: O(1) - we reuse existing nodes
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;  // attach remaining nodes

    return dummy.next;
}

/*
 * Problem 4: Find Middle of Linked List
 * ======================================
 * Slow/fast pointer - when fast reaches the end, slow is at the middle.
 *
 * Time:  O(n)
 * Space: O(1)
 */
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

/*
 * Problem 5: Remove Nth Node From End
 * ====================================
 * Use two pointers separated by n nodes. When the leader hits the end,
 * the follower is right before the node to remove.
 *
 * Time:  O(n) - single pass!
 * Space: O(1)
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* leader = &dummy;
    ListNode* follower = &dummy;

    // advance leader n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        leader = leader->next;
    }

    // move both until leader hits the end
    while (leader) {
        leader = leader->next;
        follower = follower->next;
    }

    // skip the target node
    ListNode* toDelete = follower->next;
    follower->next = follower->next->next;
    delete toDelete;

    return dummy.next;
}

// ============ Helpers ============

ListNode* createList(initializer_list<int> vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

void freeList(ListNode* head) {
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    // Reverse
    ListNode* list1 = createList({1, 2, 3, 4, 5});
    cout << "Original:  "; printList(list1);
    list1 = reverseList(list1);
    cout << "Reversed:  "; printList(list1);
    freeList(list1);

    // Cycle detection
    ListNode* list2 = createList({1, 2, 3, 4});
    cout << "Has cycle: " << (hasCycle(list2) ? "yes" : "no") << endl;
    // create a cycle: 4 -> 2
    list2->next->next->next->next = list2->next;
    cout << "Has cycle: " << (hasCycle(list2) ? "yes" : "no") << endl;
    ListNode* cycleStart = detectCycleStart(list2);
    cout << "Cycle starts at: " << cycleStart->val << endl;
    // break cycle before freeing
    list2->next->next->next->next = nullptr;
    freeList(list2);

    // Merge sorted lists
    ListNode* a = createList({1, 3, 5});
    ListNode* b = createList({2, 4, 6});
    cout << "Merged:    "; printList(mergeTwoLists(a, b));

    // Middle
    ListNode* list3 = createList({1, 2, 3, 4, 5});
    cout << "Middle of [1,2,3,4,5]: " << findMiddle(list3)->val << endl;
    freeList(list3);

    // Remove Nth from end
    ListNode* list4 = createList({1, 2, 3, 4, 5});
    cout << "Remove 2nd from end: ";
    list4 = removeNthFromEnd(list4, 2);
    printList(list4);  // 1 -> 2 -> 3 -> 5
    freeList(list4);

    return 0;
}
