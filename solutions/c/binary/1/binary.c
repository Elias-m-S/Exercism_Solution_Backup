#include "binary.h"
#include <string.h>


int convert(const char *input){
int decimal = 0;
for(size_t i= 0; input[i] != '\0'; i++){
    if (input[i] != '0' && input[i] != '1'){
        return INVALID;
    }
    decimal = 2 * decimal + (input[i] - '0');
}
return decimal;
}


