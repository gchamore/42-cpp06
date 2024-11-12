/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:53:13 by gchamore          #+#    #+#             */
/*   Updated: 2024/11/11 11:15:40 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define LIGHT_BLUE "\033[38;5;153m"
#define WHITE "\033[1;37m"

int main(void)
{
	Intern bob;
	AForm *form;
	Bureaucrat karen("Karen", 1);

	try
	{
		form = bob.makeForm("robotomy request", "Alice");
		delete form;
		form = bob.makeForm("shrubbery creation", "Charlie");
		delete form;
		form = bob.makeForm("presidential pardon", "David");
		delete form;
		form = bob.makeForm("random request", "Elisa");
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "------------------------------------" << std::endl;
		form = bob.makeForm("shrubbery creation", "Fred");
		karen.signForm(*form);
		karen.executeForm(*form);
		delete form;
		std::cout << "------------------------------------" << std::endl;
		form = bob.makeForm("presidential pardon", "Georgia");
		karen.signForm(*form);
		karen.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	return (0);
}
