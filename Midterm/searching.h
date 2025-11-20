// searching.h
#ifndef SEARCHING_H
#define SEARCHING_H

int linearSearch(int dataset[], int size, int item);


// searching.cpp
#include "searching.h"

int linearSearch(int dataset[], int size, int item) {
    for (int i = 0; i < size; i++) {
        if (dataset[i] == item) {
            return i;  // Item found, return the index
        }
    }
    return -1;  // Item not found
}




#endif