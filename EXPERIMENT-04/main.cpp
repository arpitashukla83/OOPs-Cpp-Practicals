#include <iostream>
using namespace std;
 
class Person {
protected:
    int id;
 
public:
    Person(int i) : id(i) {}
 
    virtual void show() {
        cout << "ID: " << id << endl;
    }
};
 
class Student : public Person {
protected:
    int marks;
 
public:
    Student(int i, int m) : Person(i), marks(m) {}
 
    void show() override {
        cout << "Student ID: " << id
             << " Marks: " << marks << endl;
    }
};
 
class GraduateStudent : public Student {
    const char* thesis;
 
public:
    GraduateStudent(int i, int m, const char* t)
        : Student(i, m), thesis(t) {}
 
    void show() override {
        cout << "Graduate Student ID: " << id << endl;
        cout << "Marks: " << marks << endl;
        cout << "Thesis: " << thesis << endl;
    }
};
 
int main() {
    GraduateStudent g(101, 92, "AI");
    g.show();
 
    return 0;
}
