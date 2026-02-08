
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

// Abstract Class
class Persistence {
private:
    ShoppingCart* cart;
public:
    virtual void save(ShoppingCart* cart) = 0; // pure virtual function
};


class SQLPersistence : public Persistence{
public:
    void save(ShoppingCart* cart) override{
        cout<<"Saving shopping cart to SQL..."<<endl;
    };
};

class MongoPersistence : public Persistence{
public:
    void save(ShoppingCart* cart)override{
        cout<<"Saving shopping cart to Mongodb..."<<endl;
    };
};

class FilePersistence : public Persistence{
public:
    void save(ShoppingCart* cart)override{
        cout<<"Saving shopping cart to file..."<<endl;
    };
};


int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 1000));
    cart->addProduct(new Product("Mouse", 50)); 

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    Persistence* db = new SQLPersistence();
    Persistence* mongo = new MongoPersistence();
    Persistence* file = new FilePersistence();

    db->save(cart); // save to sql database
    mongo->save(cart); // save to mongodb   
    file->save(cart); // save to file

    return 0;
}



