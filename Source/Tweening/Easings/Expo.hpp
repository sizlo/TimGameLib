#ifndef _PENNER_EXPO
#define _PENNER_EXPO

#include <math.h>

namespace Easings {
namespace Expo {
		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
};
};

#endif