/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:53:13 by gchamore          #+#    #+#             */
/*   Updated: 2024/11/04 14:35:39 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << std::endl << "-----------------Test Min + Decrement error----------------" << std::endl << std::endl;

    try
	{
        Bureaucrat Berni("Berni", 150);
        std::cout << Berni << std::endl;
		Berni.DecrementGrade();
		std::cout << Berni << std::endl;
    }
    catch (std::exception & e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

	std::cout << std::endl << "-----------------Test max + Increment error----------------" << std::endl << std::endl;

    try
	{
        Bureaucrat Gaston("Gaston", 1);
		std::cout << Gaston << std::endl;
        Gaston.IncrementGrade();
		std::cout << Gaston << std::endl;
	}
    catch (std::exception & e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

	std::cout << std::endl << "-----------------Test Min + Increment until Max error----------------" << std::endl << std::endl;
		
	try
	{
        Bureaucrat Didier("Didier", 150);
        std::cout << Didier << std::endl;
		while(1)
		{
			std::cout << Didier << std::endl;
			Didier.IncrementGrade();
		}
    }
    catch (std::exception & e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

	std::cout << std::endl << "-----------------Test construction error because of Min error----------------" << std::endl << std::endl;

	try
	{
        Bureaucrat Patoche("Patoche", 155);
        std::cout << Patoche << std::endl;
		Patoche.DecrementGrade();
		std::cout << Patoche << std::endl;
    }
    catch (std::exception & e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}