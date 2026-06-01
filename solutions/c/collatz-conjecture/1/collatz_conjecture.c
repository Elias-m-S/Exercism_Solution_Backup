#include "collatz_conjecture.h"

int steps(int start){
    if (start < 1){
        return -1;
    }
    int count = 0;
    while (start>1){
        if (number_is_even(start)){
            start = start /2;
            count++;
        }
        else 
        {
            start = start*3 +1;
            count++;
        }
            
    }
    return count;
}

bool number_is_even(int number){
    return (number%2 == 0);
}