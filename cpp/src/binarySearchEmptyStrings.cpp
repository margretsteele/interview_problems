// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find(vector<string> const& input, string value) {
    size_t lo = 0;
    size_t hi = input.size() - 1;
    while(lo <= hi) {
        while(lo < hi && input[hi] == "") {
            hi--;
        }
        auto midpoint = (lo + hi) / 2;

        int compare = input[midpoint].compare(value);
        if(compare == 0) {
            return midpoint;
        }
        if(compare < 0) {
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
    vector<string> v = {"at", "", "", "", "ball", "car", "", "", "dad", "", ""};

    auto index = find(v, "ball");
    cout << index;
}
