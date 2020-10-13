#pragma once

#include "rectangle.h"
#include "square.h"
#include "triangle.h"

template<typename T>
class Figure {
public:
	Figure();
	//Figure(T& a);
	virtual ~Figure() {};

	//void Print(const int& index);

};

//std::ostream& operator<< (std::ostream& out, const Figure& fig);
//std::istream& operator>> (std::istream& in, Figure& fig);

template<typename T>
Figure<T>::Figure() { *this = T; };

//template<typename T>
//Figure<T>::Figure(T& a) { this->fig = a; };

/*std::ostream& operator<< (std::ostream& out, const Figure& fig) {
	out << fig;
	return out;
}*/

//template<typename T>
//void Figure<T>::Print(const int& index) {*/
//	auto fig = std::get<index>(fig);
//	
//	for (auto &vertex : fig)
//		std::cout << "(" << vertex.first << "," << vertex.second << ") ";
//	std::cout << std::endl;
//}


/*std::istream& operator>> (std::istream& in, Figure& fig) {
	in << decltype(fig);
	return in;
}*/