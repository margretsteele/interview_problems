#include <iostream>
#include <ostream>
#include <bitset>

int mult(int a, int b) {
    if(b > 1) {
        return (a <<1) + mult(a, b-2);
    }
    if(b != 0) {
        return a;
    }
    return 0;
}

int main()
{
    std::cout << mult(2, 8) << "\n";
}
