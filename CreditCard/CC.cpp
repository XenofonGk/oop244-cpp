

#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;


namespace seneca {

    void CC::aloCopy(const char* name){
        cleanUp();
        if (name != nullptr){
            int len = strlen(name);
            m_name = new char[len + 1];
            strcpy(m_name, name);
        }
    }

    void CC::cleanUp() {
        delete[] m_name;
        m_name = nullptr;
    }


    bool CC::validate(const char* name, unsigned long long cardNo, short cvv,
                      short expMonth, short expYear) const {
        if (name == nullptr || strlen(name) <= 2) {
             return false; }
        if (cardNo < 4000000000000000ull || cardNo > 4099999999999999ull) {
            return false; }
        if (cvv < 100 || cvv > 999) {
            return false; }
        if (expMonth < 1 || expMonth > 12) {
            return false; }
        if (expYear < 24 || expYear > 32) {
            return false;
        }
            return true;
        }


    void CC::prnNumber(unsigned long long CCnum) const {
        cout << (CCnum / 1000000000000ull) << " ";
        CCnum %= 1000000000000ull;

        cout.width(4);
        cout.fill('0');
        cout << (CCnum / 100000000ull) << " ";
       
        CCnum %= 100000000ull;

        cout.width(4);
        cout.fill('0');
        cout << (CCnum / 10000ull) << " ";

        CCnum %= 10000ull;

        cout.width(4);
        cout.fill('0');
        cout << CCnum;
    }

   void CC::display(const char* name, unsigned long long number, short expYear, 
                    short expMon, short cvv) const {
    char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(30);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << lname << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout.fill(' ');
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);
    }
   
    void CC::set(){
        cleanUp();

        m_name = nullptr;
        m_cvv = 0;
        m_month = 0;
        m_year = 0;
        m_number = 0;
    }

    bool CC::isEmpty() const{
      return ( m_name == nullptr);
    }

    CC::~CC() {
        cleanUp();
    }

    void CC::set(const char* cc_name,  unsigned long long cc_no, 
            short cvv, short expMon,  short expYear){
        set();
        if (validate(cc_name,cc_no,cvv, expMon, expYear) == true){
            aloCopy(cc_name);
            m_number = cc_no;
            m_cvv = cvv;
            m_month = expMon;
            m_year = expYear;
        }
    }

CC::CC(){
    set();
}

CC::CC(const char* name, unsigned long long number, short cvv,
        short expMon,short expYear){
            set(name, number, cvv, expMon , expYear);
        }

void CC::display() const {
    if (isEmpty()) {
        cout << "Invalid Credit Card Record" << endl;
    } else { 
        display(m_name ,m_number ,m_year ,m_month , m_cvv );
    }  
}

}