/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/21 13:27:48 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "colours.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("RobotomyRequestForm", 72, 45), _target("Anonymous")
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the RobotomyRequestForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Constructor of the RobotomyRequestForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy):
	AForm("RobotomyRequestForm", 72, 45), _target(copy._target)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy constructor of the RobotomyRequestForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator = (const RobotomyRequestForm &c)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Assignment operator of the RobotomyRequestForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
	(void)c;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Destructor of the RobotomyRequestForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor)
{
	AForm::checkIfCanExecute(executor);
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "...making some drilling noises...";
	ft_uncolorize();
	std::cout << std::endl;
	srand(time(0));
	// std::cout << rand() << std::endl;
	if (rand() % 2)
	{
		ft_colorize(reinterpret_cast<uintptr_t>(this));
		std::cout << this->_target << " has been successfully robotomized.";
		ft_uncolorize();
		std::cout << std::endl;
	}
	else
	{
		ft_colorize(reinterpret_cast<uintptr_t>(this));
		std::cout << "Robotomy has failed. " << this->_target << " is unharmed.";
		ft_uncolorize();
		std::cout << std::endl;
	}
}

// const char* AForm::FormNotSignedException::what() const throw()
// {
// 	return (ERROR_COLOUR "Form is not signed." NO_COLOUR);
// }
