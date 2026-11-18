#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    double marks;
};

char calculateGrade(double marks) {
    if (marks >= 90.0)
        return 'A';
    if (marks >= 75.0)
        return 'B';
    if (marks >= 60.0)
        return 'C';

    return 'F';
}

int main() {
    vector<Student> students = {
        {101, "Justin", 82.0},
        {102, "Emma", 94.0},
        {103, "Jennifer", 58.0},
        {104, "Sunny", 75.0},
        {105, "Victoria", 68.0}
    };

    // Transform marks by applying a function
    transform(students.begin(), students.end(),
              students.begin(),
              [](Student &s) {
                  s.marks = min(100.0, s.marks);
                  return s;
              });

    // Sort students by marks
    sort(students.begin(), students.end(),
         [](const Student &a, const Student &b) {
             return a.marks > b.marks;
         });

    cout << "Sorted Leaderboard:" << endl;

    for (const auto &s : students) {
        cout << "ID: " << s.id
             << " Name: " << s.name
             << " Marks: " << s.marks
             << " Grade: " << calculateGrade(s.marks)
             << endl;
    }

    // Find first student having marks less than 60
    auto it = find_if(students.begin(), students.end(),
                      [](const Student &s) {
                          return s.marks < 60;
                      });

    if (it != students.end()) {
        cout << "\nFirst student needing attention: "
             << it->name << endl;
    }

    unordered_map<int, double> idToMarks;
    map<char, vector<string>> gradeDistribution;

    for (const auto &s : students) {
        idToMarks[s.id] = s.marks;
        gradeDistribution[calculateGrade(s.marks)]
            .push_back(s.name);
    }

    cout << "\nFast lookup: Marks of ID 104 = "
         << idToMarks[104] << endl;

    return 0;
}
