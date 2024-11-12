/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:40:48 by gchamore          #+#    #+#             */
/*   Updated: 2024/09/30 14:53:07 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _gradeToSign(1), _gradeToExecute(1) , _signed(false)
{
	// std::cout << "Default constructor called" << std::endl;
}

Form::Form(const std::string name, const unsigned int gradetosign, const unsigned int gradetoexecute) : _name(name), _gradeToSign(gradetosign), _gradeToExecute(gradetoexecute), _signed(false)
{
	// std::cout << "constructor named called" << std::endl;
	if (gradetosign < 1) throw GradeTooHighException();
	if (gradetoexecute < 1) throw GradeTooHighException();
	if (gradetoexecute > 150) throw GradeTooLowException();
    if (gradetosign > 150) throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _signed(other._signed)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Form::~Form()
{
	// std::cout << "Destructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	// std::cout << "Assignment operator called" << std::endl;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form Name: " << form.getName() << ", Signed: " << (form.getSigned() ? "Yes" : "No") << ", Grade Required:\nto be signed: " << form.getGradeToSign() << "\nand to be executed: " << form.getGradeToExecute() << std::endl;
    return os;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
    {
        throw GradeTooLowException();
    }
    this->_signed = true;
}

std::string Form::getName() const
{
	return _name;
}

unsigned int Form::getGradeToSign() const
{
	return _gradeToSign;
}

unsigned int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

bool Form::getSigned() const
{
	return _signed;
}

