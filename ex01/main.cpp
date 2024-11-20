/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:53:13 by gchamore          #+#    #+#             */
/*   Updated: 2024/11/20 13:04:09 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

void printData(const Data* data, const std::string& label)
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
    Data secondData = { "Patoche", 42, NULL };
    Data firstData = { "Didier", 42, &secondData };

    // Print the original data structures
    std::cout << "=== Original Data Structures ===\n";
    printData(&firstData, "First Data");
    printData(&secondData, "Second Data");

    // Perform serialization and deserialization
	std::cout << "=== Serialization and unserialize Data Structures ===\n\n";
    Serializer serializer;
    uintptr_t raw_first = serializer.serialize(&firstData);
	std::cout << "\nSerialized Address: " << raw_first << "\n" << std::endl;
    Data* unserializeData = serializer.unserialize(raw_first);
	std::cout << "\nUnserialized Address: " << unserializeData << "\n" << std::endl;

    // Print the unserialize data structure
    std::cout << "\n=== Unserialize Data Structures ===\n\n";
    printData(unserializeData, "unserialize First Data");
    printData(unserializeData->next, "unserialize Second Data");

    return 0;
}
