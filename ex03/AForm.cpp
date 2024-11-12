/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:40:48 by gchamore          #+#    #+#             */
/*   Updated: 2024/11/11 13:36:43 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm::AForm() : _name("default"), _gradeToSign(1), _gradeToExecute(1) , _signed(false)
{
	// std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, const unsigned int gradetosign, const unsigned int gradetoexecute) : _name(name), _gradeToSign(gradetosign), _gradeToExecute(gradetoexecute), _signed(false)
{
	// std::cout << "constructor named called" << std::endl;
	if (gradetosign < 1 && gradetoexecute < 1) throw GradeTooHighException();
	if (gradetoexecute > 150 && gradetosign > 150) throw GradeTooLowException(NULL);
}

AForm::AForm(const AForm &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _signed(other._signed)
{
	// std::cout << "Copy constructor called" << std::endl;
}

AForm::~AForm()
{
	// std::cout << "Destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	// std::cout << "Assignment operator called" << std::endl;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
    os << "AForm Name: " << AForm.getName() << ", Signed: " << (AForm.getSigned() ? "Yes" : "No") << ", Grade Required:\nto be signed: " << AForm.getGradeToSign() << "\nand to be executed: " << AForm.getGradeToExecute() << std::endl;
    return os;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

AForm::GradeTooLowException::GradeTooLowException(const std::string &bureaucrat_name) throw()
    : _message(bureaucrat_name + " Grade is too low!")
{
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char *AForm::GradeTooLowException::what() const throw()
{
    return _message.c_str();
}

AForm::FormNotSignedException::FormNotSignedException(const std::string &form_name) throw()
    : _message(form_name + " is not signed!")
{
}

AForm::FormNotSignedException::~FormNotSignedException() throw() {}

const char *AForm::FormNotSignedException::what() const throw()
{
    return _message.c_str();
}

char const	*AForm::InvalidFormException::what(void) const throw()
{
	return ("Invalid Form Request");
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
    {
        throw GradeTooLowException(bureaucrat.getName());
    }
    this->_signed = true;
}

std::string AForm::getName() const
{
	return _name;
}

unsigned int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

unsigned int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

bool AForm::getSigned() const
{
	return _signed;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->_gradeToExecute)
	{
		throw GradeTooLowException(executor.getName());
	}
	if (!this->_signed)
	{
		throw FormNotSignedException(this->getName());
	}
}

AForm	*AForm::makeForm(const std::string &type, const std::string &target)
{
	AForm	*form;

	form = NULL;
	form = ShrubberyCreationForm::makeForm(form, type, target);
	form = RobotomyRequestForm::makeForm(form, type, target);
	form = PresidentialPardonForm::makeForm(form, type, target);
	return (form);
}