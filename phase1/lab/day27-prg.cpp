#include <iostream>
#include <cstring>
using namespace std;

// Base class
class Student {
protected:
    char* name;
    double* marks;
    int numMarks;

public:
    Student(const char* name, const double* marks, int numMarks) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->marks = new double[numMarks];
        this->numMarks = numMarks;
        for (int i = 0; i < numMarks; ++i) {
            this->marks[i] = marks[i];
        }
    }

    Student(const Student& other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->numMarks = other.numMarks;
        this->marks = new double[numMarks];
        for (int i = 0; i < numMarks; ++i) {
            this->marks[i] = other.marks[i];
        }
    }

    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] name;
            delete[] marks;
            this->name = new char[strlen(other.name) + 1];
            strcpy(this->name, other.name);
            this->numMarks = other.numMarks;
            this->marks = new double[numMarks];
            for (int i = 0; i < numMarks; ++i) {
                this->marks[i] = other.marks[i];
            }
        }
        return *this;
    }

    virtual ~Student() {
        delete[] name;
        delete[] marks;
    }

    virtual double findTotalMarks() const {
        double total = 0;
        for (int i = 0; i < numMarks; ++i) {
            total += marks[i];
        }
        return total;
    }

    virtual void display() const {
        cout << "Name: " << name << ", Total Marks: " << findTotalMarks() << endl;
    }
};

// Derived class: HighSchoolStudent
class HighSchoolStudent : public Student {
public:
    HighSchoolStudent(const char* name, const double* marks, int numMarks)
        : Student(name, marks, numMarks) {}

    void display() const override {
        cout << "[High School Student] Name: " << name << ", Total Marks: " << findTotalMarks() << endl;
    }
};

// Derived class: NEETStudent
class NEETStudent : public Student {
private:
    double biologyMarks;

public:
    NEETStudent(const char* name, const double* marks, int numMarks, double biologyMarks)
        : Student(name, marks, numMarks), biologyMarks(biologyMarks) {}

    double findTotalMarks() const override {
        return Student::findTotalMarks() + biologyMarks;
    }

    void display() const override {
        cout << "[NEET Student] Name: " << name << ", Total Marks: " << findTotalMarks() << endl;
    }
};

// Derived class: JEEStudent
class JEEStudent : public Student {
private:
    double physicsMarks;
    double chemistryMarks;
    double mathMarks;

public:
    JEEStudent(const char* name, const double* marks, int numMarks, double physicsMarks, double chemistryMarks, double mathMarks)
        : Student(name, marks, numMarks), physicsMarks(physicsMarks), chemistryMarks(chemistryMarks), mathMarks(mathMarks) {}

    double findTotalMarks() const override {
        return Student::findTotalMarks() + physicsMarks + chemistryMarks + mathMarks;
    }

    void display() const override {
        cout << "[JEE Student] Name: " << name << ", Total Marks: " << findTotalMarks() << endl;
    }
};

// Derived class: NEETPlusJEEStudent
class NEETPlusJEEStudent : public Student {
private:
    double biologyMarks;
    double physicsMarks;
    double chemistryMarks;
    double mathMarks;

public:
    NEETPlusJEEStudent(const char* name, const double* marks, int numMarks, double biologyMarks, double physicsMarks, double chemistryMarks, double mathMarks)
        : Student(name, marks, numMarks), biologyMarks(biologyMarks), physicsMarks(physicsMarks), chemistryMarks(chemistryMarks), mathMarks(mathMarks) {}

    double findTotalMarks() const override {
        return Student::findTotalMarks() + biologyMarks + physicsMarks + chemistryMarks + mathMarks;
    }

    void display() const override {
        cout << "[NEET + JEE Student] Name: " << name << ", Total Marks: " << findTotalMarks() << endl;
    }
};

// Function to calculate the average marks of students
double findAverage(Student students[], int size) {
    double totalMarks = 0;
    for (int i = 0; i < size; ++i) {
        totalMarks += students[i].findTotalMarks();
    }
    return totalMarks / size;
}

int main() {
    // Static array of students
    const int size = 10;
    double marks1[] = {85, 90, 88, 92, 95};
    double marks2[] = {78, 80, 76, 85, 89};
    double marks3[] = {80, 82, 78, 85, 90};
    double marks4[] = {88, 85, 84, 87, 86};
    double marks5[] = {78, 82, 80, 85, 88};
    double marks6[] = {75, 78, 82, 85, 80};
    double marks7[] = {88, 89, 90, 92, 91};
    double marks8[] = {80, 82, 83, 84, 85};
    double marks9[] = {75, 78, 80, 82, 84};
    double marks10[] = {90, 92, 94, 96, 98};

    HighSchoolStudent student1("Alice", marks1, 5);
    HighSchoolStudent student2("Bob", marks2, 5);

    NEETStudent student3("Charlie", marks3, 5, 92);
    NEETStudent student4("Diana", marks4, 5, 90);
    NEETStudent student5("Eve", marks5, 5, 84);

    JEEStudent student6("Frank", marks6, 5, 88, 90, 85);
    JEEStudent student7("Grace", marks7, 5, 93, 95, 94);

    NEETPlusJEEStudent student8("Hannah", marks8, 5, 88, 90, 92, 93);
    NEETPlusJEEStudent student9("Ian", marks9, 5, 85, 87, 89, 90);
    NEETPlusJEEStudent student10("Kate", marks10, 5, 99, 97, 96, 95);

    Student students[] = {student1, student2, 
            student3, student4, student5, 
            student6, student7, 
            student8, student9, student10};

    // Display students
    for (int i = 0; i < size; ++i) {
        students[i].display();
    }

    // Calculate and display the average total marks
    double average = findAverage(students, size);
    cout << "The average total marks of all students is: " << average << endl;

    return 0;
}


/*


Name: Alice, Total Marks: 450
Name: Bob, Total Marks: 408
Name: Charlie, Total Marks: 415
Name: Diana, Total Marks: 430
Name: Eve, Total Marks: 413
Name: Frank, Total Marks: 400
Name: Grace, Total Marks: 450
Name: Hannah, Total Marks: 414
Name: Ian, Total Marks: 399
Name: Kate, Total Marks: 470
The average total marks of all students is: 424.

*/