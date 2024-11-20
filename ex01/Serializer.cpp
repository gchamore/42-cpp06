/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:52:59 by gchamore          #+#    #+#             */
/*   Updated: 2024/11/20 15:30:42 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

// Constructors
Serializer::Serializer()
{
	std::cout << "[Serializer] Default Constructor called\n";
}

Serializer::Serializer(const Serializer &src)
{
	std::cout << "[Serializer] Copy Constructor called\n";
	*this = src;
}

// Destructor
Serializer::~Serializer()
{
	std::cout << "[Serializer] Destructor called\n";
}

// Overloaded Operators
Serializer &Serializer::operator=(const Serializer &src)
{
	std::cout << "[Serializer] Assignment Operator called\n";
	if (this == &src)
	{
		return *this;
	}
	return *this;
}

// Public Methods
uintptr_t Serializer::serialize(Data *ptr)
{
	std::cout << "[Serializer] Serializing data at address: " << ptr << "\n";
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::unserialize(uintptr_t raw)
{
	std::cout << "[Serializer] Unserializing raw address: " << raw << "\n";
	return reinterpret_cast<Data *>(raw);
}
