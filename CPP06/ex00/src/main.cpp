#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./Converter <literal>" << std::endl;
        return 1;
    }

    ScalarConverter::convert(argv[1]);
    return 0;
}

//3.5e+38
//1.8e+308
