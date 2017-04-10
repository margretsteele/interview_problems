// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
class Stack {
  public:    
    T pop() {
        if(data.empty()) return T();
        T temp = data.back();
        data.pop_back();
        
        if(temp == min) {
            minCount--;
            if(minCount == 0) {
                calculateMin();
            }
        }
        return temp;
    }
    
    void push(T value) {
        data.push_back(value);
        if(value == min) {
            minCount++;
        }
        else if(value < min) {
            minCount = 1;
            min = value;
        }
    }
    
    T getMin() {
        return min;
    }
    
    void output() {
        for(auto rit = data.rbegin(); rit != data.rend(); ++rit) {
            cout << *rit << " ";
        }
        cout << "\n";
    }

  private:
    void calculateMin() {
        minCount = 0;
        min = T();
        for(auto value : data) {
            if(minCount == 0) {
                min = value;
                minCount = 1;
            }
            else if(min > value) {
                min = value;
                minCount = 1;
            }
            else if(min == value) {
                minCount++;
            }
        }
    }

    vector<T> data;
    T min;
    int minCount;
};

int main()
{
    Stack<int> stack;
    cout << stack.pop() << "\n";

    stack.push(1);
    stack.push(2);
    stack.push(-8);
    stack.push(14);
    stack.push(100);
    
    stack.output();
    cout << stack.getMin() << "\n";
    stack.pop();
    stack.pop();
    stack.pop();
    
    cout << stack.getMin() << "\n";

}
