/*
 * Shortest Path in Binary Matrix (LeetCode 1091)
 *
 * Given an n x n binary grid, find the length of the shortest clear path
 * from top-left (0,0) to bottom-right (n-1, n-1).
 *
 * - A clear path only goes through cells with value 0
 * - You can move in 8 directions (up, down, left, right, and 4 diagonals)
 * - Path length = number of cells visited
 * - Return -1 if no path exists
 *
 * Example 1:
 *   0 0 0
 *   1 1 0
 *   1 1 0
 *   Output: 4  (path: (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2))
 *
 * Example 2:
 *   0 1
 *   1 0
 *   Output: -1
 *
 * Key insight: BFS guarantees shortest path in an unweighted graph.
 *
 * Time:  O(n^2)
 * Space: O(n^2)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int shortestPath(vector<vector<int>> grid) {
    int height = grid.size();
    int width = grid[0].size();
    if(height == 0 || width == 0 || grid[0][0] == 1) return -1;

    //x,y,distance to get there
    queue<tuple<int,int,int>> neighbors;

    neighbors.push(make_tuple(0,0,1));
    while(!neighbors.empty()) {
        auto [x,y,cost] = neighbors.front();
        neighbors.pop();
        if(x == height -1  && y == width - 1) return cost;
        grid[x][y] = 1;

        if(x+1 < height && grid[x+1][y] == 0) {
            neighbors.push(make_tuple(x+1,y,cost+1));
        }
        if(y + 1 < width && grid[x][y+1] == 0) {
            neighbors.push(make_tuple(x,y+1,cost+1));
        }
        if(x - 1 >= 0 && grid[x-1][y] == 0) {
            neighbors.push(make_tuple(x-1,y,cost+1));
        }
        if(y -1 >= 0 && grid[x][y-1] == 0) {
            neighbors.push(make_tuple(x,y-1,cost+1));
        }

        if(x+1 < height &&  y+1 < width && grid[x+1][y+1] == 0) {
            neighbors.push(make_tuple(x+1,y+1,cost+1));
        }
        if(x+1 < height &&  y-1 >= 0 && grid[x+1][y-1] == 0) {
            neighbors.push(make_tuple(x+1,y-1,cost+1));
        }
        if(x-1 >= 0 &&  y+1 < width && grid[x-1][y+1] == 0) {
            neighbors.push(make_tuple(x-1,y+1,cost+1));
        }
        if(x-1 >= 0 &&  y-1 >= 0 && grid[x-1][y-1] == 0) {
            neighbors.push(make_tuple(x-1,y-1,cost+1));
        }
    }
    return -1;
}

int main() {
    // Test 1: path exists
    vector<vector<int>> grid1 = {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };
    cout << "Test 1: " << shortestPath(grid1) << " (expected 4)" << endl;

    // Test 2: no path
    vector<vector<int>> grid2 = {
        {0, 1},
        {1, 0}
    };
    cout << "Test 2: " << shortestPath(grid2) << " (expected 2)" << endl;

    // Test 3: single cell
    vector<vector<int>> grid3 = {{0}};
    cout << "Test 3: " << shortestPath(grid3) << " (expected 1)" << endl;

    // Test 4: start is blocked
    vector<vector<int>> grid4 = {
        {1, 0},
        {0, 0}
    };
    cout << "Test 4: " << shortestPath(grid4) << " (expected -1)" << endl;

    return 0;
}
