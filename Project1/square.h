#pragma once

#ifndef SQUARE_H
#define SQUARE_H

#include "vector.h"

template<typename T>
class Square {
public:
	Point<T> A, B, C, D;
};

//template<typename T>
//std::ostream& operator<< (std::ostream& out, Square<T> fig) {
//	out << fig.A;
//	return out;
//}

#endif