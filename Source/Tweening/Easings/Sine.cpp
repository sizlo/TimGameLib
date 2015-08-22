#include "Sine.hpp"

float Easings::Sine::easeIn (float t,float b , float c, float d) {
	return -c * cos(t/d * (PI/2)) + c + b;
}

float Easings::Sine::easeOut(float t,float b , float c, float d) {	
	return c * sin(t/d * (PI/2)) + b;	
}

float Easings::Sine::easeInOut(float t,float b , float c, float d) {
	return -c/2 * (cos(PI*t/d) - 1) + b;
}