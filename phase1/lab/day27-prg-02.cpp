#include <iostream>
#include <cstring>

using namespace std;

// Base Class: Student
class Student {
protected:
    char* name;  // Dynamically allocated char* for student name

public:
    Student(const char* studentName) {
        name = new char[strlen(studentName) + 1];
        strcpy(name, studentName);
    }

    virtual ~Student() {
        delete[] name;  // Properly delete dynamically allocated memory
    }

    virtual double findTotalMarks() const {
        return 0;  // Default implementation for total marks
    }

    virtual void display() const {
        cout << "Student Name: " << name << endl;
    }
};

// Derived Class: HighSchoolStudent
class HighSchoolStudent : public Student {
protected:
    double* marks;  // Dynamically allocated array of subject marks
    int numMarks;   // Number of marks

public:
    HighSchoolStudent(const char* studentName, double* studentMarks, int num)
        : Student(studentName), marks(new double[num]), numMarks(num) {
        for (int i = 0; i < numMarks; i++) {
            marks[i] = studentMarks[i];
        }
    }

    ~HighSchoolStudent() {
        delete[] marks;  // Properly delete dynamically allocated memory
    }

    double findTotalMarks() const override {
        double total = 0;
        for (int i = 0; i < numMarks; i++) {
            total += marks[i];
        }
        return total;
    }

    void display() const override {
        Student::display();  // Display student name from base class
        cout << "Marks: ";
        for (int i = 0; i < numMarks; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

// Class: NEETCourse
class NEETCourse {
protected:
    double biologyMarks;  // Marks for Biology

public:
    NEETCourse(double bioMarks) : biologyMarks(bioMarks) {}

    
};

// Class: JEECourse
class JEECourse {
protected:
    double physicsMarks, chemistryMarks, mathMarks;  // Marks for Physics, Chemistry, Math

public:
    JEECourse(double phyMarks, double chemMarks, double mathMarks)
        : physicsMarks(phyMarks), chemistryMarks(chemMarks), mathMarks(mathMarks) {}

    
};

// Derived Class: NEETStudent
class NEETStudent : public HighSchoolStudent, public NEETCourse {
public:
    NEETStudent(const char* studentName, double* studentMarks, int num, double bioMarks)
        : HighSchoolStudent(studentName, studentMarks, num), 
        NEETCourse(bioMarks) {}

    double findTotalMarks() const override {
        return HighSchoolStudent::findTotalMarks() + biologyMarks;  // Sum of high school marks and biology marks
    }

    void display() const override {
        HighSchoolStudent::display();
        cout << "Biology Marks: " << biologyMarks << endl;
    }
};

// Derived Class: JEEStudent
class JEEStudent : public HighSchoolStudent, public JEECourse {
public:
    JEEStudent(const char* studentName, double* studentMarks, 
        int num, double phyMarks, double chemMarks, double mathMarks)
        : HighSchoolStudent(studentName, studentMarks, num), 
        JEECourse(phyMarks, chemMarks, mathMarks) {}

    double findTotalMarks() const override {
        return HighSchoolStudent::findTotalMarks() + physicsMarks + chemistryMarks + mathMarks;  // Sum of high school marks and JEE subject marks
    }

    void display() const override {
        HighSchoolStudent::display();
        cout << "Physics Marks: " << physicsMarks << ", Chemistry Marks: " << chemistryMarks << ", Math Marks: " << mathMarks << endl;
    }
};

// Derived class: NEETPlusJEEStudent
class NEETPlusJEEStudent : public HighSchoolStudent, public JEECourse, public NEETCourse  {

public:
    NEETPlusJEEStudent(const char* name, double* marks, int numMarks, 
        double biologyMarks, double physicsMarks, double chemistryMarks, double mathMarks)
        : HighSchoolStudent(name, marks, numMarks), 
        JEECourse(physicsMarks, chemistryMarks, mathMarks) , 
        NEETCourse(biologyMarks)
        {}

    double findTotalMarks() const override {
        return HighSchoolStudent::findTotalMarks() + biologyMarks + physicsMarks + chemistryMarks + mathMarks ;
    }

    void display() const override {
        HighSchoolStudent::display();
        cout << "Physics Marks: " << physicsMarks << ", Chemistry Marks: " << chemistryMarks << ", Math Marks: " << mathMarks << endl;
        cout << "Biology Marks: " << biologyMarks << endl;
    }
};

// Function to calculate the average marks of students
double findAverage(Student* students[], int size) {
    double totalMarks = 0;
    for (int i = 0; i < size; ++i) {
        totalMarks += students[i]->findTotalMarks();
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

    Student* students[] = {&student1, &student2, 
            &student3, &student4, &student5, 
            &student6, &student7, 
            &student8, &student9, &student10};

    // Display students
    for (int i = 0; i < size; ++i) {
        students[i]->display(); 
        cout << "Total Marks:" << students[i]->findTotalMarks() << endl;
        cout << endl;
    }

    // Calculate and display the average total marks
    double average = findAverage(students, size);
    cout << "The average total marks of all students is: " << average << endl;

    return 0;
}