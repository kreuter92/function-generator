#include <math.h>

float triangfct(float time){
	return 4*(fabs(time-floor(time+0.75)+0.25))-1;
}
