#ifndef _PENNER_CIRC
#define _PENNER_CIRC

#include <math.h>

namespace Easings {
namespace Circ {
		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
};
};

#endif