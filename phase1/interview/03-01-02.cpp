#include <iostream>
#include <memory>
#include <cstring>
using namespace std;

class Student {
    private:
        unique_ptr<char[]> name;
    public:
        Student(const char* name) {
            this->name = make_unique<char[]>(strlen(name) + 1);
            strcpy(this->name.get(), name);
        }

        void show() const {
            cout << "name:: " << name.get() << endl;
        }
};

int main() {
    Student s1("Kim");
    s1.show();

    const char name[] = "Raj";
    Student s2(name);
    s2.show();

    return 0;
}
