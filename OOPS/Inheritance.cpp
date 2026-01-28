#include <iostream>
#include <string>

using namespace std;


/*
Interitance is a fundamental concept in object-oriented programming that allows a new class (derived class) to inherit properties and behaviors (data members and methods) from an existing class (base class). This promotes code reusability and establishes a hierarchical relationship between classes. In this example, we will create a base class 'Car' and a derived class 'SportsCar' that inherits from 'Car'.

Different types of Inheritance in C++:
1. Single Inheritance: A derived class inherits from a single base class.
2. Multiple Inheritance: A derived class inherits from more than one base class.
3. Multilevel Inheritance: A derived class inherits from a base class, and another class inherits from the derived class.
4. Hierarchical Inheritance: Multiple derived classes inherit from a single base class.
5. Hybrid Inheritance: A combination of two or more types of inheritance.
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


class ManualCar : public Car {
    private:
        int currentGear; // specific to ManualCar

        public:
        ManualCar(string b, string m) : Car(b, m){
            this->currentGear = 0; // Initialize gear to neutral
        }
        // specialized methods for ManualCar
        void shiftGear(int gear){
        if(!isEngineOn){
            cout << brand << " " << model << " : Cannot shift gear. Engine is off." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << gear << "." << endl;
    }

};

class ElectricCar : public Car {
    private:
        int batteryLevel; // specific to ElectricCar

        public:
        ElectricCar(string b, string m) : Car(b, m){
            this->batteryLevel = 100; // Initialize battery level to 100%
        }

        // specialized methods for ElectricCar
        void chargeBattery(){
            batteryLevel = 100;
            if(batteryLevel > 100) batteryLevel = 100;
            cout << brand << " " << model << " : Battery charged to " << batteryLevel << "%." << endl;
        }   

};


int main(){
    ManualCar* myManualCar = new ManualCar("Toyota", "Corolla");
    myManualCar->startEngine();
    myManualCar->shiftGear(1); // specific to ManualCar
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout<<"-----------------------------------------------" <<endl;

    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->chargeBattery(); // specific to ElectricCar
    myElectricCar->stopEngine();
    delete myElectricCar;

    return 0;
}