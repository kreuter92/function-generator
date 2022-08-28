#include <stdio.h>
#include <math.h>

float rectfct(float time){
    if (sinf(time)>0){
	    return 1.0;
    }
    else if (sinf(time)==0){
	    return 0.0;
    }
    else
	    return -1.0;
}
