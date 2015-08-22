#ifndef _PENNER_SINE
#define _PENNER_SINE

#include <math.h>

#ifndef PI
#define PI  3.14159265
#endif

namespace Easings {
namespace Sine {
		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
		
};
};

#endif