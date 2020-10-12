#pragma once

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vector.h"

template<typename T>
class Triangle {
public:
	Point<T> A, B, C;
};

//template<typename T>
//std::ostream& operator<< (std::ostream& out, Triangle<T> fig) {
//	out << fig.A;
//	return out;
//}

#endif