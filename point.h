#pragma once

#include <iostream>
#include <cmath>


template<typename T>
class Point {
public:
	Point();
	Point(T a, T b);
	Point(const Point& other);
	virtual ~Point() {};

	Point<T> operator+ (const Point<T>& a);
	Point<T> operator- (const Point<T>& a);
	Point<T> operator* (T&& a);
	Point<T> operator/ (T&& a);

	void Print(const Point<T>& a);
	friend std::istream& operator>> (std::istream& in, Point& a);

	std::pair<T, T> coord;
};

template<class T>
Point<T>::Point() {}

template<class T>
Point<T>::Point(T a, T b) : coord{ a, b } {}

template<class T>
Point<T>::Point(const Point& other) : coord{ other.coord } {}

template<class T>
Point<T> Point<T>::operator+ (const Point<T>& a) {
	this->coord = { this->coord.first + a.coord.first, this->coord.second + a.coord.second };
	return *this;
}

template<class T>
Point<T> Point<T>::operator- (const Point<T>& a) {
	this->coord = { this->coord.first - a.coord.first, this->coord.second - a.coord.second };
	return *this;
}

template<class T>
Point<T> Point<T>::operator* (T&& a) {
	this->coord = { this->coord.first * a, this->coord.second * a };
	return *this;
}

template<class T>
Point<T> Point<T>::operator/ (T&& a) {
	this->coord = { this->coord.first / a, this->coord.second / a };
	return *this;
}

template<class T>
void Point<T>::Print(const Point<T>& a) {
	std::cout << "point ( " << this->coord.first << ", " << this->coord.second << " )" << std::endl;
}

template<class T>
std::istream& operator>> (std::istream& in, Point<T>& a) {
	in >> a.coord.first >> a.coord.second;
	return in;
}
