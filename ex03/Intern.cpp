/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:59:56 by gchamore          #+#    #+#             */
/*   Updated: 2024/11/11 11:14:15 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	// std::cout << "Default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = other;
	// std::cout << "Copy constructor called" << std::endl;
}

Intern::~Intern()
{
	// std::cout << "Destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern Assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	return *this;
}


AForm	*Intern::makeForm(const std::string &type, const std::string &target)
{
	AForm	*form;

	form = AForm::makeForm(type, target);
	if (!form)
		throw (AForm::InvalidFormException());
	else
		std::cout << "Intern creates form: " << form->getName() << " with target: " << target << std::endl;
	return (form);
}