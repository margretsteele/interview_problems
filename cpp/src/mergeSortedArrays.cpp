// Example program
#include <iostream>
#include <vector>

std::vector<int> mergeSortedShit(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    result.reserve(a.size() + b.size());
    auto ait = a.begin();
    auto bit = b.begin();

    while (ait != a.end() && bit != b.end()) {
        if (*ait <= *bit) {
            result.push_back(*ait++);
        } else {
            result.push_back(*bit++);
        }
    }
    while (ait != a.end()) result.push_back(*ait++);
    while (bit != b.end()) result.push_back(*bit++);

    return result;
}

int main()
{
    std::vector<int> a = { 1, 4, 7, 9, 12, 14 };
    std::vector<int> b = { 3, 6, 7, 7 };
    auto merged = mergeSortedShit(a, b);

    for (const auto& val : merged) {
        std::cout << ' ' << val;
    }
    std::cout << '\n';
}	
