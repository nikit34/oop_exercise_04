#pragma once

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>


template<typename T>
class Point {
public:
	Point();
	Point(T a, T b);
	Point(const Point& other);

	Point<T> operator+ (const Point<T>& a);
	Point<T> operator- (const Point<T>& a);
	Point<T> operator* (T&& a);
	Point<T> operator/ (T&& a);

	//friend std::ostream& operator<< (std::ostream& out, const Point& a);
	//friend std::istream& operator>> (std::istream& in, Point& a);

	std::pair<T, T> coord;
};

template<typename T>
Point<T>::Point() {}

template<typename T>
Point<T>::Point(T a, T b) : coord{ a, b } {}

template<typename T>
Point<T>::Point(const Point& other) : coord{ other.coord } {}

template<typename T>
Point<T> Point<T>::operator+ (const Point<T>& a) {
	this->coord = { this->coord.first + a.coord.first, this->coord.second + a.coord.second };
	return *this;
}

template<typename T>
Point<T> Point<T>::operator- (const Point<T>& a) {
	this->coord = { this->coord.first - a.coord.first, this->coord.second - a.coord.second };
	return *this;
}

template<typename T>
Point<T> Point<T>::operator* (T&& a) {
	this->coord = { this->coord.first * a, this->coord.second * a };
	return *this;
}

template<typename T>
Point<T> Point<T>::operator/ (T&& a) {
	this->coord = { this->coord.first / a, this->coord.second / a };
	return *this;
}



//template<typename T>
//std::ostream& operator<< (std::ostream& out, const Point<T>& a) {
//	out << "( " << a.x << ", " << a.y << " )";
//	return out;
//}
//
//template<typename T>
//std::istream& operator>> (std::istream& in, Point<T>& a) {
//	in >> a.x >> a.y;
//	return in;
//}

#endif
