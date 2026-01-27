#include <iostream>
#include <string>

using namespace std;

// real life car
/*
Abstraction is the concept of hiding the complex implementation details and showing only the essential features of the object. It helps in reducing programming complexity and effort.
In this example, we will create an abstract class 'Car' that defines the essential features of a car. The derived class 'SportsCar' will implement these features.  
*/

class Car {
    public:
        virtual void startEngine() = 0;
        virtual void stopEngine() = 0;
        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual void shiftGear(int gear) = 0;
        virtual ~Car() {}
};

class SportsCar : public Car {
    public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    SportsCar(string b, string m){
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
        this->currentSpeed = 0;
        this->currentGear = 0;
    };

    void startEngine(){
        isEngineOn = true;
        cout << brand << " " << model << " : Engine started." << endl;
    }

    void shiftGear(int gear){
        if(!isEngineOn){
            cout << brand << " " << model << " : Cannot shift gear. Engine is off." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << gear << "." << endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Cannot accelerate. Engine is off." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerated to " << currentSpeed << " km/h." << endl;
    }


    void brake(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Cannot brake. Engine is off." << endl;
            return;
        }
        currentSpeed -= 20;
        if(currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braked to " << currentSpeed << " km/h." << endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout << brand << " " << model << " : Engine stopped." << endl;
    }
};



int main(){
    Car* myCar = new SportsCar("Ferrari", "488 Spider");
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();
    delete myCar;
    return 0;
}