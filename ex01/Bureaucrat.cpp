/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/19 16:03:10 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colours.hpp"

Bureaucrat::Bureaucrat(void) : _name("Bureaucrat")
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the Bureaucrat class called.";
	ft_uncolorize();
	std::cout << std::endl;

	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the Bureaucrat class called.";
	ft_uncolorize();
	std::cout << std::endl;
	if (!grade)
		throw(GradeTooHighException());
	if (grade > LOWGRADE)
		throw(GradeTooLowException());
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy.getName())
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy constructor of the Bureaucrat class called.";
	ft_uncolorize();
	std::cout << std::endl;

	*this = copy;
}

Bureaucrat	&Bureaucrat::operator = (const Bureaucrat &src)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy assignment of the Bureaucrat class called.";
	ft_uncolorize();
	std::cout << std::endl;

	this->_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Destructor of the Bureaucrat class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

// Getters
std::string	Bureaucrat::getName(void) const
{
	// ft_colorize(reinterpret_cast<uintptr_t>(this));
	// std::cout << " [[getting name]] ";
	// ft_uncolorize();
	// std::cout << std::endl;
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	// ft_colorize(reinterpret_cast<uintptr_t>(this));
	// std::cout << " [[getting grade]] ";
	// ft_uncolorize();
	// std::cout << std::endl;
	return (this->_grade);
}

// Other member functions

void	Bureaucrat::signForm(Form &form)
{
	if (form.getSigned())
	{
		ft_colorize(reinterpret_cast<uintptr_t>(this));
		std::cout << "Bureaucrat [" << this->_name << "] couldn't sign ";
		ft_uncolorize();
		ft_colorize(reinterpret_cast<uintptr_t>(&form));
		std::cout << "form [" << form.getName() << "]";
		ft_uncolorize();
		ft_colorize(reinterpret_cast<uintptr_t>(this));
		std::cout << ", becuase it has already been signed.";
		ft_uncolorize();
		std::cout << std::endl;
		return ;
	}
	try
	{
		form.beSigned(*this);
		ft_colorize(reinterpret_cast<uintptr_t>(this));
		std::cout << "Bureaucrat [" << this->_name << "] signed ";
		ft_uncolorize();
		ft_colorize(reinterpret_cast<uintptr_t>(&form));
		std::cout << "form [" << form.getName() << "]";
		ft_uncolorize();
		ft_colorize(reinterpret_cast<uintptr_t>(this));
		std::cout << ".";
		ft_uncolorize();
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		ft_colorize(reinterpret_cast<uintptr_t>(this));
		std::cout << "Bureaucrat [" << this->_name << "] couldn't sign ";
		ft_uncolorize();
		ft_colorize(reinterpret_cast<uintptr_t>(&form));
		std::cout << "form [" << form.getName() << "]";
		ft_uncolorize();
		ft_colorize(reinterpret_cast<uintptr_t>(this));
		std::cout << ", becuase ";
		ft_uncolorize();
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::increment(void)
{
	// ft_colorize(reinterpret_cast<uintptr_t>(this));
	// std::cout << " [[incrementing grade]] ";
	// ft_uncolorize();
	// std::cout << std::endl;
	if (this->_grade == HIGHGRADE)
		throw(GradeTooHighException());
	this->_grade -= 1;
}

void	Bureaucrat::decrement(void)
{
	// ft_colorize(reinterpret_cast<uintptr_t>(this));
	// std::cout << " [[decrementing grade]] ";
	// ft_uncolorize();
	// std::cout << std::endl;
	if (this->_grade == LOWGRADE)
		throw(GradeTooLowException());
	this->_grade += 1;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (ERROR_COLOUR "Grade is too low." NO_COLOUR);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (ERROR_COLOUR "Grade is too high." NO_COLOUR);
}

std::ostream& operator<<(std::ostream &o, const Bureaucrat &bureaucrat)
{
	o << ft_str_colorize(reinterpret_cast<uintptr_t>(&bureaucrat))
		<< "Bureaucrat [" << bureaucrat.getName()
		<< "] with grade [" << bureaucrat.getGrade()
		<< "]" << "\033[0m";
	return (o);
}
