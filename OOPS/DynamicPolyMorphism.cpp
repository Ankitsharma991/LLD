#include <iostream>
#include <string>

using namespace std;

/*
Dynamic Polymorphism (also known as Run-time Polymorphism) is a core concept in object-oriented programming that allows methods to be resolved at runtime rather than compile-time. This is typically achieved through the use of virtual functions in C++. In this example, we will create a base class 'Car' and two derived classes 'ManualCar' and 'ElectricCar' that demonstrate dynamic polymorphism by overriding base class methods.
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

    virtual ~Car(){
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

    // Overriding Accelerate method - Dynamic Polymorphism
    void accelerate()    {
        if(!isEngineOn){
            cout << brand << " " << model << " : Cannot accelerate. Engine is off." << endl;
            return;     
        }
        currentSpeed += 25; // Manual cars accelerate faster
        cout << brand << " " << model << " : Accelerated to " << currentSpeed << " km/h." << endl;
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

        // Overriding Accelerate method - Dynamic Polymorphism
        void accelerate()    {
        if(!isEngineOn){    
            cout << brand << " " << model << " : Cannot accelerate. Engine is off." << endl;
            return;     
        }   
        currentSpeed += 15; // Electric cars accelerate slower
        cout << brand << " " << model << " : Accelerated to " << currentSpeed<<endl;
    };
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