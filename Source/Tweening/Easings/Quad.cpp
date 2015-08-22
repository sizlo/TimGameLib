#include "Quad.hpp"

float Easings::Quad::easeIn (float t,float b , float c, float d) {
    t/=d;
	return c*(t)*t + b;
}

float Easings::Quad::easeOut(float t,float b , float c, float d) {
    t/=d;
	return -c *(t)*(t-2) + b;
}

float Easings::Quad::easeInOut(float t,float b , float c, float d) {
	/* This function is broken
    
    if ((t/=d/2) < 1) return ((c/2)*(t*t)) + b;
	return -c/2 * (((t-2)*(--t)) - 1) + b;
     */
	/*
     originally return -c/2 * (((t-2)*(--t)) - 1) + b;
     
     I've had to swap (--t)*(t-2) due to diffence in behaviour in
     pre-increment operators between java and c++, after hours
     of joy
     */
    
	// Here is my fix
    if (t < d/2) // If we're in the first half ease in
        return easeIn(t, b, c/2, d/2);
    else // Else ease out
        return easeOut(t -(d/2), b +(c/2), c/2, d/2);
}