/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 02:01:01 by jpceia            #+#    #+#             */
/*   Updated: 2022/01/02 09:35:17 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar_conversion.hpp"

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
    int status = print_literal_from_string(static_cast<std::string>(argv[1]));
    return (status);
}
