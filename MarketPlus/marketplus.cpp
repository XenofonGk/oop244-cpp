#include "marketplus.h"
#include <cstring>
using namespace std;


// Set the name of Item safely
// Deallocates existing memory, allocates new memory, and copies the string
void Item::setName(const char* name){
    if ( this->name != nullptr){
        delete[] this->name;
        this->name = nullptr;
    }
    if (name != nullptr && name[0] != '\0'){
        int len = strlen(name);
        this->name = new char[len +1];
        strcpy(this->name, name);
    } else {
        this->name = nullptr;
    }
}

// Creating safe state 
//Constructor
Item::Item(){
    name = nullptr;
    sku = 0;
    price = 0;
    quantity = 0;
}
// Passing value to the parameters
Item::Item(const char* name, int sku,double price){
    this->name = nullptr;
    setName(name);
    this->sku = sku;
    this->price = price;
    this->quantity = 1;
}
// Destractor
Item::~Item(){
    delete[] name;
    name = nullptr;
}

// Sets all atributes of the Item at once
// Uses setName to handle the dynamic memory
void Item::set(const char* name,int sku,double price, int qty){
    setName(name);
    this->sku = sku;
    this->price = price;
    this->quantity = qty;
}
// Prints the Item details to a specified output stream
void Item::display(ostream& os) const{
    if (name !=nullptr){
        os << "Displaying: " << name << " | " << "SKU: " << sku << " | " << "Price: " << price << endl;
    } else {
        os << "Empty Item" << endl;
    }
}

Item::operator bool() const{
    if (name != nullptr && sku > 0){
        return true;
    } else {
        return false;
    }
}

// Adds to existing quantity of the item
Item& Item::operator+=(int qty) {
    this->quantity += qty;
    return *this;
}

bool Item::operator==(int sku) const{
if (this->sku == sku){
    return true;
}    else {
    return false;
}
}

Cart::Cart(){
m_count = 0 ;
m_capacity = 0;
items = nullptr;
}

Cart::~Cart(){
    delete[] items;
    items = nullptr;
}

void Cart::resize(){
    // calculate new size
    int newCap;
    if (m_capacity == 0) {
      newCap = 2;
    } else {
       newCap = m_capacity * 2;
    }
    // alocating new array of pointers
Item** temp = new Item*[newCap];

    // copy pointers from odl array to new array
for (int i = 0; i < m_count; i++){
    temp[i] = items[i];
}
    // delete the old array
    delete[] items;
    items = temp;
    m_capacity = newCap;
}

Cart& Cart::operator+=(Item& item){
    if ( m_count == m_capacity) {
        resize();
    }
    items[m_count] = &item;
    m_count++;

    return *this;
}


Cart& Cart::operator-=(int sku){
    for (int j = 0; j < m_count; j++){
        if (*items[j] == sku) {
            for (int k = j; k < m_count - 1; k++){
                items[k] = items[k + 1];
            }
          m_count--;
          items[m_count] = nullptr;
          return *this;
        }
    }
   return *this;
}

void Cart::display() const {
    for (int i = 0; i < m_count; i++){
        items[i]->display();
    }

double total = 0;
    for (int i = 0; i < m_count; i++){
        total += items[i]->price * items[i]->quantity;
    }
    cout << "------------------------" << endl;
    cout << "Total Price: " << total << endl;
}