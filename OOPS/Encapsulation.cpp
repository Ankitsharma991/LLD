#include <iostream>
#include <string>

using namespace std;

/*
Encapsulation is the concept of wrapping data and methods that operate on that data within a single unit or class. It restricts direct access to some of the object's components, which can prevent the accidental modification of data. This is typically achieved using access specifiers like private, protected, and public. In this example, we will create a class 'BankAccount' that encapsulates the account details and provides methods to interact with the account.

Access Modifiers in cpp:
1. Private: Members declared as private are accessible only within the same class.
2. Protected: Members declared as protected are accessible within the same class and by derived class instances.
3. Public: Members declared as public are accessible from any part of the program.
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
    private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyre;

    public:
    SportsCar(string b, string m){
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
        this->currentSpeed = 0;
        this->currentGear = 0;
        this->tyre = "MRF"; // default tyre
    };

    // Getter and Setter for currentSpeed
    int getCurrentSpeed() {
        return currentSpeed;
    }

    void setCurrentSpeed(int speed) {
        if(speed >= 0) {
            currentSpeed = speed;
        }
    }

    // getter and setter for tyre
    string getTyre() {
        return tyre;
    }   

    void setTyre(string t) {
        // we can add validation here if needed to check for valid tyre brands that's why getter and setter are prefered.
        tyre = t;
    }

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
    SportsCar* sportsCar = dynamic_cast<SportsCar*>(myCar);
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();

    // sportsCar->currentSpeed = 200;
    // cout << "Current Speed (direct access): " << sportsCar->currentSpeed << " km/h." << endl;
    cout << "Current Speed (via getter): " << sportsCar->getCurrentSpeed() << " km/h." << endl;
    sportsCar->setCurrentSpeed(200);
    cout << "Current Speed (via getter): " << sportsCar->getCurrentSpeed() << " km/h." << endl;

    myCar->stopEngine();

    delete myCar;
    return 0;
}