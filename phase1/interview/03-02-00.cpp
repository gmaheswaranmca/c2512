#include <iostream>
using namespace std;

class Shape {
    private:
    public:
        virtual int findArea() = 0;
};
class Rectangle : Shape{
    private:
        int length;
        int breadth;
    public:
        Rectangle(int l, int b){
            length = l;
            breadth = b;
        }
        int findArea() override {
            return length * breadth;
        }
};

int main() {
    Shape* shape1 = (Shape*)new Rectangle(10, 20);
    cout << "Area=" << shape1->findArea();

    //Shape* shape2 = (Shape*)new Circle(10);
    //cout << "Area=" << shape2->findArea();
    return 0;
}