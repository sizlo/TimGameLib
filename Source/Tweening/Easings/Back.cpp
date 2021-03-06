#include "Back.hpp"

float Easings::Back::easeIn (float t,float b , float c, float d) {
	float s = 1.70158f;
	float postFix = t/=d;
	return c*(postFix)*t*((s+1)*t - s) + b;
}

float Easings::Back::easeOut(float t,float b , float c, float d) {	
	float s = 1.70158f;
    t = t/d-1;
	return c*((t)*t*((s+1)*t + s) + 1) + b;
}

float Easings::Back::easeInOut(float t,float b , float c, float d) {
	float s = 1.70158f;
	s*=(1.525f);
	if ((t/=d/2) < 1) return c/2*(t*t*(((s)+1)*t - s)) + b;
	float postFix = t-=2;
	s*=(1.525f);
	return c/2*((postFix)*t*(((s)+1)*t + s) + 2) + b;
}