#include <iostream>
#include <cstring>
using namespace std;

class Student {
    private:
        char* name;
    public:
        Student(const char* name) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
        ~Student() {
            delete[] name;
        }
        void show() {
            cout << "name:: " << name << endl;
        }
};

int main() {
    Student s1("Kim");
    s1.show();

    char name[255] = "Raj";
    Student s2(name);
    s2.show();
    return 0;
}