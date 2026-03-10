/*
 * Heaps & Priority Queues
 * =======================
 * C++ gives you priority_queue from <queue>:
 *   priority_queue<int> maxHeap;
 *   priority_queue<int, vector<int>, greater<int>> minHeap;
 *
 * Think about: when do you need quick access to the min or max element
 * while the rest of the collection keeps changing?
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

/*
 * Problem 1: Kth Largest Element in an Array (LC 215)
 * ---------------------------------------------------
 * Given an integer array and an integer k, return the kth largest element.
 * Note: it is the kth largest in sorted order, not the kth distinct element.
 *
 * Examples:
 *   nums = [3,2,1,5,6,4], k = 2  =>  5
 * 1 2 3 4 5 6
 *   nums = [3,2,3,1,2,4,5,5,6], k = 4  =>  4
 *
 * Hint: What size heap do you need? Do you want a min or max heap?
 *
 * Time:  O(n log k)
 * Space: O(k)
 */
int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int location = nums.size() - k;
    if(location < 0) return -1;
    return nums[location];
}

/*
 * Problem 2: Top K Frequent Elements (LC 347)
 * --------------------------------------------
 * Given an integer array and an integer k, return the k most frequent elements.
 * You may return the answer in any order.
 *
 * Examples:
 *   nums = [1,1,1,2,2,3], k = 2  =>  [1,2]
 *   nums = [1], k = 1  =>  [1]
 *   nums = [4,4,4,2,2,2,3,3,1], k = 2  =>  [4,2] (or [2,4])
 *
 * Hint: First count frequencies. Then think about which heap type
 * lets you efficiently keep only the top k.
 *
 * Time:  O(n log k)
 * Space: O(n)
 */
vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int,int> frequencies;
    for(int i = 0; i < nums.size(); i++) {
        frequencies[nums[i]]++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
    for(auto freq : frequencies) {
        heap.push({freq.second, freq.first});
        if(heap.size() > k) heap.pop();
    }
    vector<int> result;
    while(!heap.empty()) {
        result.push_back(heap.top().second);
        heap.pop();
    }
    return result;
}

/*
 * Problem 3: Merge K Sorted Lists (LC 23)
 * ----------------------------------------
 * You are given k sorted linked lists. Merge them into one sorted list.
 *
 * Using vectors here instead of ListNodes for simplicity.
 * Each inner vector is already sorted in ascending order.
 *
 * Examples:
 *   lists = [[1,4,5],[1,3,4],[2,6]]  =>  [1,1,2,3,4,4,5,6]
 *   lists = []  =>  []
 *   lists = [[]]  =>  []
 *
 * Hint: You need to track which list each element came from and
 * where you are in that list. What goes into the heap?
 *
 * Time:  O(N log k), where N = total elements across all lists
 * Space: O(k)
 */
vector<int> mergeKSorted(vector<vector<int>>& lists) {
    // Your code here
    return {};
}

/*
 * Problem 4: Find Median from Data Stream (LC 295)
 * -------------------------------------------------
 * Design a data structure that supports:
 *   addNum(int num) - add an integer from the stream
 *   findMedian()    - return the median of all elements so far
 *
 * Examples:
 *   addNum(1), addNum(2) => findMedian() = 1.5
 *   addNum(3) => findMedian() = 2.0
 *
 * Hint: Can you maintain two heaps that split the data into
 * a lower half and an upper half? What type is each heap?
 *
 * Time:  O(log n) add, O(1) find
 * Space: O(n)
 */
class MedianFinder {
public:
    // Your member variables here

    void addNum(int num) {
        // Your code here
    }

    double findMedian() {
        // Your code here
        return 0.0;
    }
};

int main() {
    // --- Test Kth Largest ---
    cout << "=== Kth Largest ===" << endl;
    vector<int> k1 = {3, 2, 1, 5, 6, 4};
    cout << "t1: " << findKthLargest(k1, 2) << " (expected 5)" << endl;

    vector<int> k2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << "t2: " << findKthLargest(k2, 4) << " (expected 4)" << endl;

    vector<int> k3 = {1};
    cout << "t3: " << findKthLargest(k3, 1) << " (expected 1)" << endl;

    vector<int> k4 = {7, 7, 7, 7};
    cout << "t4: " << findKthLargest(k4, 2) << " (expected 7)" << endl;

    // --- Test Top K Frequent ---
    cout << "\n=== Top K Frequent ===" << endl;
    auto printVec = [](const vector<int>& v) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i < v.size() - 1) cout << ",";
        }
        cout << "]";
    };

    vector<int> f1 = {1, 1, 1, 2, 2, 3};
    cout << "t1: "; printVec(topKFrequent(f1, 2)); cout << " (expected [1,2])" << endl;

    vector<int> f2 = {1};
    cout << "t2: "; printVec(topKFrequent(f2, 1)); cout << " (expected [1])" << endl;

    vector<int> f3 = {4, 4, 4, 2, 2, 2, 3, 3, 1};
    cout << "t3: "; printVec(topKFrequent(f3, 2)); cout << " (expected [4,2] or [2,4])" << endl;

    // --- Test Merge K Sorted ---
    cout << "\n=== Merge K Sorted ===" << endl;
    vector<vector<int>> m1 = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    cout << "t1: "; printVec(mergeKSorted(m1)); cout << " (expected [1,1,2,3,4,4,5,6])" << endl;

    vector<vector<int>> m2 = {};
    cout << "t2: "; printVec(mergeKSorted(m2)); cout << " (expected [])" << endl;

    vector<vector<int>> m3 = {{5}, {1, 3}, {2, 4, 6}};
    cout << "t3: "; printVec(mergeKSorted(m3)); cout << " (expected [1,2,3,4,5,6])" << endl;

    // --- Test Median Finder ---
    cout << "\n=== Median Finder ===" << endl;
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "t1: " << mf.findMedian() << " (expected 1.5)" << endl;
    mf.addNum(3);
    cout << "t2: " << mf.findMedian() << " (expected 2)" << endl;

    MedianFinder mf2;
    mf2.addNum(6);
    mf2.addNum(10);
    mf2.addNum(2);
    mf2.addNum(6);
    cout << "t3: " << mf2.findMedian() << " (expected 6)" << endl;
    mf2.addNum(5);
    cout << "t4: " << mf2.findMedian() << " (expected 6)" << endl;

    return 0;
}
