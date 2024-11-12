/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:52:14 by gchamore          #+#    #+#             */
/*   Updated: 2024/11/06 15:48:55 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>
#include <string>

class Bureaucrat;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class AForm
{
public:
	AForm();
	AForm(const std::string &name, unsigned int const gradetosign, unsigned int const gradetoexecute);
	AForm(const AForm &other);
	virtual ~AForm();

	AForm &operator=(const AForm &other);

	class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
		GradeTooLowException(const std::string &bureaucrat_name) throw();
		virtual ~GradeTooLowException() throw();
        virtual const char *what() const throw();
	private:
        std::string _message;
    };

    class FormNotSignedException : public std::exception
    {
    public:
        FormNotSignedException(const std::string &form_name) throw();
        virtual ~FormNotSignedException() throw();
        virtual const char *what() const throw();

    private:
        std::string _message;
    };
	std::string getName() const;
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExecute() const;
	bool getSigned() const;
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;


private:
	const std::string _name;
	const unsigned int _gradeToSign;
	const unsigned int _gradeToExecute;
	bool _signed;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif