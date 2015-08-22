#include "Linear.hpp"

float Easings::Linear::easeNone (float t,float b , float c, float d) {
	return c*t/d + b;
}

float Easings::Linear::easeIn (float t,float b , float c, float d) {
	return c*t/d + b;
}

float Easings::Linear::easeOut(float t,float b , float c, float d) {	
	return c*t/d + b;
}

float Easings::Linear::easeInOut(float t,float b , float c, float d) {
	return c*t/d + b;
}