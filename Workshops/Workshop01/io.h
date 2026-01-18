// moduleName.h

#ifndef SENECA_IO_H
#define SENECA_IO_H

namespace seneca {

    struct PhoneRec{
        char firstName[15];
        char lastName[25];
        long long PhoneNumber;

    };

    void read(char *name);

    void print(long long phone);

    void print(const PhoneRec& rec, size_t& row, const char* filter);

    bool read(PhoneRec& record, FILE* fptr);

    void print(PhoneRec* records[], size_t num, const char* filter = nullptr);

    void setPointers(PhoneRec* pointers[], PhoneRec records[], size_t num);

    void sort (PhoneRec* pointers[], size_t num, bool byLastName);



}
#endif // !THENAMESPACE_MODULENAME_H