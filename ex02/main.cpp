/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:53:13 by gchamore          #+#    #+#             */
/*   Updated: 2024/11/06 15:58:02 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define LIGHT_BLUE "\033[38;5;153m"
#define WHITE "\033[1;37m"


int main()
{
	// Création de bureaucrates sans aucun droit
	Bureaucrat Didier("Didier", 26);
	Bureaucrat Gonzague("Gonzague", 73);
	Bureaucrat Patoche("Patoche", 146);

	// Création de bureaucrates avec seulement droit de signature

	Bureaucrat Philou("Philou", 15);
	Bureaucrat Steph("Steph", 55);
	Bureaucrat Loulou("Loulou", 138);

	// Création de bureaucrates avec droit de signature et d'exécution

	Bureaucrat Pierro("Pierro", 5);
	Bureaucrat Bernardo("Bernardo", 26);
	Bureaucrat Tony("Tony", 73);

	// Création de formulaires

	PresidentialPardonForm P_Form1("President Donald Trump");
	RobotomyRequestForm R_Form2("RoboCop");
	ShrubberyCreationForm S_Form3("Backyard");

	std::cout << WHITE << "\n----------------- Résumé et affichage des statuts -----------------\n\n"
			  << RESET << std::flush;

	std::cout << Didier << std::flush;
	std::cout << Gonzague << std::flush;
	std::cout << Patoche << std::flush;
	std::cout << "n'ont aucun droit\n\n";

	std::cout << Philou << std::flush;
	std::cout << Steph << std::flush;
	std::cout << Loulou << std::flush;
	std::cout << "ont le droit de signer mais pas d'exécuter\n\n";

	std::cout << Pierro << std::flush;
	std::cout << Bernardo << std::flush;
	std::cout << Tony << std::flush;
	std::cout << "ont le droit de signer et d'exécuter\n\n";

	std::cout << P_Form1 << std::endl;
	std::cout << R_Form2 << std::endl;
	std::cout << S_Form3 << std::endl;

	//TESTS

	std::cout << RED << "\n----------------- Test Fail Scenarios -----------------\n\n"
			  << RESET;

	std::cout << "Statut de P_Form1: " << (P_Form1.getSigned() ? "signé" : "non signé") << std::endl;
	std::cout << "Statut de R_Form2: " << (R_Form2.getSigned() ? "signé" : "non signé") << std::endl;
	std::cout << "Statut de S_Form3: " << (S_Form3.getSigned() ? "signé" : "non signé") << std::endl;

	std::cout << YELLOW << "\n>>> Test de signature sans avoir le grade suffisant <<<\n\n"
			  << RESET;

	try
	{
		std::cout << LIGHT_BLUE << "\nTentative de signature de P_Form1 par Didier:\n\n"
				  << RESET;
		Didier.signForm(P_Form1);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n";
	try
	{
		std::cout << LIGHT_BLUE << "Tentative de signature de S_Form3 par Gonzague:\n\n"
				  << RESET;
		Gonzague.signForm(R_Form2);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n";
	try
	{
		std::cout << LIGHT_BLUE << "Tentative de signature de S_Form3 par Patoche:\n\n"
				  << RESET;
		Patoche.signForm(S_Form3);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n";

	std::cout << YELLOW << "\n>>> Test d'exécution sans signature <<<\n\n"
			  << RESET;

	try
	{
		std::cout << LIGHT_BLUE << "Tentative d'exécution de P_Form1 sans signature par Pierro:\n\n"
				  << RESET;
		Pierro.executeForm(P_Form1);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n";
	try
	{
		std::cout << LIGHT_BLUE << "Tentative d'exécution de R_Form2 sans signature par Bernardo:\n\n"
				  << RESET;
		Bernardo.executeForm(R_Form2);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n";
	try
	{
		std::cout << LIGHT_BLUE << "Tentative d'exécution de S_Form3 sans signature par Tony:\n\n"
				  << RESET;
		Tony.executeForm(S_Form3);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n";

	std::cout << "Statut de P_Form1: " << (P_Form1.getSigned() ? "signé" : "non signé") << std::endl;
	std::cout << "Statut de R_Form2: " << (R_Form2.getSigned() ? "signé" : "non signé") << std::endl;
	std::cout << "Statut de S_Form3: " << (S_Form3.getSigned() ? "signé" : "non signé") << std::endl;

	std::cout << YELLOW << "\n>>> Test d'exécution signée mais sans droit d'exécution <<<\n\n"
			  << RESET;

	try
	{
		std::cout << LIGHT_BLUE << "Tentative de signature puis d'exécution de P_Form1 par Philou:\n\n"
				  << RESET;
		Philou.signForm(P_Form1);
		Philou.executeForm(P_Form1);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n";
	try
	{
		std::cout << LIGHT_BLUE << "Tentative de signature puis d'exécution de R_Form2 par Steph:\n\n"
				  << RESET;
		Steph.signForm(R_Form2);
		Steph.executeForm(R_Form2);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n";
	try
	{
		std::cout << LIGHT_BLUE << "Tentative de signature puis d'exécution de S_Form3 par Loulou:\n\n"
				  << RESET;
		Loulou.signForm(S_Form3);
		Loulou.executeForm(S_Form3);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n";

	std::cout << "Statut de P_Form1: " << (P_Form1.getSigned() ? "signé" : "non signé") << std::endl;
	std::cout << "Statut de R_Form2: " << (R_Form2.getSigned() ? "signé" : "non signé") << std::endl;
	std::cout << "Statut de S_Form3: " << (S_Form3.getSigned() ? "signé" : "non signé") << std::endl;

	std::cout << GREEN << "\n----------------- Test Success Scenarios -----------------\n\n"
			  << RESET;

	try
	{
		std::cout << LIGHT_BLUE << "Pierro signe P_Form1 et l'exécute:\n\n"
				  << RESET;
		Pierro.signForm(P_Form1);
		Pierro.executeForm(P_Form1);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n";
	try
	{
		std::cout << LIGHT_BLUE << "Philou signe R_Form2, Bernardo l'exécute:\n\n"
				  << RESET;
		Bernardo.signForm(R_Form2);
		Bernardo.executeForm(R_Form2);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n";
	try
	{
		std::cout << LIGHT_BLUE << "Tony signe S_Form3 et l'exécute:\n\n"
				  << RESET;
		Tony.signForm(S_Form3);
		Tony.executeForm(S_Form3);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n\n";
	return 0;
}
