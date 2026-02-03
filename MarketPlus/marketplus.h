#ifndef MARKETPLUS_H
#define MARKETPLUS_H
#include <iostream>
using namespace std;

class Item{

    // Gives Permission to Cart class to access private members of Item class
    friend class Cart;
private:
    char* name{};
    int sku{};
    double price{};
    int quantity{};

void setName(const char* name);
public:
    Item();
    Item(const char* name, int sku, double price);
    void set(const char* name,int sku,double price, int qty = 1);
    void display(ostream& os = cout) const;
    operator bool() const;
    Item& operator+=(int qty);
    bool operator==(int sku) const;
    ~Item();

};


class Cart {
private:
    Item** items;
    int m_count;
    int m_capacity;
    void resize();   
public:
    Cart();
    Cart& operator+=(Item& item);
    Cart& operator-=(int sku);
    void display() const;
    ~Cart();
};
#endif
