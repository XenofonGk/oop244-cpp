#include <iostream>
#include "marketplus.h"
using namespace std;

int main() {
    cout << "======================================" << endl;
    cout << "    MarketPlus Inventory System" << endl;
    cout << "======================================" << endl;

    // 1. Create Items
    // Uses: Custom Constructor, Dynamic Strings (setName)
    Item apple("Gala Apple", 1001, 1.25);
    Item banana("Organic Banana", 1002, 0.99);
    Item laptop("MacBook Pro", 5005, 1999.99);

    // 2. Create the Shopping Cart
    // Uses: Cart Constructor
    Cart myCart;

    // 3. Add Items to Cart
    // Uses: Cart::operator+=, Cart::resize, Item pointer array
    cout << "\n--- Adding Items to Cart ---" << endl;
    myCart += apple;
    myCart += banana;
    
    // Test Resizing: Adding a 3rd item should trigger resize() 
    // (if initial capacity was 2)
    myCart += laptop; 
    
    // 4. Update Stock (Operator Overloading)
    // Uses: Item::operator+= (Chaining)
    cout << "--- Updating Stock ---" << endl;
    apple += 5; // Adds 5 to quantity
    cout << "Added 5 Apples." << endl;

    // 5. Display Cart
    // Uses: Cart::display, Item::display, Private Access (friend)
    cout << "\n--- Current Cart Receipt ---" << endl;
    myCart.display();

    // 6. Remove an Item
    // Uses: Cart::operator-= (Shift Logic)
    cout << "\n--- Removing Banana (1002) ---" << endl;
    myCart -= 1002;
    
    // 7. Final Display
    cout << "\n--- Final Receipt ---" << endl;
    myCart.display();

    cout << "\nExiting program..." << endl;
    return 0;
}