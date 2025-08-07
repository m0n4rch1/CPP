#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib> // rand
#include <ctime>   // time

int main() {
    try {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Big test with 10,000 numbers
        Span bigSpan(10000);
        std::srand(std::time(0));
        std::vector<int> bigVec;
        for (int i = 0; i < 10000; ++i)
            bigVec.push_back(std::rand());

        bigSpan.addNumbers(bigVec.begin(), bigVec.end());
        std::cout << "Big test shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big test longest span: " << bigSpan.longestSpan() << std::endl;

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
