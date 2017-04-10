// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find(vector<int> const& input, int value) {
    size_t lo = 0;
    size_t hi = input.size() - 1;
    while(lo <= hi) {
        auto midpoint = (lo + hi) / 2;
        if(input[midpoint] == value) {
            return midpoint;
        }
        else if(input[midpoint] >= input[lo]) {
            if(input[midpoint] < value) {
                lo = midpoint + 1;
            }
            else if(input[midpoint] > value){
                hi = midpoint - 1;
            }
        }
        else if(input[midpoint] > value) {
            hi = midpoint - 1;
        }
        else if(input[hi] >= value) {
            lo = midpoint + 1;
        }
        else {
            hi = midpoint - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> v = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};

    auto index = find(v, 5);
    cout << index;
}
