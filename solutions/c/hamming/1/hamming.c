#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs){  
    int hamming_distance = 0;
    if (strlen(lhs) != strlen(rhs)){
        return -1;
    }
    unsigned int size = strlen(lhs);
    for (unsigned int i = 0; i < size; i++){
        if (lhs[i] != rhs[i]){
            hamming_distance++;
        }
    }
    return hamming_distance;
}