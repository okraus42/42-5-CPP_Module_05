/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:52:35 by okraus            #+#    #+#             */
/*   Updated: 2024/05/21 16:23:04 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "colours.hpp"

//https://www.geeksforgeeks.org/cpp-polymorphism/

int main(void)
{
	std::cout << std::endl << "Intern PPF" << std::endl;
	try
	{
		Intern	inter;
		AForm	*ppf;
		std::cout << inter << std::endl;
		ppf = inter.makeForm("PresidentialPardonForm", "Arthur Dent");
		std::cout << *ppf << std::endl;
		Bureaucrat bur1("bur1", 10);
		std::cout << bur1 << std::endl;
		bur1.signForm(*ppf);
		std::cout << *ppf << std::endl;
		Bureaucrat bur2("bur2", 5);
		std::cout << bur2 << std::endl;
		bur2.executeForm(*ppf);
		std::cout << *ppf << std::endl;
		
		delete ppf;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "Intern RBTM" << std::endl;
	try
	{
		Intern	inter;
		AForm	*rbtm;
		std::cout << inter << std::endl;
		rbtm = inter.makeForm("RobotomyRequestForm", "Bender");
		std::cout << *rbtm << std::endl;
		Bureaucrat bur1("bur1", 10);
		std::cout << bur1 << std::endl;
		bur1.signForm(*rbtm);
		std::cout << *rbtm << std::endl;
		Bureaucrat bur2("bur2", 5);
		std::cout << bur2 << std::endl;
		bur2.executeForm(*rbtm);
		std::cout << *rbtm << std::endl;
		
		delete rbtm;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Intern RBTM" << std::endl;
	try
	{
		Intern	inter;
		AForm	*rbtm;
		std::cout << inter << std::endl;
		rbtm = inter.makeForm("RobotomyRequestForm", "Bender");
		std::cout << *rbtm << std::endl;
		Bureaucrat bur1("bur1", 10);
		std::cout << bur1 << std::endl;
		bur1.signForm(*rbtm);
		std::cout << *rbtm << std::endl;
		Bureaucrat bur2("bur2", 5);
		std::cout << bur2 << std::endl;
		bur2.executeForm(*rbtm);
		std::cout << *rbtm << std::endl;
		
		delete rbtm;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Intern RBTM" << std::endl;
	try
	{
		Intern	inter;
		AForm	*rbtm;
		std::cout << inter << std::endl;
		rbtm = inter.makeForm("RobotomyRequestForm", "Bender");
		std::cout << *rbtm << std::endl;
		Bureaucrat bur1("bur1", 10);
		std::cout << bur1 << std::endl;
		bur1.signForm(*rbtm);
		std::cout << *rbtm << std::endl;
		Bureaucrat bur2("bur2", 5);
		std::cout << bur2 << std::endl;
		bur2.executeForm(*rbtm);
		std::cout << *rbtm << std::endl;
		
		delete rbtm;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "Intern Shrubbery" << std::endl;
	try
	{
		Intern	inter;
		AForm	*shrub;
		std::cout << inter << std::endl;
		shrub = inter.makeForm("ShrubberyCreationForm", "Domestic");
		std::cout << *shrub << std::endl;
		Bureaucrat bur1("bur1", 10);
		std::cout << bur1 << std::endl;
		bur1.signForm(*shrub);
		std::cout << *shrub << std::endl;
		Bureaucrat bur2("bur2", 5);
		std::cout << bur2 << std::endl;
		bur2.executeForm(*shrub);
		std::cout << *shrub << std::endl;
		
		delete shrub;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "Intern invalid" << std::endl;
	try
	{
		Intern	inter;
		AForm	*invalid;
		std::cout << inter << std::endl;
		invalid = inter.makeForm("InvalidForm", "Unknown");
		
		delete invalid;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}