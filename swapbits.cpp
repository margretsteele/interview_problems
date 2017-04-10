// Example program
#include <iostream>
#include <ostream>
#include <bitset>


int main()
{
    std::bitset<8> a("01110001");
    std::bitset<8> b = a <<1;
    std::bitset<8> c = a >>1;

    std::bitset<8> removeEvens("01010101");
    std::bitset<8> removeOdds("10101010");

    std::cout << "A: " << a << "\n";
    std::cout << "B: " << b << "\n";
    std::cout << "C: " << c << "\n";

    b &= removeOdds;
    c &= removeEvens;

    std::cout << "B after mod: " << b << "\n";
    std::cout << "C after mod: " << c << "\n";

    std::bitset<8> result = b | c;
    std::cout << "result: " << result << "\n";
}
