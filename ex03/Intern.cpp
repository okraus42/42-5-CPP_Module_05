/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/21 16:21:15 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "colours.hpp"

Intern::Intern(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the Intern class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

Intern::Intern(const Intern& copy)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy constructor of the Intern class called.";
	ft_uncolorize();
	std::cout << std::endl;
	
	*this = copy;
}

Intern	&Intern::operator = (const Intern &src)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy assignment of the Intern class called.";
	ft_uncolorize();
	std::cout << std::endl;
	
	(void)src;
	return (*this);
}

Intern::~Intern(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Destructor of the Intern class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

// Getters

// Other member functions

AForm*	Intern::createForm(std::string form, std::string target)
{
	static const std::string	formNames[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	int				i = -1;
	
	while (++i < 3 && form != formNames[i]);
	switch (i)
	{
		case 0:
			return (new PresidentialPardonForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new ShrubberyCreationForm(target));
		case 3:
			throw (FormNotRealException());
			break ;
	}
	return (NULL);
}

AForm*	Intern::makeForm(std::string form, std::string target)
{
	AForm *newForm;
	try
	{
		newForm = Intern::createForm(form, target);
		ft_colorize(reinterpret_cast<uintptr_t>(this));
		std::cout << "Intern made";
		ft_uncolorize();
		ft_colorize(reinterpret_cast<uintptr_t>(newForm));
		std::cout << "form [" << newForm->getName() << "]";
		ft_uncolorize();
		ft_colorize(reinterpret_cast<uintptr_t>(this));
		std::cout << ".";
		ft_uncolorize();
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		ft_colorize(reinterpret_cast<uintptr_t>(this));
		std::cout << "Intern could not create "
		<< "form [" << form << "]";
		std::cout << ", becuase ";
		ft_uncolorize();
		std::cerr << e.what() << std::endl;
		return (NULL);
	}
	return (newForm);
}

const char* Intern::FormNotRealException::what() const throw()
{
	return (ERROR_COLOUR "form does not exist." NO_COLOUR);
}

std::ostream& operator<<(std::ostream &o, const Intern &bureaucrat)
{
	o << ft_str_colorize(reinterpret_cast<uintptr_t>(&bureaucrat))
		<< "Intern does not have any name nor grade\033[0m";
	return (o);
}
