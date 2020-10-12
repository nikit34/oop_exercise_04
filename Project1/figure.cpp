#include "figure.h"

/*std::ostream& operator<< (std::ostream& out, const Figure& fig) {
	out << fig;
	return out;
}*/

template<typename T>
void Figure<T>::Print(T& figs, const int& index) {
	auto fig = std::get<index>(figs);
	
	for (auto &vertex : fig)
		std::cout << "(" << vertex.first << "," << vertex.second << ") ";
	std::cout << std::endl;
}


/*std::istream& operator>> (std::istream& in, Figure& fig) {
	in << decltype(fig);
	return in;
}*/