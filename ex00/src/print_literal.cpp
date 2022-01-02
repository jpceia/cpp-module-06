/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_literal.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 02:52:34 by jpceia            #+#    #+#             */
/*   Updated: 2022/01/02 09:49:10 by jpceia           ###   ########.fr       */
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

void print_int(int i)
{
    std::cout << "int: " << i << std::endl;
}

void print_float(float f)
{
    std::stringstream ss;
    
    ss << std::fixed;
    ss << f;
    
    std::string s = ss.str();
    // adds .0 if the number is an integer
    if (s.find('.') == std::string::npos)
        s += ".0";
    else
    {
        // removes trailing zeros except for the last one
        size_t pos = s.find_last_not_of('0');
        if (pos != std::string::npos)
        {
            if (s[pos] == '.')
                pos++;
            s = s.substr(0, pos + 1);
        }
    }
    std::cout << "float: " << s << 'f' << std::endl;
}

void print_double(double d)
{
    std::stringstream ss;
    
    ss << std::fixed;
    ss << d;

    std::string s = ss.str();
    // adds .0 if the number is an integer
    if (s.find('.') == std::string::npos)
        s += ".0";
    else
    {
        // removes trailing zeros except for the last one
        size_t pos = s.find_last_not_of('0');
        if (pos != std::string::npos)
        {
            if (s[pos] == '.')
                pos++;
            s = s.substr(0, pos + 1);
        }
    }
    std::cout << "double: " << s << std::endl;
}

void print_literals(char c)
{
    print_char(c);
    print_int(static_cast<int>(c));
    print_float(static_cast<float>(c));
    print_double(static_cast<double>(c));
}

void print_literals(int i)
{
    if (in_range(i, std::numeric_limits<char>()))
        print_char(static_cast<char>(i));
    else
        std::cout << "char: impossible" << std::endl;
    print_int(i);
    print_float(static_cast<float>(i));
    print_double(static_cast<double>(i));
}

void print_literals(float f)
{
    if (in_range(f, std::numeric_limits<char>()))
        print_char(static_cast<char>(f));
    else
        std::cout << "char: impossible" << std::endl;
    if (in_range(f, std::numeric_limits<int>()))
        print_int(static_cast<int>(f));
    else
        std::cout << "int: impossible" << std::endl;
    print_float(f);
    print_double(static_cast<double>(f));
}

void print_literals(double d)
{
    if (in_range(d, std::numeric_limits<char>()))
        print_char(static_cast<char>(d));
    else
        std::cout << "char: impossible" << std::endl;
    if (in_range(d, std::numeric_limits<int>()))
        print_int(static_cast<int>(d));
    else
        std::cout << "int: impossible" << std::endl;
    if (in_range(d, std::numeric_limits<float>()))
        print_float(static_cast<float>(d));
    else
        std::cout << "float: impossible" << std::endl;
    print_double(d);
}


int print_literal_from_string(const std::string& str)
{
    e_literal_type type = get_type(str);
    std::stringstream ss;
    
    switch (type)
    {
    case FLOAT_NAN:
    case DOUBLE_NAN:
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return 0;
    case FLOAT_NEG_INF:
    case DOUBLE_NEG_INF:
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return 0;
    case FLOAT_INF:
    case DOUBLE_INF:
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return 0;
    case CHAR:
        char c;
        ss << str;
        ss >> c;
        print_literals(c);
        return 0;
    case INT:
        int i;
        ss << str;
        ss >> i;
        print_literals(i);
        return 0;
    case FLOAT_REGULAR:
        float f;
        ss << str.substr(0, str.length() - 1);
        ss >> f;
        print_literals(f);
        return 0;
    case DOUBLE_REGULAR:
        double d;
        ss << str;
        ss >> d;
        print_literals(d);
        return 0;
    case NONE:
    default:
        std::cerr << "Error: Invalid literal" << std::endl;
    }
    return 1;
}
