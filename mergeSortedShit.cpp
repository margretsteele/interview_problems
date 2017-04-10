// Example program
#include <iostream>
#include <string>
#include <vector>

void mergeSortedShit(std::vector<int>& a, std::vector<int>& b) {
    std::vector<int>::iterator ait = a.begin();
    std::vector<int>::iterator bit = b.begin();
    while(bit != b.end() && ait != a.end()) {
        if(*bit >= *ait) {
            ait++;
        }
        else {
            ait = a.insert(ait, *bit);
            bit++;
        }
    }
}

int main()
{
    std::vector<int> a = { 1, 4, 7, 9, 12, 14 };
    std::vector<int> b = { 3, 6, 7, 7 };
    mergeSortedShit(a, b);
    
    for (std::vector<int>::iterator it = a.begin() ; it != a.end(); ++it) {
        std::cout << ' ' << *it;
    }
    
}	