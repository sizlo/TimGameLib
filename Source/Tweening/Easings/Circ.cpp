#include "Circ.hpp"

float Easings::Circ::easeIn (float t,float b , float c, float d) {
	t/=d;
	return -c * (sqrt(1 - (t)*t) - 1) + b;
}

float Easings::Circ::easeOut(float t,float b , float c, float d) {
	t=t/d-1;
	return c * sqrt(1 - (t)*t) + b;
}

float Easings::Circ::easeInOut(float t,float b , float c, float d) {
	if ((t/=d/2) < 1) return -c/2 * (sqrt(1 - t*t) - 1) + b;
	t-=2;
	return c/2 * (sqrt(1 - t*(t)) + 1) + b;
}