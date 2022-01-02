/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_conversion.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 02:52:43 by jpceia            #+#    #+#             */
/*   Updated: 2022/01/02 09:36:30 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERSION_HPP
# define SCALAR_CONVERSION_HPP



# include <limits>
# include <iostream>

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

e_literal_type get_type(const std::string& literal);
int print_literal_from_string(const std::string& str);

template <typename T, typename U>
bool in_range(const T& x, struct std::numeric_limits<U> limits)
{
    return (x >= static_cast<T>(limits.min()) && x <= static_cast<T>(limits.max()));
}

#endif
