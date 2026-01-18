#include <iostream>
#include "io.h"
using namespace std;

namespace seneca {
    void read(char *name){
        cout<<"name >/n "<<endl;
        cin >> name;
    }

    void print(long long phone){
        int area = phone / 10000000;
        int prefix = (phone / 10000) % 1000;
        int suffix = phone % 10000;

        cout << "(" << area << ")" << prefix << "-" << suffix;
    }

    void print(const PhoneRec& rec, size_t& row, const char* filter){

        if (!filter || strstr(rec.firstName, filter) || strstr(rec.lastName, filter)){
          cout << row << ": " << rec.firstName << " " << rec.lastName << " ";

          print(rec.PhoneNumber);

          cout << endl;

          row++;
        }
    }

    bool read(PhoneRec& record, FILE* fptr){
        int readCount = fscanf(fptr, "%s %s %lld", record.firstName, record.lastName, &record.PhoneNumber);

        return readCount == 3;
    }

    void print(PhoneRec* records[], size_t num, const char* filter){
        size_t row = 1;

        for (size_t i=0; i< num; i++) {
            print(*records[i],row,filter);
        }
    }

    void setPointers(PhoneRec* pointers[], PhoneRec records[], size_t num){
        for (size_t i = 0; i < num; i++) {
            pointers[i] = &records[i];
        }
    }

    void sort (PhoneRec* pointers[], size_t num, bool byLastName){
        for (size_t i = 0; i < num -1; i++){
            for (size_t j = i +1; j<num; j++) {
                int result;

                if (byLastName) {
                    result = strcmp(pointers[i]->lastName, pointers[j]->lastName);
                } else {
                    result = strcmp(pointers[i]->firstName, pointers[j]->firstName);
                }
                if (result > 0){
                    PhoneRec* temp = pointers[i];
                    pointers[i] = pointers[j];
                    pointers[j] = temp;
                }
            }
        }
    }


}