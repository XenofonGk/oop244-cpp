# MarketPlus 🛒
### A Dynamic C++ Inventory & Shopping Engine

**MarketPlus** is a lightweight, memory-efficient C++ application that simulates the backend logic of an e-commerce shopping cart. It demonstrates advanced Object-Oriented Programming concepts, including manual dynamic memory management, operator overloading, and pointer-based data structures.

---

##  Key Features

* **Dynamic Memory Management:** Manually handles memory allocation/deallocation (`new`/`delete`) for strings and arrays to prevent memory leaks.
* **Smart Resizing:** The `Cart` automatically expands its capacity when full, simulating `std::vector` logic from scratch.
* **Operator Overloading:** Uses natural syntax for complex operations:
    * `cart += item` (Add to cart)
    * `cart -= sku` (Remove from cart by ID)
    * `item += 5` (Restock item quantity)
* **Deep Copy Logic:** Ensures dynamic strings (like product names) are safely copied and managed.
* **Friend Classes:** Implements secure encapsulation while allowing tightly coupled classes (`Cart` and `Item`) to interact efficiently.

---

##  Technical Concepts Demonstrated

This project was built to practice and demonstrate the following C++ core competencies:

* **Pointers & Arrays:** Managing an array of pointers (`Item**`) to store objects efficiently.
* **Encapsulation:** Protecting data using `private` members and controlling access via `friend` classes.
* **Constructors & Destructors:** Managing the complete lifecycle of objects to ensure "Safe Empty States" and clean memory release.
* **The "this" Pointer:** Enabling method chaining (e.g., `cart += apple += banana;`).
* **File Modularity:** Separation of Interface (`.h`), Implementation (`.cpp`), and Client Code (`main.cpp`).

---

##  How to Build and Run

This project requires a standard C++ compiler (like `g++` or `clang`).

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/your-username/MarketPlus.git](https://github.com/your-username/MarketPlus.git)
   cd MarketPlus