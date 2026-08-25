#include "eliuds_eggs.h"
unsigned int egg_count(unsigned int egg_number){
    int count = 0;
    while (egg_number != 0){
        count = count + (egg_number & 1);
        egg_number >>= 1;
    }
    return count;
}