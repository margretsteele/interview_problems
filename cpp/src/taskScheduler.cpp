/*
 * Task Scheduler (LeetCode 621)
 *
 * Given a list of tasks represented by characters and a cooldown period n,
 * find the minimum number of intervals the robot needs to finish all tasks.
 *
 * - Each task takes 1 interval to execute
 * - There must be at least n intervals between two identical tasks
 * - The robot can idle or run a different task during cooldown
 *
 * Example 1:
 *   tasks = ['A','A','A','B','B','B'], n = 2
 *   Output: 8  (e.g. A B _ A B _ A B)
 *
 * Example 2:
 *   tasks = ['A','A','A','A','B','B','B','C','C'], n = 2
 *   Output: 10
 *
 * Example 3:
 *   tasks = ['A','A','A','B','B','B'], n = 0
 *   Output: 6
 *
 * Time:  O(n)
 * Space: O(1)  (at most 26 distinct tasks)
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> frequency;
    for(auto value : tasks) {
        frequency[value]++;
    }
    int maxFreq = -1;
    int numWithMax = 0;
    for(auto freq : frequency) {
        if(freq.second > maxFreq) {
            numWithMax = 1;
            maxFreq = freq.second;
        } else if(freq.second == maxFreq) {
            numWithMax++;
        }
    }
    return max((int)tasks.size(), (maxFreq - 1) * (n + 1) + numWithMax);
}

int main() {
    vector<char> t1 = {'A','A','A','B','B','B'};
    cout << "Test 1: " << leastInterval(t1, 2) << " (expected 8)" << endl;

    vector<char> t2 = {'A','A','A','A','B','B','B','C','C'};
    cout << "Test 2: " << leastInterval(t2, 2) << " (expected 10)" << endl;

    vector<char> t3 = {'A','A','A','B','B','B'};
    cout << "Test 3: " << leastInterval(t3, 0) << " (expected 6)" << endl;

    vector<char> t4 = {'A'};
    cout << "Test 4: " << leastInterval(t4, 2) << " (expected 1)" << endl;

    vector<char> t5 = {'A','A','A','A','B','B','B','C','C','D'};
    cout << "Test 5: " << leastInterval(t5, 2) << " (expected 10)" << endl;

    return 0;
}
