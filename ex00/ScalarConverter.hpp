/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:53:05 by gchamore          #+#    #+#             */
/*   Updated: 2024/11/06 13:19:17 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <cstdlib>
#include <float.h>

class ScalarConverter
{
public:
	ScalarConverter(const ScalarConverter &other);
	virtual ~ScalarConverter();

	ScalarConverter &operator=(const ScalarConverter &other);

	static void convert(const std::string &str);

private:
	ScalarConverter();
	
};

#endif