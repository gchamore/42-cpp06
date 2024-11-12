/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:52:14 by gchamore          #+#    #+#             */
/*   Updated: 2024/10/17 15:57:17 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
public:
	Form();
	Form(const std::string name, unsigned int const gradetosign, unsigned int const gradetoexecute);
	Form(const Form &other);
	~Form();

	Form &operator=(const Form &other);

	class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

	std::string getName() const;
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExecute() const;
	bool getSigned() const;
	void beSigned(Bureaucrat &bureaucrat);


private:
	std::string const _name;
	unsigned int const _gradeToSign;
	unsigned int const _gradeToExecute;
	bool _signed;
};

std::ostream& operator<<(std::ostream& os, const Form& Form);

#endif