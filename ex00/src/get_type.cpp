/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 02:53:00 by jpceia            #+#    #+#             */
/*   Updated: 2022/01/03 13:32:39 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar_conversion.hpp"
#include <string>
#include <sstream>


e_literal_type get_type_wo_validation(const std::string& literal)
{
    // handling special cases
    if (literal == "nanf")
        return FLOAT_NAN;
    if (literal == "inff" || literal == "+inff")
        return FLOAT_INF;
    if (literal == "-inff")
        return FLOAT_NEG_INF;
    if (literal == "nan")
        return DOUBLE_NAN;
    if (literal == "inf" || literal == "+inf")
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
