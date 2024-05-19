/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/19 15:50:12 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

# define LOWGRADE 150
# define HIGHGRADE 1

class Bureaucrat;

class Form
{
	private:
		const std::string		_name;
		bool					_signed;
		const unsigned int		_signGrade;
		const unsigned int		_execGrade;

	public:
		Form(void);
		Form(const Form& copy);
		Form &operator=(const Form& c);
		~Form(void);

		Form(const std::string name, unsigned int signGrade, unsigned int execGrade);

		unsigned int	getSignGrade(void) const;
		unsigned int	getExecGrade(void) const;
		bool			getSigned(void) const;
		std::string		getName(void) const;

		void			beSigned(Bureaucrat &bureaucrat);

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
};

std::ostream	&operator<<(std::ostream &o, const Form &f);

#endif