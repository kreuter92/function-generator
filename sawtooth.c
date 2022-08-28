#include <math.h>

float sawtooth(float time){
	return 2*(time-floor(time+0.5));
}
