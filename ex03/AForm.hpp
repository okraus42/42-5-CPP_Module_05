/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/21 13:59:12 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

# define LOWGRADE 150
# define HIGHGRADE 1

class Bureaucrat;

class AForm
{
	private:
		const std::string		_name;
		bool					_signed;
		const unsigned int		_signGrade;
		const unsigned int		_execGrade;

	public:
		AForm(void);
		AForm(const AForm& copy);
		AForm &operator=(const AForm& c);
		virtual ~AForm(void);

		AForm(const std::string name, unsigned int signGrade, unsigned int execGrade);

		unsigned int	getSignGrade(void) const;
		unsigned int	getExecGrade(void) const;
		bool			getSigned(void) const;
		std::string		getName(void) const;

		void			beSigned(Bureaucrat &bureaucrat);
		void			checkIfCanExecute(Bureaucrat const &executor) const;
		virtual void	execute(Bureaucrat const &bureaucrat) = 0;
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char*		what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char*		what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char*		what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, const AForm &f);

#endif