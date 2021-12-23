/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 02:01:01 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/23 02:14:16 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <cctype>
#include <limits>

enum e_literal_type
{
    NONE,
    CHAR,
    INT,
    FLOAT_REGULAR,
    FLOAT_NAN,
    FLOAT_INF,
    FLOAT_NEG_INF,
    DOUBLE_REGULAR,
    DOUBLE_NAN,
    DOUBLE_INF,
    DOUBLE_NEG_INF
};

template <typename T>
bool in_range(const T& d, const T& min, T& max)
{
    return (d >= min && d <= max);
}

e_literal_type get_type_wo_validation(const std::string& literal)
{
    // handling special cases
    if (literal == "nanf")
        return FLOAT_NAN;
    if (literal == "inff")
        return FLOAT_INF;
    if (literal == "-inff")
        return FLOAT_NEG_INF;
    if (literal == "nan")
        return DOUBLE_NAN;
    if (literal == "inf")
        return DOUBLE_INF;
    if (literal == "-inf")
        return DOUBLE_NEG_INF;
    if (literal.length() == 0)
        return NONE;
    if (literal.length() < 2) // Can be either a char or an int
    {
        if (static_cast<std::string>("0123456789").find(literal) != std::string::npos)
            return INT;
        return CHAR;
    }
    if (literal.find('f') != std::string::npos)
        return FLOAT_REGULAR;
    if (literal.find('.') != std::string::npos)
        return DOUBLE_REGULAR;
    return INT;
}

e_literal_type get_type(const std::string& literal)
{
    e_literal_type type = get_type_wo_validation(literal);
    
    std::stringstream ss;
    
    switch (type)
    {
    case FLOAT_NAN:
    case FLOAT_NEG_INF:
    case FLOAT_INF:
    case DOUBLE_NAN:
    case DOUBLE_NEG_INF:
    case DOUBLE_INF:
        // no validation required
        return type;
    case NONE:
        return NONE;
    case CHAR:
        ss << literal;
        char c;
        ss >> c >> std::ws;
        if (ss.fail() || !ss.eof())
            return NONE;
        return CHAR;
    case INT:
        ss << literal;
        int i;
        ss >> i;
        if (ss.fail() || !ss.eof())
            return NONE;
        return INT;
    case FLOAT_REGULAR:
        ss << literal.substr(0, literal.length() - 1);
        float f;
        ss >> f;
        if (ss.fail() || !ss.eof())
            return NONE;
        return FLOAT_REGULAR;
    case DOUBLE_REGULAR:
        ss << literal;
        double d;
        ss >> d;
        if (ss.fail() || !ss.eof())
            return NONE;
        return DOUBLE_REGULAR;
    }
    return NONE;
}

void print_char(char c)
{
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void print_literal(char c)
{
    print_char(c);
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void print_literal(int i)
{
    std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << "float: " << static_cast<float>(i) << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void print_literal(float f)
{
    if (std::isnan(f) || std::isinf(f))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        print_char(static_cast<char>(f));
        std::cout << "int: " << static_cast<int>(f) << std::endl;   
    }
    std::cout << std::setprecision(9) << std::fixed;
    std::cout << "float: " << f << 'f' << std::endl;
    std::cout << "double: " << static_cast<float>(f) << std::endl;
}

void print_literal(double d)
{
    if (std::isnan(d) || std::isinf(d))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        print_char(static_cast<char>(d));
        std::cout << "int: " << static_cast<int>(d) << std::endl;   
    }
    std::cout << std::setprecision(9) << std::fixed;
    std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
    std::cout << "double: " << d << std::endl;
}

int print_literal(const std::string& str)
{
    e_literal_type type = get_type(str);
    std::stringstream ss;
    
    switch (type)
    {
    case FLOAT_NAN:
        print_literal(std::numeric_limits<float>::quiet_NaN());
        return 0;
    case FLOAT_NEG_INF:
        print_literal(-std::numeric_limits<float>::infinity());
        return 0;
    case FLOAT_INF:
        print_literal(std::numeric_limits<float>::infinity());
        return 0;
    case DOUBLE_NAN:
        print_literal(std::numeric_limits<double>::quiet_NaN());
        return 0;
    case DOUBLE_NEG_INF:
        print_literal(-std::numeric_limits<double>::infinity());
        return 0;
    case DOUBLE_INF:
        print_literal(std::numeric_limits<double>::infinity());
        return 0;
    case CHAR:
        char c;
        ss << str;
        ss >> c;
        print_literal(c);
        return 0;
    case INT:
        int i;
        ss << str;
        ss >> i;
        print_literal(i);
        return 0;
    case FLOAT_REGULAR:
        float f;
        ss << str.substr(0, str.length() - 1);
        ss >> f;
        print_literal(f);
        return 0;
    case DOUBLE_REGULAR:
        double d;
        ss << str;
        ss >> d;
        print_literal(d);
        return 0;
    case NONE:
    default:
        std::cerr << "Error: Invalid literal" << std::endl;
    }
    return 1;
}

/*
** Write a program that takes a string representation of a C++ literal value
** (in its most common form) as a parameter. This literal must belong to one of
** the following a scalar types: char, int, float or double. Only the decimal
** notation will be used.
*/
int main(int argc, char **argv)
{   
    if (argc != 2)
    {
        std::cout << "Usage: ./main <char|int|float|double>" << std::endl;
        return (1);
    }
    int status = print_literal(static_cast<std::string>(argv[1]));
    return (status);
}
