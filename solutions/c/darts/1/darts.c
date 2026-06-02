#include "darts.h"
#include <math.h>

static float distanceToCenter (coordinate_t landing_position)
{
    float x = landing_position.x;
    float y = landing_position.y;
    
     return sqrt(x*x + y*y);
   
}

uint8_t score (coordinate_t landing_position){

    float distance = distanceToCenter(landing_position);
    if (distance <= 1.0F) {
        return 10;
    } 
    else if (distance <= 5.0F) {
        return 5;
    } 
    else if (distance <= 10.0F) {
        return 1;
    } 
    else {
        return 0; 
    }
}