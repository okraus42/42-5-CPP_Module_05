/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/21 12:56:39 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "colours.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("PresidentialPardonForm", 25, 5), _target("Anonymous")
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the PresidentialPardonForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Constructor of the PresidentialPardonForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy):
	AForm("PresidentialPardonForm", 25, 5), _target(copy._target)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy constructor of the PresidentialPardonForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator = (const PresidentialPardonForm &c)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Assignment operator of the PresidentialPardonForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
	(void)c;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Destructor of the PresidentialPardonForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	AForm::checkIfCanExecute(executor);
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.";
	ft_uncolorize();
	std::cout << std::endl;
}

// const char* AForm::FormNotSignedException::what() const throw()
// {
// 	return (ERROR_COLOUR "Form is not signed." NO_COLOUR);
// }
