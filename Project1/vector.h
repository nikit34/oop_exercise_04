#pragma once

#ifndef VECTOR_H
#define VECTOR_H

#include <tuple>
#include "point.h"


template<typename T>
class Vector {
public:
	Vector(T x_cord, T y_cord);
	Vector(Point<T>& p1, Point<T>& p2);

	T operator*(const Vector& a) const;
	Vector<T>& operator=(const Vector& a);

	//SumSquare(std::tuple figuries);
	//Print(const Vector& a);

	T x, y;
};

template<typename T>
T Length(const Point<T>& a, const Point<T>& b);

template<typename T>
T Length(const Vector<T>& a);


template<typename T>
bool isParallel(const Vector<T>& a, const Vector<T>& b);

#endif