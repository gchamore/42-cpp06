/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:53:05 by gchamore          #+#    #+#             */
/*   Updated: 2024/11/20 15:30:35 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct Data
{
	std::string name;
	size_t age;
	Data *next;
} Data;

class Serializer
{
public:
	Serializer(const Serializer &src);
	~Serializer();
	Serializer &operator=(const Serializer &src);

	static uintptr_t serialize(Data *ptr);
	static Data *unserialize(uintptr_t raw);

private:
	Serializer();
};

#endif