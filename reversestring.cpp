// Example program
#include <iostream>
#include <stdio.h>
#include <cstring>

void reverse(char *str) {
    if (str == 0 || *str == 0)
    {
        return;
    }

    char *start = str;
    char *end = start + (strlen(str) - 1);
    char temp;

    while (end > start)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        ++start;
        --end;
    }

}

int main()
{
    char butthole[] = "butthole";
    reverse(butthole);
    std::cout << butthole << "\n";
}

