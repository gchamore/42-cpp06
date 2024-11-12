/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:52:59 by gchamore          #+#    #+#             */
/*   Updated: 2024/11/06 13:19:46 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
	{
		// Do something
	}
	return *this;
}

int toInt(const std::string &str)
{
	char *end;
	long value = std::strtol(str.c_str(), &end, 10);

	if (*end != '\0')
	{
		throw std::invalid_argument("Conversion to int failed");
	}

	if (value < INT_MIN || value > INT_MAX)
	{
		throw std::out_of_range("Int value out of range");
	}

	return static_cast<int>(value);
}

float toFloat(const std::string &str)
{
	char *end;
	float value = std::strtof(str.c_str(), &end);

	if (*end != '\0')
	{
		throw std::invalid_argument("Conversion to float failed");
	}

	return value;
}

double toDouble(const std::string &str)
{
	char *end;
	double value = std::strtod(str.c_str(), &end);

	if (*end != '\0')
	{
		throw std::invalid_argument("Conversion to double failed");
	}

	return value;
}

#include <iomanip> // Include this for std::fixed and std::setprecision

void ScalarConverter::convert(const std::string &str)
{
	// 1. Vérifier les valeurs spéciales
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return;
	}
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}

	// 2. Conversion en `char` si un seul caractère non numérique
	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		char charValue = str[0];
		std::cout << "char: '" << charValue << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(charValue) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(charValue) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(charValue) << std::endl;
		return;
	}

	// 3. Essayer de convertir en `int`
	try
	{
		int intValue = toInt(str);
		std::cout << "char: ";
		if (intValue >= 0 && intValue <= 127 && std::isprint(static_cast<char>(intValue)))
			std::cout << "'" << static_cast<char>(intValue) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;

		std::cout << "int: " << intValue << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(intValue) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(intValue) << std::endl;
		return;
	}
	catch (...)
	{
	} // Ignorer les erreurs ici et passer à la conversion suivante

	// 4. Essayer de convertir en `float` avec suffixe 'f'
	try
	{
		if (str[str.length() - 1] == 'f')
		{
			float floatValue = toFloat(str);
			std::cout << "char: ";
			if (floatValue >= 0 && floatValue <= 127 && std::isprint(static_cast<char>(floatValue)))
				std::cout << "'" << static_cast<char>(floatValue) << "'" << std::endl;
			else
				std::cout << "Non displayable" << std::endl;
			std::cout << "int: ";
			if (floatValue >= static_cast<float>(INT_MIN) && floatValue <= static_cast<float>(INT_MAX))
				std::cout << static_cast<int>(floatValue) << std::endl;
			else
				std::cout << "impossible" << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << floatValue << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(floatValue) << std::endl;
			return;
		}
	}
	catch (...)
	{
	} // Ignorer les erreurs ici et passer à la conversion suivante

	// 5. Essayer de convertir en `double`
	try
	{
		std::string doubleStr = str;
		if (doubleStr[doubleStr.length() - 1] == 'f')
		{
			doubleStr = doubleStr.substr(0, doubleStr.length() - 1);
		}
		double doubleValue = toDouble(doubleStr);
		std::cout << "char: ";
		if (doubleValue >= 0 && doubleValue <= 127 && std::isprint(static_cast<char>(doubleValue)))
			std::cout << "'" << static_cast<char>(doubleValue) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: ";
		if (doubleValue >= INT_MIN && doubleValue <= INT_MAX)
			std::cout << static_cast<int>(doubleValue) << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: ";
		if (doubleValue >= -FLT_MAX && doubleValue <= FLT_MAX)
			std::cout << static_cast<float>(doubleValue) << "f" << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "double: " << doubleValue << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Conversion error: " << e.what() << std::endl;
	}
}