

    #ifndef SENECA_CC_H
    #define SENECA_CC_H
    #include "cstr.h"
    #include <iostream>

    namespace seneca {
    class CC{
    private:
        char* m_name{nullptr};
        unsigned long long m_number{};
        short m_cvv{};
        short m_month{};
        short m_year{};

        // --- Private functions ---
        void cleanUp();
        void aloCopy(const char* name);
        bool validate(const char* name, unsigned long long cardNo, short cvv,
                        short expMonth, short expYear) const;
        void prnNumber(unsigned long long CCnum) const;
        void display(const char* name, unsigned long long number, short expYear, 
                        short expMon, short cvv) const;
    
    public:
    CC();
        CC(const char* name, unsigned long long number, short cvv,
            short expMon=12,short expYear=26);
        void set();
        bool isEmpty() const;
        void set(const char* cc_name,  unsigned long long cc_no, 
                short cvv, short expMon,  short expYear);
        void display() const;
    ~CC();
    };
    }
    #endif