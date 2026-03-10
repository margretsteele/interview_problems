/*
 * Interval Problems
 * =================
 * Common pattern: sort by start time, then process intervals
 * in order, tracking overlaps or merging as you go.
 *
 * These come up constantly for scheduling, resource allocation,
 * and robotics motion planning questions.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Problem 1: Merge Intervals (LC 56)
 * -----------------------------------
 * Given an array of intervals where intervals[i] = [start, end],
 * merge all overlapping intervals.
 *
 * Examples:
 *   [[1,3],[2,6],[8,10],[15,18]]  =>  [[1,6],[8,10],[15,18]]
 *   [[1,4],[4,5]]  =>  [[1,5]]
 *   [[1,4],[0,4]]  =>  [[0,4]]
 *
 * Hint: Sort first. Then what condition tells you two intervals overlap?
 *
 * Time:  O(n log n)
 * Space: O(n)
 */
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    // Your code here
    return {};
}

/*
 * Problem 2: Insert Interval (LC 57)
 * -----------------------------------
 * Given a set of NON-overlapping intervals sorted by start time,
 * insert a new interval, merging if necessary.
 *
 * Examples:
 *   intervals = [[1,3],[6,9]], newInterval = [2,5]  =>  [[1,5],[6,9]]
 *   intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 *       =>  [[1,2],[3,10],[12,16]]
 *   intervals = [], newInterval = [5,7]  =>  [[5,7]]
 *
 * Hint: Three phases — intervals fully before, intervals that overlap,
 * intervals fully after.
 *
 * Time:  O(n)
 * Space: O(n)
 */
vector<vector<int>> insertInterval(vector<vector<int>>& intervals,
                                    vector<int>& newInterval) {
    // Your code here
    return {};
}

/*
 * Problem 3: Meeting Rooms II (LC 253)
 * -------------------------------------
 * Given an array of meeting time intervals, find the minimum number
 * of conference rooms required.
 *
 * Examples:
 *   [[0,30],[5,10],[15,20]]  =>  2
 *   [[7,10],[2,4]]  =>  1
 *   [[1,5],[2,6],[3,7],[4,8]]  =>  4
 *   [[1,3],[3,5]]  =>  1  (end == start means no overlap)
 *
 * Hint: Think about what matters — when meetings start and when
 * they end. You can decouple these events. Or think about a sweep line.
 *
 * Time:  O(n log n)
 * Space: O(n)
 */
int minMeetingRooms(vector<vector<int>>& intervals) {
    // Your code here
    return 0;
}

/*
 * Problem 4: Non-Overlapping Intervals (LC 435)
 * -----------------------------------------------
 * Given an array of intervals, find the minimum number of intervals
 * you need to REMOVE to make the rest non-overlapping.
 *
 * Examples:
 *   [[1,2],[2,3],[3,4],[1,3]]  =>  1  (remove [1,3])
 *   [[1,2],[1,2],[1,2]]  =>  2
 *   [[1,2],[2,3]]  =>  0
 *
 * Hint: Greedy approach. Sort by end time. When two intervals overlap,
 * which one is better to keep — the one that ends earlier or later?
 *
 * Time:  O(n log n)
 * Space: O(1)
 */
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // Your code here
    return 0;
}

int main() {
    auto printIntervals = [](const vector<vector<int>>& iv) {
        cout << "[";
        for (int i = 0; i < iv.size(); i++) {
            cout << "[" << iv[i][0] << "," << iv[i][1] << "]";
            if (i < iv.size() - 1) cout << ",";
        }
        cout << "]";
    };

    // --- Test Merge Intervals ---
    cout << "=== Merge Intervals ===" << endl;
    vector<vector<int>> mi1 = {{1,3},{2,6},{8,10},{15,18}};
    cout << "t1: "; printIntervals(mergeIntervals(mi1));
    cout << " (expected [[1,6],[8,10],[15,18]])" << endl;

    vector<vector<int>> mi2 = {{1,4},{4,5}};
    cout << "t2: "; printIntervals(mergeIntervals(mi2));
    cout << " (expected [[1,5]])" << endl;

    vector<vector<int>> mi3 = {{1,4},{0,4}};
    cout << "t3: "; printIntervals(mergeIntervals(mi3));
    cout << " (expected [[0,4]])" << endl;

    vector<vector<int>> mi4 = {{1,4},{2,3}};
    cout << "t4: "; printIntervals(mergeIntervals(mi4));
    cout << " (expected [[1,4]])" << endl;

    // --- Test Insert Interval ---
    cout << "\n=== Insert Interval ===" << endl;
    vector<vector<int>> ii1 = {{1,3},{6,9}};
    vector<int> ni1 = {2,5};
    cout << "t1: "; printIntervals(insertInterval(ii1, ni1));
    cout << " (expected [[1,5],[6,9]])" << endl;

    vector<vector<int>> ii2 = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> ni2 = {4,8};
    cout << "t2: "; printIntervals(insertInterval(ii2, ni2));
    cout << " (expected [[1,2],[3,10],[12,16]])" << endl;

    vector<vector<int>> ii3 = {};
    vector<int> ni3 = {5,7};
    cout << "t3: "; printIntervals(insertInterval(ii3, ni3));
    cout << " (expected [[5,7]])" << endl;

    // --- Test Meeting Rooms II ---
    cout << "\n=== Meeting Rooms II ===" << endl;
    vector<vector<int>> mr1 = {{0,30},{5,10},{15,20}};
    cout << "t1: " << minMeetingRooms(mr1) << " (expected 2)" << endl;

    vector<vector<int>> mr2 = {{7,10},{2,4}};
    cout << "t2: " << minMeetingRooms(mr2) << " (expected 1)" << endl;

    vector<vector<int>> mr3 = {{1,5},{2,6},{3,7},{4,8}};
    cout << "t3: " << minMeetingRooms(mr3) << " (expected 4)" << endl;

    vector<vector<int>> mr4 = {{1,3},{3,5}};
    cout << "t4: " << minMeetingRooms(mr4) << " (expected 1)" << endl;

    // --- Test Non-Overlapping Intervals ---
    cout << "\n=== Non-Overlapping Intervals ===" << endl;
    vector<vector<int>> no1 = {{1,2},{2,3},{3,4},{1,3}};
    cout << "t1: " << eraseOverlapIntervals(no1) << " (expected 1)" << endl;

    vector<vector<int>> no2 = {{1,2},{1,2},{1,2}};
    cout << "t2: " << eraseOverlapIntervals(no2) << " (expected 2)" << endl;

    vector<vector<int>> no3 = {{1,2},{2,3}};
    cout << "t3: " << eraseOverlapIntervals(no3) << " (expected 0)" << endl;

    return 0;
}
