// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;
void merge(vector<pair<int, int>>& input, int low, int midpoint, int high) {
    vector<pair<int, int>> temp;
    temp.reserve(50);
    auto i = low;
    auto k = low;
    auto j = midpoint + 1;
    
    while(i <= midpoint && j <= high) {
        if(input[i] < input[j]) {
            temp[k] = input[i];
            i++;
            k++;
        }
        else {
            temp[k] = input[j];
            j++;
            k++;
        }
    }
    
    while(i <= midpoint) {
        temp[k] = input[i];
        i++;
        k++;
    }
    
    while(j <= high) {
        temp[k] = input[j];
        j++;
        k++;
    }
    
    for(i = low; i < k; i++) {
        input[i] = temp[i];
    }
}

void mergesort(vector<pair<int, int>>& input, int low, int high) {
    if(low < high) {
        auto midpoint = (low + high) / 2;
        mergesort(input, low, midpoint);
        mergesort(input, midpoint + 1, high);
        merge(input, low, midpoint, high);
    }
}

int largestTower(vector<pair<int, int>>& input) {
    mergesort(input, 0, input.size() - 1);

    auto count = 1; //the very first person
    pair<int, int> prevPerson = input[0];
    for(size_t i = 1; i != input.size(); ++i) {
        if(input[i].first > prevPerson.first && input[i].second > prevPerson.second) {
            count++;
            prevPerson = input[i];
        }
    }
    return count;
}

int main()
{
    pair<int, int> a = make_pair(65, 100);
    pair<int, int> b = make_pair(70, 150);
    pair<int, int> c = make_pair(56, 90);
    pair<int, int> d = make_pair(75, 190);
    pair<int, int> e = make_pair(60, 95);
    pair<int, int> f = make_pair(68, 110);
    pair<int, int> g = make_pair(68, 120);
    vector<pair<int, int>> v = {a, b, c, d, e, f, g};

    auto val = largestTower(v);
    cout << val;
}
