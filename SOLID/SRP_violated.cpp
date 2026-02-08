/*
Single Responsibility Principle (SRP) states that a class should have only one reason to change, meaning it should only have one job or responsibility. This principle helps in making the code more maintainable, understandable, and testable by ensuring that each class focuses on a single aspect of the functionality.

In single terms:
    - A class should have only one reason to change.
    - A class should do only one thing.

why should we follow SRP:
    - It makes the code easier to understand and maintain.
    - It reduces the impact of changes, as changes to one responsibility do not affect others.
    - It enhances testability by allowing focused unit tests for each class.
    - It promotes reusability, as classes with single responsibilities can be reused in different contexts.
    - It helps in managing complexity by breaking down large classes into smaller, more manageable ones.
    - It aligns with the principles of high cohesion and low coupling, leading to better software design.
    - It facilitates collaboration among developers, as different team members can work on different classes without causing conflicts.

How should we follow SRP:
    - Identify Responsibilities: Analyze the class to identify distinct responsibilities or functionalities it encompasses.
    - Separate Concerns: Create separate classes for each identified responsibility, ensuring that each class has a clear and focused purpose.
    - Define Clear Interfaces: Establish clear interfaces for each class, specifying the methods and properties relevant to its responsibility.
    - Limit Class Size: Keep classes small and focused, avoiding the temptation to add unrelated functionalities.
    - Refactor Regularly: Continuously review and refactor the codebase to ensure that classes adhere to SRP as the code evolves.
    - Use Composition: Favor composition over inheritance to combine functionalities from multiple classes without violating SRP.
    - Document Responsibilities: Clearly document the purpose and responsibilities of each class to aid understanding for future developers.

*/

#include <iostream>
#include <vector>

using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    };
};

// violating SRP: Shoppingcart is handelling multiple responsibilities
class ShoppingCart {
private:
    vector<Product*> products;

public:
    void addProduct(Product *p){
        products.push_back(p);
    };

    vector<Product*>& getProducts(){
        return products;
    };

    // 1. Calculates total price in cart
    double calculateTotal(){
        double total = 0;
        for(auto p:products){
            total += p->price;
        }
        return total;
    };

    // 2. Violating SRP - Prints in voice (Should be in a separate class)
    void printInvoice(){
        cout<<"Shopping cart invoice:\n";
        for(auto p:products){
            cout<<p->name<<" - $"<<p->price<<endl;
        }
        cout<<"Total: $"<<calculateTotal()<<endl;
    };

    // 3. Violating SRP - saves to DB (Should be in a separate class)
    void saveToDatabase(){
        cout<<"Saving to database..."<<endl;
    };
};


int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 1500));
    cart->addProduct(new Product("Mouse", 50));

    cart->printInvoice();
    cart->saveToDatabase();

    return 0;
}