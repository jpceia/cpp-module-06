/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_literal.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 02:52:34 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/23 02:57:02 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar_conversion.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>

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
    std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void print_literal(int i)
{
    if (in_range<int, char>(i, std::numeric_limits<char>()))
        print_char(static_cast<char>(i));
    else
        std::cout << "char: impossible" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void print_literal(float f)
{
    if (in_range<float, char>(f, std::numeric_limits<char>()))
        print_char(static_cast<char>(f));
    else
        std::cout << "char: impossible" << std::endl;
    if (in_range<float, int>(f, std::numeric_limits<int>()))
        std::cout << "int: " << static_cast<int>(f) << std::endl;  
    else
        std::cout << "int: impossible" << std::endl;
    
    std::cout << "float: " << f << 'f' << std::endl;
    std::cout << "double: " << static_cast<float>(f) << std::endl;
}

void print_literal(double d)
{
    if (in_range<double, char>(d, std::numeric_limits<char>()))
        print_char(static_cast<char>(d));
    else
        std::cout << "char: impossible" << std::endl;
    if (in_range<double, int>(d, std::numeric_limits<int>()))
        std::cout << "int: " << static_cast<int>(d) << std::endl;  
    else
        std::cout << "int: impossible" << std::endl;
    
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
