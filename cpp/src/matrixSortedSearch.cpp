// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<int, int> find(vector<vector<int>> const& input, int value, int numCol, int numRow) {
    size_t col = numCol - 1;    
    size_t row = 0;
    
    while(row < numRow && col >= 0) {
        if(input[col][row] == value) {
            return make_pair(row, col);
        }
        else if(input[col][row] > value) {
            col--;
        }
        else {
            row++;
        }
    }
    return make_pair(-1, -1);
}

int main()
{
    vector<int> a = {1,  3,  7};
    vector<int> b = {4,  6,  9};
    vector<int> c = {7,  8,  15};
    vector<int> d = {9,  10, 16};
    vector<vector<int>> v = {a, b, c, d};

    pair<int, int> index = find(v, 16, 4, 3);
    cout << index.first << " " << index.second;
}
