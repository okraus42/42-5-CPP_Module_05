/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/19 18:20:37 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "colours.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("ShrubberyCreationForm", 145, 137), _target("Anonymous")
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the ShrubberyCreationForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Constructor of the ShrubberyCreationForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy):
	AForm("ShrubberyCreationForm", 145, 137), _target(copy._target)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy constructor of the ShrubberyCreationForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator = (const ShrubberyCreationForm &c)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Assignment operator of the ShrubberyCreationForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
	(void)c;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Destructor of the ShrubberyCreationForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
{

	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Execution of the ShrubberyCreationForm.";
	ft_uncolorize();
	std::cout << std::endl;
	(void)executor;
}

// const char* AForm::FormNotSignedException::what() const throw()
// {
// 	return (ERROR_COLOUR "Form is not signed." NO_COLOUR);
// }
