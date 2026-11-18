#include <iostream>
#include <string>
using namespace std;
 
template <typename T>
class Stack {
    T arr[10];
    int topIndex;
 
public:
    Stack() : topIndex(-1) {}
 
    void push(T val) {
        if (topIndex == 9) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++topIndex] = val;
    }
 
    T pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow" << endl;
            return T{};
        }
        return arr[topIndex--];
    }
};
 
int main() {
    Stack<int> sInt;
    sInt.push(10);
    sInt.push(20);
    cout << "Popped Int: " << sInt.pop() << endl;
 
    Stack<float> sFloat;
    sFloat.push(5.5f);
    cout << "Popped Float: " << sFloat.pop() << endl;
 
    Stack<string> sStr;
    sStr.push("Hello");
    cout << "Popped String: " << sStr.pop() << endl;
 
    return 0;
}
