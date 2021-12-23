/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 02:58:50 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/23 03:27:40 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h> // https://stackoverflow.com/questions/12228373/what-is-the-header-file-for-the-uintptr-t-type-in-modern-c
#include <iostream>

struct Data
{
    int x;
    float y;
    double z;
};

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

int main(void)
{
    Data data = {42, 3.14, 2.718};
    uintptr_t raw = serialize(&data);
    Data* ptr = deserialize(raw);
    std::cout << "x: " << ptr->x << std::endl;
    std::cout << "y: " << ptr->y << std::endl;
    std::cout << "z: " << ptr->z << std::endl;

    // Check if the return value is equal to the first pointer.
    std::cout << "&data : " << &data << std::endl;
    std::cout << "ptr   : " << ptr << std::endl;
    return (0);
}
