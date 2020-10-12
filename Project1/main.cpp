#include <iostream>

#include "figure.h"


void print_help() {

    std::cout << "'1'           - Create square" << std::endl;
    std::cout << "'2'           - Create rectangle" << std::endl;
    std::cout << "'3'           - Create triangle" << std::endl;
    std::cout << "'4'           - Tuple" << std::endl;
    std::cout << "'0'           - Exit" << std::endl;
}

enum {
    add_rectangle,
    add_square,
    add_triangle,
    sum_area,
    quit
};

int main() {
    //int cmd;
    Rectangle<int> rec;
    rec.A.coord = { 0, 0 };
    rec.B.coord = { 0, 10 };
    rec.C.coord = { 10, 10 };
    rec.D.coord = { 10, 0 };
    
    Square<double> squ;
    squ.A.coord = { 3.56, 0.6 };
    squ.B.coord = { 3.56, 1.6 };
    squ.C.coord = { 3.96, 1.6 };
    squ.D.coord = { 3.96, 0.6 };

    Triangle<float> tri;
    tri.A.coord = { -1, 8.1 };
    tri.B.coord = { -3.56, 8.1 };
    tri.C.coord = { -3.56, 1.6 };


    //std::tuple<Rectangle<int>, Square<double>, Triangle<float>> basic_set{rec, squ, tri};

    //Figure<Rectangle<int>> figs;
    //figs.Print(basic_set[0]);

    //std::cout << std::get<1>(basic_set);

   /* while (true) {
        print_help();
        std::cin >> cmd;
        std::cout << std::endl;
        switch (cmd) {
        case add_rectangle: {
               
            break;
        }
        case add_square: {
            break;
        }
        case add_triangle: {
            break;
        }
        case sum_area: {
            break;
        }
        case quit: {
            return 0;
            break;
        }
        default: {
            std::cout << "Undefined cmd" << std::endl;
        }
        }

    }*/
	return 0;
}

