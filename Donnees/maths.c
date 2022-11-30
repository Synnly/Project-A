#include "maths.h"
#include "constantes.h"
#include <math.h>

float max(float val1, float val2){
    if(val1>=val2){
        return val1;
    }
    return val2;
}

float min(float val1, float val2){
    if(val1<=val2){
        return val1;
    }
    return val2;
}

float pythagore(float c) {
    return sqrt((pow(c , 2)/2));
}

int floatEquals(float f1, float f2){
    return fabs(f1-f2)<EPSILON;
}
