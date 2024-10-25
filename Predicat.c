#include "Predicat.h"
#include <math.h>

int isEqual(PTYPE a, PTYPE b){
    PTYPE eps = 0.00001;
    return fabs(a-b) < eps;
}

int isEqual2(TVECT a, TVECT b){
    
    return isEqual(a.x,b.x) && isEqual(a.y,b.y);
}

