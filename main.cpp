#include <iostream>

#include <tuple>
#include "rectangle.h"
#include "quadrate.h"
#include "triangle.h"


void printHelp() {

    std::cout << "'1'           - Create rectangle" << std::endl;
    std::cout << "'2'           - Create square" << std::endl;
    std::cout << "'3'           - Create triangle" << std::endl;
    std::cout << "'4'           - Print coords" << std::endl;
    std::cout << "'5'           - Total Square" << std::endl;
    std::cout << "'0'           - Exit" << std::endl;
}

enum {
    quit,
    add_rectangle,
    add_square,
    add_triangle,
    all_print,
    sum_area
};


template<typename T, uint8_t index>
typename std::enable_if<index == std::tuple_size<T>::value, void>::type Print(T&) {
    std::cout << std::endl;
}

template<typename T, uint8_t index>
typename std::enable_if<index < std::tuple_size<T>::value, void>::type Print(T& tuple) {
    auto item = std::get<index>(tuple);
    std::cout << "Coords of " << typeid(item).name() << ":\t";
    itemPrint(item);
    Print<T, index + 1>(tuple);
}

template<typename T>
typename std::enable_if<(sizeof(T) / sizeof(T::P[0]) > 0), void>::type itemPrint(T& vertex) {
    for (auto v : vertex.P)
        std::cout << " ( " << v.coord.first << ", " << v.coord.second << " ) ";
    std::cout << std::endl;
}

template <class T, uint8_t index>
double Square(T& tuple) {
    auto item = std::get<index>(tuple);
    double value = itemSquare(item);

    if constexpr ((index + 1) < std::tuple_size<T>::value) {
        return value + Square<T, index + 1>(tuple);
    }
    return value;
}

template <class T>
auto itemSquare(T& vertex) {
    auto area = 0;
    for (int i = 0; i < (sizeof(T) / sizeof(T::P[0])) - 1; ++i)
        area += (vertex.P[i + 1].coord.first - vertex.P[i].coord.first) * (vertex.P[i + 1].coord.second + vertex.P[i].coord.second);
    return std::abs(area) / 2.0;
}


int main() {
    int cmd;
    double left, right;
    unsigned int i;

    Rectangle<int> rec;
    rec.P[0].coord = { 0, 0 };
    rec.P[1].coord = { 0, 10 };
    rec.P[2].coord = { 10, 10 };
    rec.P[3].coord = { 10, 0 };
    
    Quadrate<double> qua;
    qua.P[0].coord = { 3.56, 0.6 };
    qua.P[1].coord = { 3.56, 1.6 };
    qua.P[2].coord = { 3.96, 1.6 };
    qua.P[3].coord = { 3.96, 0.6 };

    Triangle<double> tri;
    tri.P[0].coord = { -1, 8.1 };
    tri.P[1].coord = { -3.56, 8.1 };
    tri.P[2].coord = { -3.56, 1.6 };
    std::tuple<Rectangle<int>, Quadrate<double>, Triangle<double>> basic_set{rec, qua, tri};

    while (true) {
        printHelp();
        std::cin >> cmd;
        std::cout << std::endl;
        switch (cmd) {
        case add_rectangle: {
            Rectangle<int> rec;
            for (i = 0; i < 4; ++i) {
                std::cout << std::endl << "enter " << i << " pair: ";
                std::cin >> left >> right;
                rec.P[i].coord = { left, right };
            }
            std::get<0>(basic_set) = rec;
            break;
        }
        case add_square: {
            Quadrate<double> que;
            for (i = 0; i < 4; ++i) {
                std::cout << std::endl << "enter " << i << " pair: ";
                std::cin >> left >> right;
                que.P[i].coord = { left, right };
            }
            std::get<1>(basic_set) = que;
            break;
        }
        case add_triangle: {
            Triangle<double> tri;
            for (i = 0; i < 3; ++i) {
                std::cout << std::endl << "enter " << i << " pair: ";
                std::cin >> left >> right;
                tri.P[i].coord = { left, right };
            }
            std::get<2>(basic_set) = tri;
            break;
        }
        case all_print: {
            Print<decltype(basic_set), 0>(basic_set);
            break;
        }
        case sum_area: {
            std::cout << "Total square: " << Square<decltype(basic_set), 0>(basic_set) << std::endl << std::endl;
            break;
        }
        case quit: {
            return 0;
        }
        default: {
            std::cout << "Undefined cmd" << std::endl;
        }
        }
    }
	return 0;
}

