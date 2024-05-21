/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/21 12:50:24 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "colours.hpp"

AForm::AForm(void) : _name("AForm"), _signGrade(150), _execGrade(150)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the AForm class called.";
	ft_uncolorize();
	std::cout << std::endl;

	this->_signed = false;
}

AForm::AForm(const std::string name, unsigned int signGrade, unsigned int execGrade)
	:  _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the AForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
	if (!signGrade)
		throw(GradeTooHighException());
	if (signGrade > LOWGRADE)
		throw(GradeTooLowException());
	if (!execGrade)
		throw(GradeTooHighException());
	if (execGrade > LOWGRADE)
		throw(GradeTooLowException());
	this->_signed = false;
}

AForm::AForm(const AForm& copy): _name(copy.getName()),
	_signed(copy.getSigned()), _signGrade(copy.getSignGrade()),
	_execGrade(copy.getExecGrade())
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy constructor of the AForm class called.";
	ft_uncolorize();
	std::cout << std::endl;

	*this = copy;
}

AForm	&AForm::operator = (const AForm &src)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy assignment of the AForm class called.";
	ft_uncolorize();
	std::cout << std::endl;

	this->_signed = src._signed;
	return (*this);
}

AForm::~AForm(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Destructor of the AForm class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

// Getters
std::string	AForm::getName(void) const
{
	// ft_colorize(reinterpret_cast<uintptr_t>(this));
	// std::cout << " [[getting name]] ";
	// ft_uncolorize();
	// std::cout << std::endl;
	return (this->_name);
}

unsigned int	AForm::getSignGrade(void) const
{
	// ft_colorize(reinterpret_cast<uintptr_t>(this));
	// std::cout << " [[getting signgrade]] ";
	// ft_uncolorize();
	// std::cout << std::endl;
	return (this->_signGrade);
}

unsigned int	AForm::getExecGrade(void) const
{
	// ft_colorize(reinterpret_cast<uintptr_t>(this));
	// std::cout << " [[getting execgrade]] ";
	// ft_uncolorize();
	// std::cout << std::endl;
	return (this->_execGrade);
}

bool	AForm::getSigned(void) const
{
	// ft_colorize(reinterpret_cast<uintptr_t>(this));
	// std::cout << " [[getting signed]] ";
	// ft_uncolorize();
	// std::cout << std::endl;
	return (this->_signed);
}

// Other member functions

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw(GradeTooLowException());
}

void	AForm::checkIfCanExecute(Bureaucrat const &executor) const
{
	if (this->_signed == false)
		throw(FormNotSignedException());
	else if (this->getExecGrade() < executor.getGrade())
		throw(GradeTooLowException());
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return (ERROR_COLOUR "Grade is too low." NO_COLOUR);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return (ERROR_COLOUR "Grade is too high." NO_COLOUR);
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return (ERROR_COLOUR "Form is not signed." NO_COLOUR);
}

std::ostream& operator<<(std::ostream &o, const AForm &AForm)
{
	o << ft_str_colorize(reinterpret_cast<uintptr_t>(&AForm))
		<< "AForm [" << AForm.getName()
		//<< "] with sign [" << AForm.getSigned()
		<< "] with sign [" << (AForm.getSigned() ? "signed" : "not signed")
		<< "] with Sign Grade [" << AForm.getSignGrade()
		<< "] with Exec Grade [" << AForm.getExecGrade()
		<< "]" << "\033[0m";
	return (o);
}
