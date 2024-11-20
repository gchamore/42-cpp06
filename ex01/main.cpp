/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:53:13 by gchamore          #+#    #+#             */
/*   Updated: 2024/11/20 15:30:47 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

void printData(const Data *data, const std::string &label)
{
	std::cout << label << ":\n";
	std::cout << "\tAddress: " << data << "\n";
	std::cout << "\tName: " << data->name << "\n";
	std::cout << "\tAge: " << data->age << "\n";
	std::cout << "\tNext Address: " << data->next << "\n\n";
}

int main()
{
	// Initialize the data structures
	Data secondData = {"Patoche", 42, NULL};
	Data firstData = {"Didier", 42, &secondData};

	// Print the original data structures
	std::cout << "=== Original Data Structures ===\n";
	printData(&firstData, "First Data");
	printData(&secondData, "Second Data");

	// Perform serialization and deserialization
	std::cout << "=== Serialization and unserialize Data Structures ===\n\n";

	uintptr_t raw_first = Serializer::serialize(&firstData);
	std::cout << "\nSerialized Address (First Data): " << raw_first << "\n"
			  << std::endl;

	uintptr_t raw_second = Serializer::serialize(&secondData);
	std::cout << "\nSerialized Address (Second Data): " << raw_second << "\n"
			  << std::endl;

	Data *unserializedFirst = Serializer::unserialize(raw_first);
	std::cout << "\nUnserialized Address (First Data): " << unserializedFirst << "\n"
			  << std::endl;
	Data *unserializedSecond = Serializer::unserialize(raw_second);
	std::cout << "\nUnserialized Address (Second Data): " << unserializedSecond << "\n"
			  << std::endl;

	// Print the unserialized data structure
	std::cout << "\n=== Unserialized Data Structures ===\n\n";
	printData(unserializedFirst, "Unserialized First Data");
	printData(unserializedFirst->next, "Unserialized Second Data");

	return 0;
}
