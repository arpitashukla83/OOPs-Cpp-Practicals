#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("students.csv", ios::out | ios::in | ios::trunc | ios::binary);

    // Check if file actually opened
    if (!file.is_open()) {
        cout << "Error: Unable to create/open students.csv!\n";
        return 1;
    }

    // 1. Write student records
    file << "101,Amit ,85\n";
    streampos pos2 = file.tellp();
    file << "102,Neha ,90\n";
    file << "103,Rohan,78\n";
    file.flush(); // Force data to write before reading

    cout << "Total bytes written (tellp): " << file.tellp() << "\n\n";

    // 2. Read all records from the start
    file.seekg(0);
    char line[30];
    cout << "--- Initial Records ---\n";
    while (file.getline(line, 30)) {
        cout << line << "\n";
    }

    // 3. Modify 2nd record directly using seekp()
    file.clear();
    file.seekp(pos2);
    file << "102,Neha ,99\n";
    file.flush();

    // 4. Verify updated record using seekg() and tellg()
    file.seekg(pos2);
    cout << "\nReading from byte " << file.tellg() << " (tellg):\n";
    file.getline(line, 30);
    cout << "Updated Record -> " << line << "\n";

    file.close();
    return 0;
}
