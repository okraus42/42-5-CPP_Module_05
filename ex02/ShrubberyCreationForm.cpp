/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/21 13:58:14 by okraus           ###   ########.fr       */
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
	AForm::checkIfCanExecute(executor);
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << " Creating shrubbery in " << this->_target << "_shrubbery.";
	ft_uncolorize();
	std::cout << std::endl;
	 // Create and open a text file
	std::ofstream MyFile((this->_target + "_shrubbery").c_str());
	//check if file was opend succesfully
	if (!MyFile.is_open())
		throw(outfileException());
	// Write to the file
	MyFile << "Files can be tricky, but it is fun enough!\n";

	// Close the file
	MyFile.close();
	
}

const char* ShrubberyCreationForm::outfileException::what() const throw()
{
	return (ERROR_COLOUR "file could not be created." NO_COLOUR);
}
