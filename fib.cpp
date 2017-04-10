#include <iostream>
#include <string>

int fib(int num) {
    if(num == 0) {
        return 0;
    }
    if(num == 1) {
        return 1;
    }
    return fib(num-1) + fib(num-2);
}

int main()
{
    for(auto i = 0; i < 15; i++) {
        std::cout << "i: " << i << " fib(i): " << fib(i) << "\n";
    }

}



