#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>      
#include <limits>
#include <cmath>        
#include <iomanip>      
#include <cctype>       

static bool isPseudo(const std::string& s) {
    return s == "nan"   || s == "+inf"  || s == "-inf"
        || s == "nanf"  || s == "+inff" || s == "-inff";
}

static bool matchInt(const std::string& s) {
    size_t i = 0;
    if (s[i]=='+'||s[i]=='-') i++;
    if (i >= s.size()) return false;
    for (; i < s.size(); ++i)
        if (!std::isdigit(s[i])) return false;
    return true;
}

static bool matchFloat(const std::string& s) {
    if (s.size() < 2 || s.back() != 'f') return false;
    std::string t = s.substr(0, s.size()-1);
    size_t i = 0; if (t[i]=='+'||t[i]=='-') i++;
    bool dot = false, digit = false;
    for (; i < t.size(); ++i) {
        if (t[i] == '.') {
            if (dot) return false;
            dot = true;
        } else if (std::isdigit(t[i])) {
            digit = true;
        } else return false;
    }
    return dot && digit;
}

static bool matchDouble(const std::string& s) {
    size_t i = 0; if (s[i]=='+'||s[i]=='-') i++;
    bool dot = false, digit = false;
    for (; i < s.size(); ++i) {
        if (s[i] == '.') {
            if (dot) return false;
            dot = true;
        } else if (std::isdigit(s[i])) {
            digit = true;
        } else return false;
    }
    return dot && digit;
}

static void printChar(double d, bool invalid) {
    std::cout << "char: ";
    if (invalid || std::isnan(d) || std::isinf(d)
        || d < std::numeric_limits<char>::min()
        || d > std::numeric_limits<char>::max())
    {
        std::cout << "impossible\n";
    } else {
        char c = static_cast<char>(d);
        if (std::isprint(c))
            std::cout << "'" << c << "'\n";
        else
            std::cout << "Non displayable\n";
    }
}

static void printInt(double d, bool invalid) {
    std::cout << "int: ";
    if (invalid || std::isnan(d) || std::isinf(d)
        || d < std::numeric_limits<int>::min()
        || d > std::numeric_limits<int>::max())
    {
        std::cout << "impossible\n";
    } else {
        std::cout << static_cast<int>(d) << "\n";
    }
}

static void printFloat(double d, const std::string& lit) {
    std::cout << "float: ";
    if      (lit == "nan"  || lit == "nanf")  std::cout << "nanf\n";
    else if (lit == "+inf" || lit == "+inff") std::cout << "+inff\n";
    else if (lit == "-inf" || lit == "-inff") std::cout << "-inff\n";
    else if (std::isnan(d))                   std::cout << "nanf\n";
    else if (std::isinf(d))                   std::cout << (d < 0 ? "-inff\n" : "+inff\n");
    else if (d < -std::numeric_limits<float>::max()
          || d >  std::numeric_limits<float>::max())
    {
        std::cout << "impossible\n";
    } else {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1)
            << static_cast<float>(d);
        std::cout << oss.str() << "f\n";
    }
}

static void printDouble(double d, const std::string& lit) {
    std::cout << "double: ";
    if      (lit == "nan"  || lit == "nanf")  std::cout << "nan\n";
    else if (lit == "+inf" || lit == "+inff") std::cout << "+inf\n";
    else if (lit == "-inf" || lit == "-inff") std::cout << "-inf\n";
    else if (std::isnan(d))                   std::cout << "nan\n";
    else if (std::isinf(d))                   std::cout << (d < 0 ? "-inf\n" : "+inf\n");
    else {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1) << d;
        std::cout << oss.str() << "\n";
    }
}

void ScalarConverter::convert(const std::string& lit) {
    double        d       = 0.0;
    bool          invalid = false;

    if (lit.size() == 3 && lit.front() == '\'' && lit.back() == '\'') {
        d = static_cast<double>(lit[1]);
    }
    else if (isPseudo(lit)) {
        invalid = false;
        if (lit.back() == 'f')
            d = std::strtof(lit.c_str(), NULL);
        else
            d = std::strtod(lit.c_str(), NULL);
    }
    else if (matchInt(lit)) {
        long l = std::strtol(lit.c_str(), NULL, 10);
        d = static_cast<double>(l);
    }
    else if (matchFloat(lit)) {
        std::string tmp = lit.substr(0, lit.size()-1);
        d = std::strtof(tmp.c_str(), NULL);
    }
    else if (matchDouble(lit)) {
        d = std::strtod(lit.c_str(), NULL);
    }
    else {
        invalid = true;
    }

    printChar(d, invalid);
    printInt (d, invalid);
    printFloat(d, lit);
    printDouble(d, lit);
}
