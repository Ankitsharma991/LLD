#include<iostream>
#include<string>

using namespace std;

/*
Polymorphism (poly means many i.e manyforms is polymorphism) is a core concept in object-oriented programming that allows objects of different classes to be treated as objects of a common superclass. It enables a single interface to represent different underlying forms (data types). The most common use of polymorphism in C++ is through virtual functions, which allow derived classes to override methods of their base class. In this example, we will create a base class 'Car' with virtual functions and two derived classes

there are two types of polymorphism:
1. Compile-time Polymorphism (Function Overloading and Operator Overloading) (static polymorphism)
2. Run-time Polymorphism (Virtual Functions) (Dyanamic Polymorphism)

-- compile-time polymorphism is achieved using function overloading and operator overloading. 
    - function overloading allows multiple functions with the same name but different parameters to coexist.
    - operator overloading allows custom implementation of operators for user-defined types.

-- run-time polymorphism is achieved using virtual functions. A base class declares a function as virtual, and derived classes override this function to provide specific implementations. When a base class pointer points to a derived class object, the overridden function in the derived class is called at runtime. 'ManualCar' and 'ElectricCar' that override these methods to provide specific implementations.
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





int main(){
    return 0;
}