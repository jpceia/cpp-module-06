/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 02:01:01 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/19 02:58:16 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <cctype>

enum e_literal_type
{
    NONE,
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};

bool is_number(const std::string& str)
{
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it))
        ++it;
    return !str.empty() && it == str.end();
}

e_literal_type get_type(const std::string& literal)
{
    // handling special cases
    if (literal == "-inf" || literal == "inf" || literal == "nan")
        return DOUBLE;
    if (literal == "-inff" || literal == "inff" || literal == "nanf")
        return FLOAT;
    if (literal.length() == 0)
        return NONE;
    if (literal.length() < 2) // Can be either a char or an int
    {
        if (std::string("0123456789").find(literal) != std::string::npos)
            return INT;
        return CHAR;
    }
    // else
    // Can be either int, float or double
    size_t point_pos = literal.find('.');
    size_t start_pos = 0;
    // check if has a signal
    if (literal[0] == '-' || literal[0] == '+')
        start_pos = 1;
    if (literal.find('f') != std::string::npos)
    {
        if (point_pos != std::string::npos)
        {
            if (!is_number(literal.substr(start_pos, point_pos)))
                return NONE;
            if (!is_number(literal.substr(point_pos + 1, literal.length() - 1)))
                return NONE;
            return FLOAT;
        }
        else
        {
            if (!is_number(literal.substr(start_pos, literal.length() - 1)))
                return NONE;
            return FLOAT;
        }
        return FLOAT;
    }
    if (point_pos != std::string::npos)
    {
        if (!is_number(literal.substr(start_pos, point_pos)))
            return NONE;
        if (!is_number(literal.substr(point_pos + 1, literal.length())))
            return NONE;
        return DOUBLE;
    }
    if (!is_number(literal.substr(start_pos, literal.length())))
        return NONE;
    return INT;
}

void display_char(char c)
{
    if (std::isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void display(char c)
{
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void display(int i)
{
    display_char(static_cast<char>(i));
    std::cout << "int: " << i << std::endl;
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << "float: " << static_cast<float>(i) << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void display(float f)
{
    if (std::isnan(f) || std::isinf(f))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        display_char(static_cast<char>(f));
        std::cout << "int: " << static_cast<int>(f) << std::endl;   
    }
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << "float: " << f << 'f' << std::endl;
    std::cout << "double: " << static_cast<float>(f) << std::endl;
}

void display(double d)
{
    if (std::isnan(d) || std::isinf(d))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        display_char(static_cast<char>(d));
        std::cout << "int: " << static_cast<int>(d) << std::endl;   
    }
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
    std::cout << "double: " << d << std::endl;
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

    std::stringstream literal(argv[1]);
    e_literal_type type = get_type(literal.str());
    switch (type)
    {
    case CHAR:
        char c;
        literal >> c;
        display(c);
        break;
    case INT:
        int i;
        literal >> i;
        display(i);
        break;
    case FLOAT:
        float f;
        literal >> f;
        display(f);
        break;
    case DOUBLE:
        double d;
        literal >> d;
        display(d);
        break;
    default:
        std::cout << "Invalid literal" << std::endl;
        break;
    }
}
