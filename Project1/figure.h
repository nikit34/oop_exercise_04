
#pragma once

#ifndef FIGURE_H
#define FIGURE_H

#include "rectangle.h"
#include "triangle.h"
#include "square.h"


template<typename T>
class Figure {
public:
	virtual ~Figure() = default;

	//virtual Point Center() const = 0;
	//virtual double Area() const = 0;

	void Print(T& figs, const int& index);
};

//std::ostream& operator<< (std::ostream& out, const Figure& fig);
//std::istream& operator>> (std::istream& in, Figure& fig);

#endif