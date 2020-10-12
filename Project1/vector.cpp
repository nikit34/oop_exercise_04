#include "vector.h"

template<typename T>
Vector<T>::Vector(T x_cord, T y_cord) : x{ x_cord }, y{ y_cord } {}

template<typename T>
Vector<T>::Vector(Point<T>& p1, Point<T>& p2) : x{ p2.X() - p1.X() }, y{ p2.Y() - p1.Y() } {}

template<typename T>
T Vector<T>::operator*(const Vector& a) const {
	return (this->x * a.x) + (this->y * a.y);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& a) {
	this->x = a.x;
	this->y = a.y;
	return *this;
}

template<typename T>
T Length(const Point<T>& a, const Point<T>& b) {
	return sqrt(pow((b.X() - a.X()), 2) + pow((b.Y() - a.Y()), 2));
}

template<typename T>
T Length(const Vector<T>& a) {
	return sqrt(pow(a.x, 2) + pow(a.y, 2));
}

template<typename T>
bool isParallel(const Vector<T>& a, const Vector<T>& b) {
	return (a.x * b.y) - (a.y * b.x) == 0;
}


//template<typename T>
//void Vector<T>::Print(figuries) {
//	for (std::tuple fig : figuries) {
//		fig->Print();
//	}
//}
//
//
//template<typename T>
//double Vector<T>::SumSquare(figuries) {
//	double sum_area = 0;
//	for (std::tuple fig : figuries) {
//		sum_area += fig->Area();
//	}
//	return sum_area;
//}