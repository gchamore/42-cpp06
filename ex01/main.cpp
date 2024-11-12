/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:53:13 by gchamore          #+#    #+#             */
/*   Updated: 2024/11/04 15:38:31 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
		std::cout << std::endl << "-----------------Test Fail----------------" << std::endl << std::endl;
		
        Bureaucrat Steph("Steph", 50);
        Form Form1("Form1", 45, 80);
		std::cout << Steph << std::endl;
		std::cout << Form1 << std::endl;

        Steph.signForm(Form1);

		std::cout << std::endl << "-----------------Test Print Form State----------------" << std::endl << std::endl;
        std::cout << Form1 << std::endl;
		
		std::cout << "-----------------Test Success----------------" << std::endl << std::endl;

        Bureaucrat Francis("Francis", 30);
		std::cout << Francis << std::endl;
		std::cout << Form1 << std::endl;
        Francis.signForm(Form1);

		std::cout << std::endl << "-----------------Test Print Form State----------------" << std::endl << std::endl;
        std::cout << Form1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception attrapée: " << e.what() << std::endl;
    }
	try
    {
		std::cout << "-----------------Test too high grade on gradetosign----------------" << std::endl << std::endl;
		Form Form2("Form2", 0, 100);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception attrapée: " << e.what() << std::endl;
    }

	try
    {
		std::cout << std::endl << "-----------------Test too high grade on gradetoexecute----------------" << std::endl << std::endl;
		Form Form2("Form2", 100, 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception attrapée: " << e.what() << std::endl;
    }

	try
    {
		std::cout << std::endl << "-----------------Test too low grade on gradetosign----------------" << std::endl << std::endl;
		Form Form4("Form4", 200, 100);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception attrapée: " << e.what() << std::endl;
    }

	try
    {
		std::cout << std::endl << "-----------------Test too low grade on gradetoexecute----------------" << std::endl << std::endl;
		Form Form3("Form3", 100, 200);
	}
    catch (const std::exception &e)
    {
        std::cerr << "Exception attrapée: " << e.what() << std::endl;
    }

	std::cout << std::endl << "-----------------Test Min + Decrement error----------------" << std::endl << std::endl;
    try
	{
        Bureaucrat bob("Berni", 150);
        std::cout << bob;
		bob.DecrementGrade();
		std::cout << bob;
    }
    catch (std::exception & e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

	std::cout << std::endl << "-----------------Test max + Increment error----------------" << std::endl << std::endl;

    try
	{
        Bureaucrat alice("Gaston", 1);
		std::cout << alice;
        alice.IncrementGrade();
		std::cout << alice;
	}
    catch (std::exception & e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

	// std::cout << std::endl << "-----------------Test Min + Increment until Max error----------------" << std::endl << std::endl;
		
	// try
	// {
    //     Bureaucrat bob("Didier", 150);
    //     std::cout << bob;
	// 	while(1)
	// 	{
	// 		std::cout << bob;
	// 		bob.IncrementGrade();
	// 	}
    // }
    // catch (std::exception & e)
	// {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

	std::cout << std::endl << "-----------------Test construction error because of Min error----------------" << std::endl << std::endl;

	try
	{
        Bureaucrat bob("Patoche", 155);
        std::cout << bob;
		bob.DecrementGrade();
		std::cout << bob;
    }
    catch (std::exception & e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}