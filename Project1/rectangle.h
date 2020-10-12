#pragma once

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "vector.h"


template<typename T>
class Rectangle {
public:
	Point<T> A, B, C, D;
};


//template<typename T>
//std::ostream& operator<< (std::ostream& out, Rectangle<T> fig) {
//	out << fig.A;
//	return out;
//}

#endif