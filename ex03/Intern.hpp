/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:59:59 by gchamore          #+#    #+#             */
/*   Updated: 2024/11/06 17:09:38 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"



class Intern
{
	public:
		Intern();
		Intern(const Intern &other);

		~Intern();

		Intern &operator=(const Intern &other);

		AForm	*makeForm(const std::string &type, const std::string &target);

};

#endif