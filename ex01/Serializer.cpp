/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:52:59 by gchamore          #+#    #+#             */
/*   Updated: 2024/11/12 17:01:12 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	// std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Serializer::~Serializer()
{
	// std::cout << "Destructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	if (this != &other)
	{
	}
	// std::cout << "Assignment operator called" << std::endl;
	return *this;
}
