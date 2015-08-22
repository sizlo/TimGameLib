#include "Quart.hpp"

float Easings::Quart::easeIn (float t,float b , float c, float d) {
    t/=d;
	return c*(t)*t*t*t + b;
}

float Easings::Quart::easeOut(float t,float b , float c, float d) {
    t=t/d-1;
	return -c * ((t)*t*t*t - 1) + b;
}

float Easings::Quart::easeInOut(float t,float b , float c, float d) {
	if ((t/=d/2) < 1) return c/2*t*t*t*t + b;
    t-=2;
	return -c/2 * ((t)*t*t*t - 2) + b;
}