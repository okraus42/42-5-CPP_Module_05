/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/19 15:57:56 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "colours.hpp"

Form::Form(void) : _name("Form"), _signGrade(150), _execGrade(150)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the Form class called.";
	ft_uncolorize();
	std::cout << std::endl;

	this->_signed = false;
}

Form::Form(const std::string name, unsigned int signGrade, unsigned int execGrade)
	:  _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the Form class called.";
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

Form::Form(const Form& copy): _name(copy.getName()),
	_signed(copy.getSigned()), _signGrade(copy.getSignGrade()),
	_execGrade(copy.getExecGrade())
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy constructor of the Form class called.";
	ft_uncolorize();
	std::cout << std::endl;

	*this = copy;
}

Form	&Form::operator = (const Form &src)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy assignment of the Form class called.";
	ft_uncolorize();
	std::cout << std::endl;

	this->_signed = src._signed;
	return (*this);
}

Form::~Form(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Destructor of the Form class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

// Getters
std::string	Form::getName(void) const
{
	// ft_colorize(reinterpret_cast<uintptr_t>(this));
	// std::cout << " [[getting name]] ";
	// ft_uncolorize();
	// std::cout << std::endl;
	return (this->_name);
}

unsigned int	Form::getSignGrade(void) const
{
	// ft_colorize(reinterpret_cast<uintptr_t>(this));
	// std::cout << " [[getting signgrade]] ";
	// ft_uncolorize();
	// std::cout << std::endl;
	return (this->_signGrade);
}

unsigned int	Form::getExecGrade(void) const
{
	// ft_colorize(reinterpret_cast<uintptr_t>(this));
	// std::cout << " [[getting execgrade]] ";
	// ft_uncolorize();
	// std::cout << std::endl;
	return (this->_execGrade);
}

bool	Form::getSigned(void) const
{
	// ft_colorize(reinterpret_cast<uintptr_t>(this));
	// std::cout << " [[getting signed]] ";
	// ft_uncolorize();
	// std::cout << std::endl;
	return (this->_signed);
}

// Other member functions

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw(GradeTooLowException());
}


const char* Form::GradeTooLowException::what() const throw()
{
	return (ERROR_COLOUR "Grade is too low." NO_COLOUR);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return (ERROR_COLOUR "Grade is too high." NO_COLOUR);
}

std::ostream& operator<<(std::ostream &o, const Form &Form)
{
	o << ft_str_colorize(reinterpret_cast<uintptr_t>(&Form))
		<< "Form [" << Form.getName()
		//<< "] with sign [" << Form.getSigned()
		<< "] with sign [" << (Form.getSigned() ? "signed" : "not signed")
		<< "] with Sign Grade [" << Form.getSignGrade()
		<< "] with Exec Grade [" << Form.getExecGrade()
		<< "]" << "\033[0m";
	return (o);
}
