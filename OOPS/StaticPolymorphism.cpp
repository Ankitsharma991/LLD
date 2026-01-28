#include <iostream>
#include <string>

using namespace std;

/*
Static polymorphism (also known as Compile-time Polymorphism) is a core concept in object-oriented programming that allows methods to be resolved at compile-time rather than runtime. This is typically achieved through function overloading and operator overloading in C++. In this example, we will create a base class 'Car' and two derived classes 'ManualCar' and 'ElectricCar' that demonstrate static polymorphism by providing specialized methods.
*/

class Car {
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
    public:
    Car(string b, string m){
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
        this->currentSpeed = 0;
    };

    void startEngine(){
        isEngineOn = true;
        cout << brand << " " << model << " : Engine started." << endl;
    }   

    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine stopped." << endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Cannot accelerate. Engine is off." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerated to " << currentSpeed << " km/h." << endl;
    }

    // static polymorphism through function overloading
    void accelerate(int increment){
        if(!isEngineOn){
            cout << brand << " " << model << " : Cannot accelerate. Engine is off." << endl;
            return;
        }
        currentSpeed += increment;
        cout << brand << " " << model << " : Accelerated by " << increment << " to " << currentSpeed << " km/h." << endl;
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

    ~Car(){
        cout << brand << " " << model << " : Car object destroyed." << endl;
    }
};


int main(){
    Car* myManualCar = new Car("Toyota", "Corolla");
    myManualCar->startEngine();
    myManualCar->accelerate(); // base class method
    myManualCar->accelerate(30); // overloaded method
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    return 0;
}