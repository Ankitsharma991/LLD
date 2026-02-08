/*
OCP stands for open-close principle, A class should be open for extension but close for modification.
this is very strict to follow and it's supposed to be followed as far as possible.
OCP can be used easily through Abstraction, Inheritance and Polymorphism

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;



// Product class representing any items in ecommerce
class Product{
public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }

};

// 1. ShoppingCart: Only responsible for cart related bussiness logic.
class ShoppingCart{
private:
    vector<Product*> products; // stores heap allocated products

public:
    void addProduct(Product* p){
        products.push_back(p);
    }

    vector<Product*>& getProducts(){
        return products;
    };

    // calculates total price in cart
    double calculateTotal(){
        double total = 0;
        for(auto p:products){
            total+=p->price;
        };
        return total;
    }
};

// 2. ShoppingCartPrinter: only responsible for printing invoices
class ShoppingCartPrinter {
private:
    ShoppingCart* cart;
public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart = cart;
    }

    void printInvoice(){
        cout<<"Invoice: "<<endl;
        for(auto p:cart->getProducts()){
            cout<<p->name<<" - "<<p->price<<endl;
        }
        cout<<"Total: "<<cart->calculateTotal()<<endl;
    }
};

// ShoppingCartStorage: only responsible for saving data to db
class ShoppingCartStorage{
private:
    ShoppingCart* cart;

public:

// this is violating OCP because if we want to add new storage type we have to modify this class, which is not good. but here all the methods are included in the singlle class.

    ShoppingCartStorage(ShoppingCart* cart){
        this->cart = cart;
    }

    void saveToSQLDatabase(){
        cout<<"Saving shopping cart to SQL DB..."<<endl;
    };

    void saveToMongodb(){
        cout<<"Saving shopping cart to Mongo DB..."<<endl;
    }

    void saveToFile(){
        cout<<"Saving shopping cart to file..."<<endl;
    }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 1000));
    cart->addProduct(new Product("Mouse", 50)); 

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToSQLDatabase();
    db->saveToMongodb();
    db->saveToFile();

    return 0;
}



