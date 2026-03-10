/*
 * Number of Islands (LeetCode 200)
 *
 * Given a 2D grid of '1's (land) and '0's (water), count the number
 * of islands. An island is surrounded by water and is formed by
 * connecting adjacent lands horizontally or vertically.
 *
 * Example:
 *   1 1 0 0 0
 *   1 1 0 0 0
 *   0 0 1 0 0
 *   0 0 0 1 1
 *   Output: 3
 *
 * Time:  O(rows * cols)
 * Space: O(rows * cols) worst case for queue
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    int numIslands = 0;
    int height = grid.size();
    int width = grid[0].size();
    queue<pair<int,int>> visit;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            bool isIsland = (grid[i][j] == '1');
            if(isIsland) {
                grid[i][j] = '0';
                numIslands++;
                visit.push(make_pair(i,j));
                while(!visit.empty()) {
                    auto [x, y] = visit.front();
                    visit.pop();
                    if(y + 1 < width && grid[x][y+1] == '1') {
                        visit.push(make_pair(x,y+1));
                        grid[x][y+1] = '0';

                    }
                    if(x + 1 < height && grid[x+1][y] == '1') {
                        visit.push(make_pair(x+1,y));
                        grid[x+1][y] = '0';

                    }
                    if(y - 1 >= 0 && grid[x][y-1] == '1') {
                        visit.push(make_pair(x,y-1));
                        grid[x][y-1] = '0';

                    }
                    if(x - 1 >= 0 && grid[x - 1][y] == '1') {
                        visit.push(make_pair(x-1,y));
                        grid[x-1][y] = '0';

                    }
                }
            }
        }
    }
    // Expected: 3
    cout << numIslands << endl;
    return 0;
}
