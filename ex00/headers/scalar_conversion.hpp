/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_conversion.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 02:52:43 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/23 02:58:25 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include <iostream>

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
int print_literal(const std::string& str);

template <typename T, typename U>
bool in_range(const T& d, struct std::numeric_limits<U> limits)
{
    return (d >= static_cast<T>(limits.min()) && d <= static_cast<T>(limits.max()));
}
