#include <iostream>
#include <string>
using namespace std;

// Base class
class Vehicle {
protected:
    int maxSpeed; // Protected field

public:
    // Constructor
    Vehicle(int speed);

    // Destructor
    ~Vehicle();

    // Behavior
    void start();
};

// Derived class
class Car : public Vehicle {
private:
    string fuelType; // Private field

public:
    // Constructor
    Car(int speed, const string& fuel);

    // Destructor
    ~Car();

    // Behavior
    void drive();
};

int main() {
    // static/stack objects
    Vehicle bus(80);            // static/stack Vehicle object
    Car sedan(120, "Petrol");   // static/stack Car object

    // Call behaviors for static/stack objects
    bus.start();
    sedan.start();
    sedan.drive();

    // dynamic/heap objects
    Vehicle* truck = new Vehicle(90);        // dynamic/heap Vehicle object
    Car* sportsCar = new Car(200, "Diesel"); // dynamic/heap Car object

    // Call behaviors for dynamic/heap objects
    truck->start();
    sportsCar->start();
    sportsCar->drive();

    // Clean up dynamic/heap objects
    delete truck;
    delete sportsCar;

    return 0;
}

// Definitions for Vehicle
Vehicle::Vehicle(int speed) : maxSpeed(speed) {
    cout << "Vehicle created with maxSpeed: " << maxSpeed << endl;
}

Vehicle::~Vehicle() {
    cout << "Vehicle destroyed" << endl;
}

void Vehicle::start() {
    cout << "Vehicle is starting at maxSpeed: " << maxSpeed << endl;
}

// Definitions for Car
Car::Car(int speed, const string& fuel) : Vehicle(speed), fuelType(fuel) {
    cout << "Car created with maxSpeed: " << maxSpeed << " and fuelType: " << fuelType << endl;
}

Car::~Car() {
    cout << "Car destroyed" << endl;
}

void Car::drive() {
    cout << "Car is driving with fuelType: " << fuelType << " at maxSpeed: " << maxSpeed << endl;
}

/*

Explanation
1. `Base Class `Vehicle`:`
   - `maxSpeed` is defined as `protected` 
   to allow derived classes to access it directly.
   - The constructor initializes `maxSpeed` using a member initializer list.
   - Behavior `start()` displays the value of `maxSpeed`.

2. `Derived Class `Car`:`
   - `fuelType` is defined as `private`.
   - The constructor initializes `maxSpeed` (via `Vehicle` constructor) and 
   `fuelType` using a member initializer list.
   - Behavior `drive()` displays `fuelType` and `maxSpeed`.

3. `Main Function:`
   - `static/stack Objects:`
     - `bus` is a static/stack `Vehicle` object.
     - `sedan` is a static/stack `Car` object.
   - `dynamic/heap Objects:`
     - `truck` is a dynamic/heap `Vehicle` object.
     - `sportsCar` is a dynamic/heap `Car` object.
   - Behaviors are called for all objects.

4. `Real-World Names for Objects:`
   - `bus` and `truck` represent vehicles.
   - `sedan` and `sportsCar` represent cars with appropriate names.

Output
```
Vehicle created with maxSpeed: 80
Car created with maxSpeed: 120 and fuelType: Petrol
Vehicle is starting at maxSpeed: 80
Vehicle is starting at maxSpeed: 120
Car is driving with fuelType: Petrol at maxSpeed: 120
Vehicle created with maxSpeed: 90
Car created with maxSpeed: 200 and fuelType: Diesel
Vehicle is starting at maxSpeed: 90
Vehicle is starting at maxSpeed: 200
Car is driving with fuelType: Diesel at maxSpeed: 200
Vehicle destroyed
Car destroyed
Vehicle destroyed
```
*/