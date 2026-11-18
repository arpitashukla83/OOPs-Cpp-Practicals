#include <iostream>
using namespace std;
 
int main() {
    int age = 19;
    float height = 5.3f;
    char grade = 'A';
    bool isStudent = true;
    const int MAX_MARKS = 100;
 
    int studentAge;
    int a = 10, b = 5;
 
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << "Grade: " << grade << endl;
    cout << "Is Student: " << isStudent << endl;
    cout << "Maximum Marks: " << MAX_MARKS << endl;
 
    cout << "Sum = " << a + b << endl;
    cout << "Difference = " << a - b << endl;
    cout << "Product = " << a * b << endl;
    cout << "Quotient = " << a / b << endl;
    cout << "Remainder = " << a % b << endl;
 
    cout << "Enter your age: ";
    cin >> studentAge;
    cout << "You entered: " << studentAge << endl;
 
    return 0;
}

 
