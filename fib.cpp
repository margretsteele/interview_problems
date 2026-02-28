#include <iostream>

int fib(int num) {
    if (num <= 0) return 0;
    if (num == 1) return 1;

    int prev = 0, curr = 1;
    for (int i = 2; i <= num; i++) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main()
{
    for(auto i = 0; i < 15; i++) {
        std::cout << "i: " << i << " fib(i): " << fib(i) << "\n";
    }

}

