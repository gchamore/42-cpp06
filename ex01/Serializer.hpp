/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:53:05 by gchamore          #+#    #+#             */
/*   Updated: 2024/11/12 16:59:28 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

class Serializer
{
public:
	Serializer();
	Serializer(const Serializer &other);
	~Serializer();

	Serializer &operator=(const Serializer &other);

	

private:

};


#endif